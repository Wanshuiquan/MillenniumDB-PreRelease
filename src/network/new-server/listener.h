#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/new-server/server.h"

namespace NewServer {

class Listener : public std::enable_shared_from_this<Listener> {
public:
    Server&                        server;
    boost::asio::io_context&       io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::endpoint endpoint;
    std::chrono::seconds           timeout;

    explicit Listener(Server&                        server,
                      boost::asio::io_context&       io_context,
                      boost::asio::ip::tcp::endpoint endpoint,
                      std::chrono::seconds           timeout);

    void run();

private:
    // Returns true if the connection was accepted, false otherwise
    bool session_handler(boost::asio::ip::tcp::socket&& socket);

    void dispatch_session(const boost::system::error_code& ec, std::size_t /*bytes_transferred*/);

    void do_accept();

    inline void fail(const boost::system::error_code& ec, char const* what) const;
};
} // namespace NewServer