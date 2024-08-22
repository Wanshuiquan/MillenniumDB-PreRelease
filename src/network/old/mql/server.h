#pragma once

#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <vector>

#include "query/query_context.h"

namespace MQL {

class Server {
public:
    static constexpr int DEFAULT_PORT = 8080;

    static bool shutdown_server;

    std::vector<QueryContext> query_contexts;

    // used to prevent synchronization problems between tht timeout thread
    // and the worker thread
    std::mutex thread_info_vec_mutex;

    std::shared_mutex execution_mutex;

    void execute_timeouts();

    static void signal_shutdown_server(int /*signal*/) {
        shutdown_server = true;
    }

    void run(unsigned short port,
             int worker_threads,
             std::chrono::seconds timeout);
};

} // namespace MQL
