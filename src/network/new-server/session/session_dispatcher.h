#pragma once

#include <chrono>
#include <memory>

#include <boost/asio.hpp>


namespace NewServer {

class Server;

/**
 * Handle the initial connection and chooses the type of client that has connected
 */
class SessionDispatcher : public std::enable_shared_from_this<SessionDispatcher> {
public:
    Server& server;

    boost::asio::ip::tcp::socket socket;

    std::chrono::seconds timeout;

    SessionDispatcher(Server& server, boost::asio::ip::tcp::socket socket, std::chrono::seconds timeout) :
        server { server }, socket { std::move(socket) }, timeout { timeout } { }

    void run();

    void do_read(const boost::system::error_code& ec, std::size_t bytes_transferred);

private:
    boost::asio::streambuf buffer;
};
} // namespace NewServer