#include "listener.h"

#include "misc/logger.h"
#include "network/new-server/session/session_dispatcher.h"

using namespace NewServer;
using namespace boost;

Listener::Listener(Server&                 server_,
                   asio::io_context&       io_context,
                   asio::ip::tcp::endpoint endpoint,
                   std::chrono::seconds    timeout) :
    server { server_ },
    io_context { io_context },
    acceptor { asio::make_strand(io_context) },
    endpoint { endpoint },
    timeout { timeout } {
    boost::system::error_code ec;

    // Open the acceptor
    (void) acceptor.open(endpoint.protocol(), ec);
    if (ec) {
        fail(ec, "open");
    }

    // Allow address reuse
    (void) acceptor.set_option(asio::socket_base::reuse_address(true), ec);
    if (ec) {
        fail(ec, "set options");
    }

    // Bind to the server address
    (void) acceptor.bind(endpoint, ec);
    if (ec) {
        fail(ec, "bind");
    }

    // Start listening for connections
    (void) acceptor.listen(asio::socket_base::max_listen_connections, ec);
    if (ec) {
        fail(ec, "listen");
    }
}

void Listener::run() {
    do_accept();
}

void Listener::do_accept() {
    acceptor.async_accept(asio::make_strand(io_context),
                          [&](const boost::system::error_code& ec, asio::ip::tcp::socket socket) {
                              // A new connection is accepted
                              logger(Category::Info) << "New client connected";
                              if (!ec) {
                                  std::make_shared<SessionDispatcher>(server, std::move(socket), timeout)->run();
                              }

                              // Accept another connection
                              do_accept();
                          });
}


void Listener::fail(const boost::system::error_code& ec, char const* what) const {
    if (ec == boost::asio::error::address_in_use) {
        logger(Category::Error) << "Port " << endpoint.port()
            << " already in use, try using a different port";
    } else {
        logger(Category::Error) << "MillenniumDB::Listener error while trying to " << what << ": "
            << ec.message();
    }
    std::exit(ec.value());
}
