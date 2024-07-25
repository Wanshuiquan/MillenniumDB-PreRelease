#pragma once

#include <chrono>
#include <memory>

#include <boost/asio.hpp>


namespace NewServer {

template <uint64_t ModelId>
class Server;

/**
 * Handle the initial connection and chooses the type of client that has connected
 */
template<uint64_t ModelId>
class SessionDispatcher : public std::enable_shared_from_this<SessionDispatcher<ModelId>> {
public:
    Server<ModelId>& server;

    boost::asio::ip::tcp::socket socket;

    std::chrono::seconds timeout;

    SessionDispatcher(Server<ModelId>& server, boost::asio::ip::tcp::socket socket, std::chrono::seconds timeout) :
        server  (server),
        socket  (std::move(socket)),
        timeout (timeout) { }

    void run();

    void do_read(const boost::system::error_code& ec, std::size_t bytes_transferred);

private:
    boost::asio::streambuf buffer;
};
} // namespace NewServer
