#include "http_quad_session.h"

#include <antlr4-runtime.h>

#include "misc/logger.h"
#include "network/mql/request_handler.h"
#include "network/server/protocol.h"
#include "network/server/server.h"
#include "network/server/session/http/response/http_response_buffer.h"
#include "query/executor/query_executor/query_executor.h"
#include "query/optimizer/quad_model/executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/mql_query_parser.h"
#include "query/query_context.h"
#include "storage/tmp_manager.h"
#include "misc/logger.h"

using namespace boost;
using namespace MDBServer;
namespace beast = boost::beast;
namespace http  = beast::http;

HttpQuadSession::HttpQuadSession(Server<Protocol::QUAD_MODEL_ID>&   server,
                                 stream_type&&                      stream,
                                 http::request<http::string_body>&& request,
                                 std::chrono::seconds               query_timeout) :
    server        { server },
    stream        { std::move(stream) },
    request       { std::move(request) },
    query_timeout { query_timeout } { }


HttpQuadSession::~HttpQuadSession() {
    if (stream.socket().is_open()) {
        stream.close();
    }
}


void HttpQuadSession::run() {
    boost::asio::dispatch(stream.get_executor(),
                          beast::bind_front_handler(&HttpQuadSession::handle_request, this->shared_from_this()));
}


void HttpQuadSession::handle_request() {
    HttpResponseBuffer response_buffer { stream };

    std::ostream response_ostream { &response_buffer };

    // Without this line ConnectionException won't be caught properly
    response_ostream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    auto&& [query, return_type] = MQL::RequestHandler::parse_request(request);

    // After parsing the query we don't want to have a connection timeout
    stream.expires_never();

    tmp_manager.reset();
    get_query_ctx().reset();

    std::unique_ptr<QueryExecutor> current_physical_plan;
    try {
        auto current_logical_plan = create_logical_plan(query);
        if (current_logical_plan->read_only()) {
            current_physical_plan = create_readonly_physical_plan(*current_logical_plan, return_type);
            execute_readonly_query(*current_logical_plan, response_ostream, return_type);
        } else {
            // TODO: execute_update_query(*current_logical_plan, response_ostream);
            return;
        }
    }
    catch (const QueryException& e) {
        logger(Category::Error) << "Query Exception: " << e.what();

        response_ostream << "HTTP/1.1 400 Bad Request\r\n"
                         << "Content-Type: text/plain\r\n"
                         << "\r\n"
                         << std::string(e.what());
    }
    catch (const LogicException& e) {
        logger(Category::Error) << "Logic Exception: " << e.what();

        response_ostream << "HTTP/1.1 500 Internal Server Error\r\n"
                         << "Content-Type: text/plain\r\n"
                         << "\r\n"
                         << std::string(e.what());
    }
}


std::unique_ptr<Op> HttpQuadSession::create_logical_plan(const std::string& query) {
    const auto start_parser = std::chrono::system_clock::now();
    {
        std::lock_guard<std::mutex> lock(server.thread_info_vec_mutex);
        get_query_ctx().thread_info.interruption_requested = false; // used in query optimization
        get_query_ctx().thread_info.time_start             = start_parser;
        get_query_ctx().thread_info.timeout                = start_parser + query_timeout;
    }
    antlr4::MyErrorListener error_listener;

    auto logical_plan = MQL::QueryParser::get_query_plan(query, &error_listener);
    parser_duration   = std::chrono::system_clock::now() - start_parser;
    return logical_plan;
}


std::unique_ptr<QueryExecutor> HttpQuadSession::create_readonly_physical_plan(Op& logical_plan, MQL::ReturnType return_type) {
    const auto start_optimizer = std::chrono::system_clock::now();

    MQL::ExecutorConstructor executor_constructor(return_type);
    logical_plan.accept_visitor(executor_constructor);

    optimizer_duration = std::chrono::system_clock::now() - start_optimizer;
    return std::move(executor_constructor.executor);
}


void HttpQuadSession::execute_readonly_query(Op& logical_plan, std::ostream& os, MQL::ReturnType return_type) {
    std::unique_ptr<QueryExecutor> current_physical_plan;

    try {
        current_physical_plan = create_readonly_physical_plan(logical_plan, return_type);
    }
    catch (const QueryParsingException& e) {
        logger(Category::Error) << "Query Parsing Exception. Line " << e.line << ", col: " << e.column << ": "
                                << e.what();

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
        logger(Category::Error) << "Logic Exception: " << e.what();

        os << "HTTP/1.1 500 Internal Server Error\r\n"
           << "Content-Type: text/plain\r\n"
           << "\r\n"
           << std::string(e.what());
    }

    if (current_physical_plan == nullptr) {
        return;
    }

    try {
        execute_readonly_query_plan(*current_physical_plan, os, return_type);
    }
    catch (const ConnectionException& e) {
        logger(Category::Error) << "Connection Exception: " << e.what();
    }
    catch (const InterruptedException& e) {
        // Handled in execute_readonly_query_plan
    }
    catch (const QueryExecutionException& e) {
        // Handled in execute_readonly_query_plan
    }
}


void HttpQuadSession::execute_readonly_query_plan(QueryExecutor&  physical_plan,
                                                  std::ostream&   os,
                                                  MQL::ReturnType return_type) {
    const auto execution_start = std::chrono::system_clock::now();
    try {
        os << "HTTP/1.1 200 OK\r\n"
           << "Server: MillenniumDB\r\n";

        switch (return_type) {
        case MQL::ReturnType::CSV:
            os << "Content-Type: text/csv; charset=utf-8\r\n";
            break;
        case MQL::ReturnType::TSV:
            os << "Content-Type: text/tab-separated-values; charset=utf-8\r\n";
            break;
        default:
            throw LogicException("Response type not implemented: " + std::to_string(static_cast<int>(return_type)));
        }
        os << "Access-Control-Allow-Origin: *\r\n"
           << "Access-Control-Allow-Headers: Origin, X-Requested-With, Content-Type, Accept, Authorization\r\n"
           << "Access-Control-Allow-Methods: GET, POST\r\n"
           << "\r\n";

        logger.log(Category::PhysicalPlan, [&physical_plan](std::ostream& os) {
            physical_plan.analyze(os, false);
            os << '\n';
        });

        const auto result_count = physical_plan.execute(os);
        execution_duration      = std::chrono::system_clock::now() - execution_start;

        logger.log(Category::ExecutionStats, [&physical_plan](std::ostream& os) {
            physical_plan.analyze(os, true);
            os << '\n';
        });

        logger(Category::Info) << "Results: " << result_count << '\n'
                               << "Parser duration:    " << parser_duration.count() << " ms\n"
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
