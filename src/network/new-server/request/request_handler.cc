#include "request_handler.h"

#include <antlr4-runtime.h>

#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/new-server/protocol.h"
#include "network/new-server/session/abstract_streaming_session.h"
#include "query/optimizer/quad_model/streaming_executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/mql_query_parser.h"
#include "query/query_context.h"
#include "storage/tmp_manager.h"

using namespace NewServer;

void RequestHandler::handle(const uint8_t* request_bytes, std::size_t request_size) {
    request_reader.set_request(request_bytes, request_size);

    const auto request_type = request_reader.read_request_type();
    switch (request_type) {
    case Protocol::RequestType::RUN: {
        if (session.state != Protocol::ServerState::READY) {
            throw ProtocolException("Cannot handle RUN request in state: "
                                    + Protocol::server_state_to_string(session.state));
        }

        const auto query = request_reader.read_string();
        logger(Category::Info) << "Request received: RUN(" << query << ")";
        handle_run(query);
        break;
    }
    case Protocol::RequestType::PULL: {
        if (session.state != Protocol::ServerState::STREAMING) {
            throw ProtocolException("Cannot handle PULL request in state: "
                                    + Protocol::server_state_to_string(session.state));
        }

        const auto num_records = request_reader.read_uint32();
        logger(Category::Info) << "Request received: PULL(" << num_records << ")";
        handle_pull(num_records);
        break;
    }
    case Protocol::RequestType::DISCARD: {
        if (session.state != Protocol::ServerState::STREAMING) {
            throw ProtocolException("Cannot handle DISCARD request in state: "
                                    + Protocol::server_state_to_string(session.state));
        }

        logger(Category::Info) << "Request received: DISCARD";
        handle_discard();
        break;
    }
    default: {
        throw ProtocolException("Unhandled request type: " + Protocol::request_type_to_string(request_type));
    }
    }
}


void RequestHandler::handle_run(const std::string& query) {
    tmp_manager.reset();
    get_query_ctx().reset();

    try {
        std::chrono::duration<float, std::milli> parser_duration;
        std::chrono::duration<float, std::milli> optimizer_duration;

        auto current_logical_plan = create_logical_plan(query, &parser_duration);
        logger(Category::Info) << "Parser duration: " << parser_duration.count() << " ms";

        if (!current_logical_plan->read_only()) {
            response_writer.write_error("Only read-only queries are supported");
            response_writer.flush();
            return;
        }

        current_physical_plan = create_readonly_physical_plan(*current_logical_plan, &optimizer_duration);
        logger.log(Category::PhysicalPlan, [&](std::ostream& os) {
            current_physical_plan->analyze(os, false);
            os << '\n';
        });
        logger(Category::Info) << "Optimizer duration: " << optimizer_duration.count() << " ms";

        const auto projection_vars = current_physical_plan->get_projection_vars();
        response_writer.write_run_success(projection_vars, parser_duration.count(), optimizer_duration.count());
        response_writer.flush();

        session.state = Protocol::ServerState::STREAMING;
    }
    catch (const QueryException& e) {
        const auto msg = std::string("Query Exception: ") + e.what();
        logger(Category::Error) << msg;
        response_writer.write_error(msg);
        response_writer.flush();
    }
    catch (const LogicException& e) {
        const auto msg = std::string("Logic Exception: ") + e.what();
        logger(Category::Error) << msg;
        response_writer.write_error(msg);
        response_writer.flush();
    }
}


void RequestHandler::handle_pull(uint32_t num_records) {
    bool has_next = current_physical_plan->pull(response_writer, num_records);

    response_writer.write_pull_success(has_next, current_physical_plan->get_result_count());
    if (!has_next) {
        session.state = Protocol::ServerState::READY;
    }

    response_writer.flush();
}


void RequestHandler::handle_discard() {
    get_query_ctx().thread_info.interruption_requested = true;
    session.state = Protocol::ServerState::READY;

    response_writer.write_pull_success(false, current_physical_plan->get_result_count());
    response_writer.flush();
}


std::unique_ptr<Op>
  RequestHandler::create_logical_plan(const std::string& query, std::chrono::duration<float, std::milli>* duration) {
    const auto start = std::chrono::system_clock::now();
    {
        std::lock_guard<std::mutex> lock(session.server.thread_info_vec_mutex);
        get_query_ctx().thread_info.interruption_requested = false; // used in query optimization
        get_query_ctx().thread_info.time_start             = start;
        get_query_ctx().thread_info.timeout                = start + session.timeout;
    }
    antlr4::MyErrorListener error_listener;
    auto logical_plan = MQL::QueryParser::get_query_plan(query, &error_listener);
    *duration = std::chrono::system_clock::now() - start;
    return logical_plan;
}


inline std::unique_ptr<StreamingQueryExecutor>
  RequestHandler::create_readonly_physical_plan(Op& logical_plan, std::chrono::duration<float, std::milli>* duration) {
    const auto start = std::chrono::system_clock::now();
    MQL::StreamingExecutorConstructor query_optimizer;
    logical_plan.accept_visitor(query_optimizer);
    *duration = std::chrono::system_clock::now() - start;
    return std::move(query_optimizer.executor);
}
