#pragma once

#include <chrono>
#include <memory>

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/server/protocol.h"


namespace MDBServer {

template<uint64_t ModelId>
class Server;

/**
 * Handle the initial connection and chooses the session based on the type of client that has connected
 */
template<uint64_t ModelId>
class SessionDispatcher : public std::enable_shared_from_this<SessionDispatcher<ModelId>> {
public:
    SessionDispatcher(Server<ModelId>&               server,
                      boost::asio::ip::tcp::socket&& socket,
                      std::chrono::seconds           query_timeout) :
        server        { server },
        stream        { std::move(socket) },
        query_timeout { query_timeout } { }

    void run();

private:
    Server<ModelId>& server;

    boost::beast::tcp_stream stream;

    std::chrono::seconds query_timeout;

    boost::beast::flat_buffer buffer;

    boost::beast::http::request<boost::beast::http::string_body> request;

    void on_read(boost::system::error_code& ec, std::size_t bytes_transferred);
};
} // namespace MDBServer
