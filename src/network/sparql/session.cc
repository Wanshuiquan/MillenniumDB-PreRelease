#include "session.h"

#include <memory>

#include "misc/logger.h"
#include "misc/trim.h"
#include "network/sparql/http_buffer.h"
#include "network/sparql/request_handler.h"
#include "network/sparql/server.h"
#include "query/optimizer/rdf_model/executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/sparql_query_parser.h"
#include "query/parser/sparql_update_parser.h"
#include "storage/buffer_manager.h"
#include "storage/tmp_manager.h"
#include "update/sparql/update_executor.h"

using namespace boost;
using namespace SPARQL;

using DurationMS = std::chrono::duration<float, std::milli>;

void Session::run() {
    asio::dispatch(
        stream.get_executor(),
        beast::bind_front_handler(&Session::do_read, shared_from_this())
    );
}


void Session::do_read() {
    // Make the request empty before reading, otherwise the operation behavior is undefined.
    req = {};

    // Set the timeout for getting the query
    stream.expires_after(connection_timeout);

    // Read a request
    beast::http::async_read(stream,
                            buffer,
                            req,
                            beast::bind_front_handler(&Session::on_read, shared_from_this()));
}


void Session::fail(boost::beast::error_code& ec, char const* what) {
    logger(Category::Error) << what << ": " << ec.message() << "\n";
}


void Session::on_read(beast::error_code ec, std::size_t /*bytes_transferred*/) {
    // This means they closed the connection
    if (ec == beast::http::error::end_of_stream) {
        stream.socket().shutdown(asio::ip::tcp::socket::shutdown_send, ec);
        return;
    }

    if (ec)
        return fail(ec, "read");

    HttpBuffer http_buffer(stream.socket());
    std::ostream os(&http_buffer);

    // without this line ConnectionException won't be caught properly
    os.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    bool is_update = false;
    if (req.target().rfind("/update", 0) != std::string::npos) {
        is_update = true;
    } else if (req.target().rfind("/sparql", 0) == std::string::npos) {
         os << "HTTP/1.1 404 Not Found\r\n"
            << "\r\n";
        return;
    }

    auto [query, response_type] = RequestHandler::parse_request(req);

    // after parsing the query we don't want to have a connection timeout
    stream.expires_never();

    logger(Category::Query) << "-------------------------------------\n" << trim_string(query) << "\n";

    tmp_manager.reset();
    get_query_ctx().reset();

    if (is_update) {
        execute_update(query, os);
    } else {
        execute_query(query, os, response_type);
    }
}



void Session::execute_query(
    const std::string& query,
    std::ostream& os,
    ResponseType response_type)
{
    std::unique_ptr<QueryExecutor> physical_plan;

    // declared here because the destruction need to be after calling execute_query_plan
    std::unique_ptr<BufferManager::VersionScope> version_scope;
    try {
        auto logical_plan = create_query_logical_plan(query);
        version_scope = buffer_manager.init_version_readonly();
        get_query_ctx().start_version = version_scope->start_version;
        get_query_ctx().result_version = version_scope->start_version;
        physical_plan = create_query_physical_plan(*logical_plan, response_type);
    }
    catch (const QueryParsingException& e) {
        logger(Category::Error) << "Query Parsing Exception. Line " << e.line << ", col: " << e.column << ": " << e.what();

        os << "HTTP/1.1 400 Bad Request\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
        return;
    }
    catch (const QueryException& e) {
        logger(Category::Error) << "Query Exception: " << e.what();

        os << "HTTP/1.1 400 Bad Request\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
    }
    catch (const LogicException& e) {
        logger(Category::Error)  << "Logic Exception: " << e.what();

        os << "HTTP/1.1 500 Internal Server Error\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
    }

    if (physical_plan == nullptr) {
        return;
    }

    try {
        execute_query_plan(*physical_plan, os, response_type);
    }
    catch (const ConnectionException& e) {
        logger(Category::Error) << "Connection Exception: " << e.what();
    }
    catch (const InterruptedException& e) {
        // Handled in execute_query_plan
    }
    catch (const QueryExecutionException& e) {
        // Handled in execute_query_plan
    }
}


void Session::execute_update(const std::string& query, std::ostream& os) {
    // mutex to allow only one write query at a time
    std::lock_guard<std::mutex> lock(update_mutex);

    DurationMS parser_duration;
    DurationMS execution_duration;

    std::unique_ptr<BufferManager::VersionScope> version_scope;
    std::unique_ptr<OpUpdate> logical_plan;
    try {
        logical_plan = create_update_logical_plan(query);
        version_scope = buffer_manager.init_version_editable();
        get_query_ctx().start_version = version_scope->start_version;
        get_query_ctx().result_version = version_scope->start_version + 1;
    }
    catch (const QueryParsingException& e) {
        logger(Category::Error) << "Query Parsing Error. Line " << e.line << ", col: " << e.column << ": " << e.what();

        os << "HTTP/1.1 400 Bad Request\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
        return;
    }
    catch (const QueryException& e) {
        logger(Category::Error) << "Query Exception: " << e.what();

        os << "HTTP/1.1 400 Bad Request\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
        return;
    }
    catch (const LogicException& e) {
        logger(Category::Error) << "Logic Exception: " << e.what();

        os << "HTTP/1.1 500 Internal Server Error\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
        return;
    }

    auto execution_start = std::chrono::system_clock::now();
    try {
        UpdateExecutor update_executor;
        for (auto& update : logical_plan->updates) {
            update->accept_visitor(update_executor);
        }
        execution_duration = std::chrono::system_clock::now() - execution_start;

        logger.log(Category::ExecutionStats, [&update_executor] (std::ostream& os) {
            os << "Update Stats";
            if (update_executor.triples_inserted != 0) {
                os << "\nTriples inserted: " << update_executor.triples_inserted;
            }
            if (update_executor.triples_deleted != 0) {
                os << "\nTriples deleted: " << update_executor.triples_deleted;
            }
            if (update_executor.triples_inserted == 0 && update_executor.triples_deleted == 0) {
                os << "\nNo modifications were performed";
            }
        });
    }
    catch (const ConnectionException& e) {
        logger(Category::Error) << "Connection Exception: " << e.what();
        return;
    }
    catch (const InterruptedException& e) {
        execution_duration = std::chrono::system_clock::now() - execution_start;
        logger(Category::Info) << "Timeout thrown after "
            << std::chrono::duration_cast<std::chrono::milliseconds>(parser_duration + execution_duration).count()
            << " ms";

        os << "HTTP/1.1 408 Request Timeout\r\n";
        return;
    }
    catch (const QueryExecutionException& e) {
        execution_duration = std::chrono::system_clock::now() - execution_start;
        logger(Category::Error) << "Query Execution Exception: " << e.what();

        os << "HTTP/1.1 500 Internal Server Error\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
        return;
    }

    os << "HTTP/1.1 204 No Content\r\n";
    logger(Category::Info) << "Parser duration:" << parser_duration.count() << "ms\n"
        << "Execution duration:" << execution_duration.count() << "ms";
}


