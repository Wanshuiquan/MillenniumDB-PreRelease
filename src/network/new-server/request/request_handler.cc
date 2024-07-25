#include "request_handler.h"

#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/new-server/protocol.h"
#include "query/query_context.h"
#include "storage/tmp_manager.h"


using namespace NewServer;

inline auto get_duration(std::chrono::system_clock::time_point start) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now() - start
    ).count();
}


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
        logger(Category::Debug) << "Request received: PULL(" << num_records << ")";
        handle_pull(num_records);
        break;
    }
    case Protocol::RequestType::DISCARD: {
        // Discard in other states are ignored
        if (session.state != Protocol::ServerState::STREAMING) {
            return;
        }

        logger(Category::Debug) << "Request received: DISCARD";
        handle_discard();
        break;
    }
    case Protocol::RequestType::CATALOG: {
        logger(Category::Debug) << "Request received: CATALOG";
        handle_catalog();
        break;
    }
    default: {
        throw ProtocolException("Unhandled request type: "
                                + Protocol::request_type_to_string(request_type));
    }
    }
}


void RequestHandler::handle_pull(uint32_t num_records) {
    bool has_next = current_physical_plan->pull(*response_writer, num_records);

    if (has_next) {
        // There are more records to pull
        response_writer->write_pull_success_has_next();
    } else {
        // All records have been pulled
        execution_duration_ms = get_duration(execution_start);

        logger.log(Category::ExecutionStats, [&](std::ostream& os) {
            current_physical_plan->analyze(os, true);
            os << '\n';
        });

        logger(Category::Info)
            << "Results:            " << current_physical_plan->get_result_count() << '\n'
            << "Parser duration:    " << parser_duration_ms    << " ms\n"
            << "Optimizer duration: " << optimizer_duration_ms << " ms\n"
            << "Execution duration: " << execution_duration_ms << " ms";
        response_writer->write_pull_success_final(current_physical_plan->get_result_count(),
                                                  parser_duration_ms,
                                                  optimizer_duration_ms,
                                                  execution_duration_ms);
        session.state = Protocol::ServerState::READY;
    }

    response_writer->flush();
}


void RequestHandler::handle_discard() {
    get_query_ctx().thread_info.interruption_requested = true;
    session.state = Protocol::ServerState::READY;

    response_writer->write_discard_success();
    response_writer->flush();
}


void RequestHandler::handle_run(const std::string& query) {
    tmp_manager.reset();
    get_query_ctx().reset();

    try {
        const auto query_start = std::chrono::system_clock::now();
        {
            std::lock_guard<std::mutex> lock(session.get_thread_info_vec_mutex());
            get_query_ctx().thread_info.interruption_requested = false; // used in query optimization
            get_query_ctx().thread_info.time_start             = query_start;
            get_query_ctx().thread_info.timeout                = query_start + session.get_timeout();
        }

        auto parser_start = std::chrono::system_clock::now();
        auto current_logical_plan = create_logical_plan(query);
        parser_duration_ms = get_duration(parser_start);

        if (!current_logical_plan->read_only()) {
            response_writer->write_error("Only read-only queries are supported");
            response_writer->flush();
            return;
        }

        auto optimizer_start  = std::chrono::system_clock::now();
        current_physical_plan = create_readonly_physical_plan(*current_logical_plan);
        optimizer_duration_ms = get_duration(optimizer_start);

        logger.log(Category::PhysicalPlan, [&](std::ostream& os) {
            current_physical_plan->analyze(os, false);
            os << '\n';
        });

        execution_start = std::chrono::system_clock::now();

        const auto projection_vars = current_physical_plan->get_projection_vars();
        response_writer->write_run_success(projection_vars);
        response_writer->flush();

        session.state = Protocol::ServerState::STREAMING;
    }
    catch (const QueryException& e) {
        const auto msg = std::string("Query Exception: ") + e.what();
        logger(Category::Error) << msg;
        response_writer->write_error(msg);
        response_writer->flush();
    }
    catch (const LogicException& e) {
        const auto msg = std::string("Logic Exception: ") + e.what();
        logger(Category::Error) << msg;
        response_writer->write_error(msg);
        response_writer->flush();
    }
}


void RequestHandler::handle_catalog() {
    response_writer->write_catalog_success();
    response_writer->flush();
}
