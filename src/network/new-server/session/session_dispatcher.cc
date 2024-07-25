#include "session_dispatcher.h"

#include <boost/beast.hpp>

#include "boost/bind/bind.hpp"
#include "misc/logger.h"
#include "network/new-server/protocol.h"
#include "network/new-server/session/websocket/websocket_streaming_session.h"
#include "query/exceptions.h"


using namespace NewServer;
using namespace boost;

template<uint64_t ModelId>
void SessionDispatcher<ModelId>::run() {
    boost::asio::async_read(socket,
                            buffer.prepare(sizeof(uint32_t)),
                            boost::bind(&SessionDispatcher::do_read,
                                        this->shared_from_this(),
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}


template<uint64_t ModelId>
void SessionDispatcher<ModelId>::do_read(const boost::system::error_code& ec_, std::size_t /*bytes_transferred*/) {
    boost::system::error_code ec;
    if (ec_) {
        socket.close();
        logger(Category::Error) << "Could not read the connection preamble";
        return;
    }
    buffer.commit(sizeof(uint32_t));

    // Extract the preamble
    uint32_t preamble = 0;
    auto     tmp      = asio::buffer_cast<const uint8_t*>(buffer.data());
    preamble |= static_cast<uint32_t>(tmp[0]) << 24;
    preamble |= static_cast<uint32_t>(tmp[1]) << 16;
    preamble |= static_cast<uint32_t>(tmp[2]) << 8;
    preamble |= static_cast<uint32_t>(tmp[3]);

    if (preamble == Protocol::MDB_PREAMBLE) {
        // TODO: Implement
        throw NotSupportedException("TCP Client not supported yet");
    } else if (preamble == Protocol::HTTP_GET_PREAMBLE) {
        // Try to handshake the WebSocket upgrade request
        asio::read_until(socket, buffer, "\r\n\r\n", ec);
        if (ec) {
            socket.close();
            logger(Category::Error) << "Could not read WebSocket upgrade request";
            return;
        }
        beast::websocket::stream<asio::ip::tcp::socket> stream { std::move(socket) };
        stream.accept(buffer.data(), ec);
        if (ec) {
            socket.close();
            logger(Category::Error) << "WebSocket handshake failed. " << ec.message();
            return;
        }
        logger(Category::Info) << "WebSocket client accepted";
        std::make_shared<WebSocketStreamingSession<ModelId>>(server, timeout, std::move(stream))->run();
    } else {
        socket.close();
        logger(Category::Error) << "Unknown client type";
    }
}


template class NewServer::SessionDispatcher<NewServer::Protocol::QUAD_MODEL_ID>;
template class NewServer::SessionDispatcher<NewServer::Protocol::RDF_MODEL_ID>;