std::unique_ptr<Op> Session::create_query_logical_plan(const std::string& query) {
    auto start_parser = std::chrono::system_clock::now();
    {
        std::lock_guard<std::mutex> lock(server.thread_info_vec_mutex);
        get_query_ctx().thread_info.interruption_requested = false; // used in query optimization
        get_query_ctx().thread_info.time_start = start_parser;
        get_query_ctx().thread_info.timeout = start_parser + timeout;
    }
    antlr4::MyErrorListener error_listener;
    auto logical_plan = SPARQL::QueryParser::get_query_plan(query, &error_listener);
    parser_duration = std::chrono::system_clock::now() - start_parser;
    return logical_plan;
}


std::unique_ptr<OpUpdate> Session::create_update_logical_plan(const std::string& query) {
    auto start_parser = std::chrono::system_clock::now();
    {
        std::lock_guard<std::mutex> lock(server.thread_info_vec_mutex);
        get_query_ctx().thread_info.interruption_requested = false;
        get_query_ctx().thread_info.time_start = start_parser;
        get_query_ctx().thread_info.timeout = start_parser + timeout;
    }
    antlr4::MyErrorListener error_listener;
    auto logical_plan = SPARQL::UpdateParser::get_query_plan(query, &error_listener);
    parser_duration = std::chrono::system_clock::now() - start_parser;
    return logical_plan;
}


void Session::execute_query_plan(
    QueryExecutor& physical_plan,
    std::ostream& os,
    ResponseType response_type)
{
    auto execution_start = std::chrono::system_clock::now();
    try {
        os << "HTTP/1.1 200 OK\r\n"
           << "Server: MillenniumDB\r\n";

        switch (response_type) {
            case SPARQL::ResponseType::CSV:
                os << "Content-Type: text/csv; charset=utf-8\r\n";
                break;
            case SPARQL::ResponseType::TSV:
                os << "Content-Type: text/tab-separated-values; charset=utf-8\r\n";
                break;
            case SPARQL::ResponseType::JSON:
                os << "Content-Type: application/json; charset=utf-8\r\n";
                break;
            case SPARQL::ResponseType::XML:
                os << "Content-Type: application/sparql-results+xml; charset=utf-8\r\n";
                break;
            case SPARQL::ResponseType::TURTLE:
                os << "Content-Type: application/turtle; charset=utf-8\r\n";
                break;
            default: throw NotSupportedException("RESPONSE TYPE: " + SPARQL::response_type_to_string(response_type));
        }
        os << "Access-Control-Allow-Origin: *\r\n"
           << "Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept, Authorization\r\n"
           << "Access-Control-Allow-Methods: GET, POST\r\n"
           << "\r\n";

        logger.log(Category::PhysicalPlan, [&physical_plan] (std::ostream& os) {
            physical_plan.analyze(os, false);
            os << '\n';
        });

        auto result_count = physical_plan.execute(os);
        execution_duration = std::chrono::system_clock::now() - execution_start;

        logger.log(Category::ExecutionStats, [&physical_plan] (std::ostream& os) {
            physical_plan.analyze(os, true);
            os << '\n';
        });

        logger(Category::Info)
            << "Results: " << result_count << '\n'
            << "Parser duration:    " << parser_duration.count()    << " ms\n"
            << "Optimizer duration: " << optimizer_duration.count() << " ms\n"
            << "Execution duration: " << execution_duration.count() << " ms";
    }
    catch (const InterruptedException& e) {
        execution_duration = std::chrono::system_clock::now() - execution_start;
        logger(Category::Info) << "Timeout thrown after "
            << std::chrono::duration_cast<std::chrono::milliseconds>(execution_duration).count()
            << " ms";
        throw e;
    }
    catch (const QueryExecutionException& e) {
        execution_duration = std::chrono::system_clock::now() - execution_start;
        logger(Category::Error) << "\nQuery Execution Exception: " << e.what();
        throw e;
    }
}


std::unique_ptr<QueryExecutor> Session::create_query_physical_plan(
    Op& logical_plan,
    ResponseType response_type)
{
    auto start_optimizer = std::chrono::system_clock::now();

    SPARQL::ExecutorConstructor executor_constructor(response_type);
    logical_plan.accept_visitor(executor_constructor);

    optimizer_duration = std::chrono::system_clock::now() - start_optimizer;
    return std::move(executor_constructor.executor);
}
