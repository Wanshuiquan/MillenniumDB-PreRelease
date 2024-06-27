#pragma once

#include <chrono>
#include <mutex>
#include <vector>

#include "query/query_context.h"

namespace NewServer {

// Server singleton
class Server {
public:
    static constexpr std::string_view DEFAULT_BROWSER_PATH = "./browser";

    static constexpr uint_fast32_t DEFAULT_PORT = 1234;

    static constexpr uint_fast32_t DEFAULT_BROWSER_PORT = 4321;

    static constexpr uint_fast32_t DEFAULT_TIMEOUT_SECONDS = 60;

    void run(unsigned short       port,
             unsigned short       browser_port,
             bool                 launch_browser,
             int                  num_threads,
             std::chrono::seconds timeout);

    static bool shutdown_server;

    std::vector<QueryContext> query_contexts;

    // Used to prevent synchronization problems between tht timeout thread and the worker thread
    std::mutex thread_info_vec_mutex;

    static void signal_shutdown_server(int signal);

    void execute_timeouts();
};
} // namespace NewServer