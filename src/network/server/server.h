#pragma once

#include <chrono>
#include <mutex>
#include <vector>

#include <boost/asio.hpp>

#include "query/query_context.h"


namespace MDBServer {

template<uint64_t ModelId>
class Server {
public:
    static inline bool shutdown_server = false;

    void run(unsigned short       port,
             unsigned short       browser_port,
             bool                 launch_browser,
             int                  num_threads,
             std::chrono::seconds timeout);

    std::vector<QueryContext> query_contexts;

    // Used to prevent synchronization problems between tht timeout thread and the worker thread
    std::mutex thread_info_vec_mutex;

    static void signal_shutdown_server(int signal);

    void execute_timeouts();

private:
    static void browser_session(boost::asio::ip::tcp::socket&& socket);

    static void browser_listener(boost::asio::io_context* browser_io_context, int port);
};
} // namespace MDBServer
