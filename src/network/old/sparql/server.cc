#include "server.h"

#include <array>
#include <csignal>
#include <cstddef>
#include <iostream>
#include <thread>

#include <boost/asio.hpp>

#include "network/old/sparql/listener.h"

using namespace boost;
using namespace SPARQL;

bool SPARQL::Server::shutdown_server = false;

void Server::execute_timeouts() {
    while (!shutdown_server) {
        auto now = std::chrono::system_clock::now();
        {
            std::lock_guard<std::mutex> lock(thread_info_vec_mutex);
            for (auto& query_ctx : query_contexts) {
                if (query_ctx.thread_info.timeout <= now) {
                    query_ctx.thread_info.interruption_requested = true;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


void Server::run(
    unsigned short port,
    int number_of_workers,
    std::chrono::seconds timeout)
{
    shutdown_server = false;

    // The io_context is required for all I/O
    asio::io_context io_context(number_of_workers);

    // Create and launch a listening port
    SPARQL::Listener listener(
        *this,
        io_context,
        asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port),
        timeout
    );

    std::signal(SIGTERM, &signal_shutdown_server);
    std::signal(SIGINT,  &signal_shutdown_server);

    // to make io_context have some work and not finish immediately
    // after calling run() when creating threads
    auto work_guard = asio::make_work_guard(io_context);

    // Run the I/O service on the requested number of threads
    std::vector<std::thread> threads;
    threads.reserve(number_of_workers);
    query_contexts.resize(number_of_workers);
    for (auto i = 0; i < number_of_workers; ++i) {
        threads.emplace_back([&, i] {
            auto& qc = query_contexts[i];
            QueryContext::set_query_ctx(&qc);
            get_query_ctx().thread_info.worker_index = i;
            io_context.run();
        });
    }

    listener.run();
    work_guard.reset();

    std::cout << "SPARQL Server running on port " << port << std::endl;
    std::cout << "To terminate press CTRL-C" << std::endl;

    execute_timeouts();

    // If we get here, it means we got a SIGINT or SIGTERM
    std::cout << "\nShutting down server..." << std::endl;
    for (auto& query_ctx : query_contexts) {
        query_ctx.thread_info.interruption_requested = true;
    }

    io_context.stop();

    // Block until all the threads exit
    for (auto& thread : threads) {
        thread.join();
    }
}
