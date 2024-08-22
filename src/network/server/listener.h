#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/server/server.h"

namespace MDBServer {

template <uint64_t ModelId>
class Listener {
public:
    Server<ModelId>&              server;
    boost::asio::io_context&       io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    boost::asio::ip::tcp::endpoint endpoint;
    std::chrono::seconds           query_timeout;

    explicit Listener(Server<ModelId>&              server,
                      boost::asio::io_context&       io_context,
                      boost::asio::ip::tcp::endpoint endpoint,
                      std::chrono::seconds           query_timeout);

    void run();

private:
    void do_accept();

    inline void fail(const boost::system::error_code& ec, char const* what) const;
};
} // namespace MDBServer
