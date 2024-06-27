#pragma once

#include <cstdint>
#include <memory>

#include "network/new-server/request/request_reader.h"
#include "network/new-server/response/response_writer.h"
#include "query/executor/query_executor/streaming_query_executor.h"
#include "query/parser/op/op.h"

namespace NewServer {

class AbstractStreamingSession;

class RequestHandler {
public:
    RequestHandler(AbstractStreamingSession& session_) : session { session_ }, response_writer { session } { }

    void handle(const uint8_t* request_bytes, std::size_t request_size);

    ResponseWriter& get_response_writer() {
        return response_writer;
    }

private:
    AbstractStreamingSession& session;

    ResponseWriter response_writer;

    RequestReader request_reader;

    std::unique_ptr<StreamingQueryExecutor> current_physical_plan;

    // Build the logical and physical plan. On success store the result in current_physical_plan and transition to
    // STREAMING state.
    void handle_run(const std::string& query);

    // Pull num_records from current_physical_plan. On success if no more records are available, transition to READY
    // state, otherwise keep the STREAMING state.
    void handle_pull(uint32_t num_records);

    // Discard the current query execution. On success transition to READY state.
    void handle_discard();

    std::unique_ptr<Op>
    create_logical_plan(const std::string& query, std::chrono::duration<float, std::milli>* duration);

    std::unique_ptr<StreamingQueryExecutor>
    create_readonly_physical_plan(Op& logical_plan, std::chrono::duration<float, std::milli>* duration);
};
} // namespace NewServer
