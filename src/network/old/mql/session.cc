#include "session.h"

#include <memory>
#include <mutex>

#include <boost/bind/bind.hpp>

#include "graph_models/quad_model/quad_model.h"
#include "misc/trim.h"
#include "network/exceptions.h"
#include "network/old/mql/server.h"
#include "network/old/mql/tcp_buffer.h"
#include "query/optimizer/quad_model/executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/mql_query_parser.h"
#include "storage/tmp_manager.h"


using namespace boost;
using namespace MQL;
using namespace std::chrono;

void Session::run() {
    boost::asio::async_read(
        socket,
        boost::asio::buffer(query_size_b, CommunicationProtocol::BYTES_FOR_QUERY_LENGTH),
        boost::bind(
            &Session::do_read,
            shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}


void Session::do_read(const boost::system::error_code& ec, std::size_t /*bytes_transferred*/) {
    std::string query;

    if (ec) {
        logger(Category::Error) << "Error receiving the query size";
        return;
    }

    try {
        assert(CommunicationProtocol::BYTES_FOR_QUERY_LENGTH == 4);

        int query_size = 0;
        for (int i = 0, offset = 0; i < CommunicationProtocol::BYTES_FOR_QUERY_LENGTH; i++, offset += 8) {
            query_size += query_size_b[i] << offset;
        }
        query.resize(query_size);
        boost::asio::read(socket, boost::asio::buffer(query.data(), query_size));

        logger(Category::Query) << "-------------------------------------\n" << trim_string(query) << "\n";
    } catch (...) {
        logger(Category::Error) << "Error receiving the query";
        return;
    }

    TcpBuffer tcp_buffer(socket);
    std::ostream os(&tcp_buffer);

    // without this line ConnectionException won't be caught properly
    os.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    tmp_manager.reset();
    get_query_ctx().reset();

    std::unique_ptr<QueryExecutor> physical_plan;
    try {
        std::shared_lock s_lock(server.execution_mutex);
        auto logical_plan = create_logical_plan(query);
        if (logical_plan->read_only()) {
            physical_plan = create_readonly_physical_plan(*logical_plan);
        } else {
            std::unique_lock u_lock(server.execution_mutex);
            // TODO: implement inserts for quad model
            // quad_model.exec_inserts(*reinterpret_cast<OpInsert*>(logical_plan.get()));
        }
    }
    catch (const QueryException& e) {
        logger(Category::Error) << "Query Exception: " << e.what();
        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::query_error);
    }
    catch (const LogicException& e) {
        logger(Category::Error) << "Logic Exception: " << e.what();
        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::logic_error);
    }

    if (physical_plan == nullptr) {
        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::logic_error);
        return;
    }

    try {
        execute_plan(*physical_plan, os);
        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::success);
    }
    catch (const ConnectionException& e) {
        logger(Category::Error) << "Connection Exception: " << e.what();
    }
    catch (const InterruptedException& e) {
        execution_duration = std::chrono::system_clock::now() - execution_start;

        logger.log(Category::ExecutionStats, [&physical_plan](std::ostream& os) {
            physical_plan->analyze(os, true);
            os << '\n';
        });

        logger(Category::Info) << "Timeout thrown after "
            << std::chrono::duration_cast<std::chrono::milliseconds>(execution_duration).count()
            << " ms";

        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::timeout);
    }
    catch (const QueryExecutionException& e) {
        logger(Category::Error) << "Query Execution Exception: " << e.what();
        tcp_buffer.set_status(CommunicationProtocol::StatusCodes::unexpected_error);
    }
}


std::unique_ptr<Op> Session::create_logical_plan(const std::string& query) {
    auto start_parser = std::chrono::system_clock::now();
    {
        std::lock_guard<std::mutex> lock(server.thread_info_vec_mutex);
        get_query_ctx().thread_info.interruption_requested = false; // used in query optimization
        get_query_ctx().thread_info.time_start = start_parser;
        get_query_ctx().thread_info.timeout = start_parser + timeout;
    }
    antlr4::MyErrorListener error_listener;
    auto logical_plan = MQL::QueryParser::get_query_plan(query, &error_listener);
    parser_duration = std::chrono::system_clock::now() - start_parser;
    return logical_plan;
}


void Session::execute_plan(QueryExecutor& physical_plan, std::ostream& os) {
    execution_start = std::chrono::system_clock::now();
    logger.log(Category::PhysicalPlan, [&physical_plan](std::ostream& os) {
        physical_plan.analyze(os, false);
        os << '\n';
    });

    auto result_count = physical_plan.execute(os);
    execution_duration = std::chrono::system_clock::now() - execution_start;

    logger.log(Category::ExecutionStats, [&physical_plan](std::ostream& os) {
        physical_plan.analyze(os, true);
        os << '\n';
    });

    logger(Category::Info)
        << "Results: " << result_count << '\n'
        << "Parser duration:    " << parser_duration.count()    << " ms\n"
        << "Optimizer duration: " << optimizer_duration.count() << " ms\n"
        << "Execution duration: " << execution_duration.count() << " ms";
}


std::unique_ptr<QueryExecutor> Session::create_readonly_physical_plan(Op& logical_plan) {
    auto start_optimizer = std::chrono::system_clock::now();

    MQL::ExecutorConstructor query_optimizer(MQL::ReturnType::CSV);
    logical_plan.accept_visitor(query_optimizer);

    optimizer_duration = std::chrono::system_clock::now() - start_optimizer;
    return std::move(query_optimizer.executor);
}


void Session::fail(boost::system::error_code& ec, char const* what) {
    logger(Category::Error) << what << ": " << ec.message();
}
