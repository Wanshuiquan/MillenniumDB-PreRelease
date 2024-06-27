#pragma once

#include <chrono>
#include <memory>
#include <mutex>
#include <ostream>

#include <boost/asio.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>

#include "network/sparql/response_type.h"
#include "network/sparql/server.h"
#include "query/executor/query_executor/query_executor.h"
#include "query/query_context.h"

class Op;

namespace SPARQL {

class OpUpdate;
class Server;

// Handles an HTTP server connection
class Session : public std::enable_shared_from_this<Session> {
    Server& server;

    boost::beast::tcp_stream stream;
    boost::beast::flat_buffer buffer;
    boost::beast::http::request<boost::beast::http::string_body> req;

    std::chrono::seconds timeout;

    using DurationMS = std::chrono::duration<float, std::milli>;

    DurationMS parser_duration;
    DurationMS optimizer_duration;
    DurationMS execution_duration;

    static inline std::chrono::seconds connection_timeout = std::chrono::seconds(10);

    static inline std::mutex update_mutex;

public:
    // Take ownership of the stream
    Session(
        Server& server,
        boost::asio::ip::tcp::socket&& socket,
        std::chrono::seconds timeout
    ) :
        server  (server),
        stream  (std::move(socket)),
        timeout (timeout) { }

    // Start the asynchronous operation
    void run();

    void do_read();

    void on_read(boost::beast::error_code ec, std::size_t bytes_transferred);

    void fail(boost::beast::error_code& ec, const char* what);

private:
    std::unique_ptr<Op> create_query_logical_plan(
        const std::string& query
    );

    std::unique_ptr<QueryExecutor> create_query_physical_plan(
        Op& logical_plan,
        ResponseType response_type
    );

    void execute_query(
        const std::string& query,
        std::ostream& os,
        ResponseType response_type
    );

    void execute_query_plan(
        QueryExecutor& physical_plan,
        std::ostream& os,
        ResponseType response_type
    );

    std::unique_ptr<OpUpdate> create_update_logical_plan(
        const std::string& query
    );

    void execute_update(const std::string& query, std::ostream& os);
};
}
