#pragma once

#include <memory>

#include <boost/asio.hpp>

#include "misc/fatal_error.h"
#include "network/old/sparql/session.h"

namespace SPARQL {

class Server;

class Listener {
    Server& server;
    boost::asio::io_context& io_context;
    boost::asio::ip::tcp::acceptor acceptor;
    std::chrono::seconds timeout;
    boost::asio::ip::tcp::endpoint endpoint; // To show port in error messages

public:
    Listener(
        Server& server,
        boost::asio::io_context& io_context,
        boost::asio::ip::tcp::endpoint endpoint,
        std::chrono::seconds timeout
    ) :
        server     (server),
        io_context (io_context),
        acceptor   (boost::asio::make_strand(io_context)),
        timeout    (timeout),
        endpoint   (endpoint)
    {
        boost::beast::error_code ec;

        // Open the acceptor
        acceptor.open(endpoint.protocol(), ec);
        if (ec) {
            fail(ec, "open");
            return;
        }

        // Allow address reuse
        acceptor.set_option(boost::asio::socket_base::reuse_address(true), ec);
        if (ec) {
            fail(ec, "set options");
            return;
        }

        // Bind to the server address
        acceptor.bind(endpoint, ec);
        if (ec) {
            fail(ec, "bind");
            return;
        }

        // Start listening for connections
        acceptor.listen(boost::asio::socket_base::max_listen_connections, ec);
        if (ec) {
            fail(ec, "listen");
            return;
        }
    }

    // Start accepting incoming connections
    void run() {
        do_accept();
    }

private:
    void do_accept() {
        // The new connection gets its own strand
        acceptor.async_accept(
            boost::asio::make_strand(io_context),
            [this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket) {
                if (!ec) {
                    // Create the session and run it
                    std::make_shared<Session>(server, std::move(socket), timeout)->run();
                }
                // Accept another connection
                do_accept();
            }
        );
    }

    void fail(boost::system::error_code ec, char const* what) {
        if (ec == boost::asio::error::address_in_use) {
            FATAL_ERROR("Port " + std::to_string(endpoint.port())
                + " already in use, try using a different port");
        } else {
            FATAL_ERROR("SPARQL::Listener error while trying to "
                + std::string(what) + ": " + ec.message());
        }
        std::exit(ec.value());
    }
};
} // namespace SPARQL
