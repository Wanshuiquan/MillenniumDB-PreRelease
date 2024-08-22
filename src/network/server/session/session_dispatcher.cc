#include "session_dispatcher.h"

#include "misc/logger.h"
#include "network/server/protocol.h"
#include "network/server/session/http/http_rdf_session.h"
#include "network/server/session/http/http_quad_session.h"
#include "network/server/session/streaming/streaming_websocket_session.h"

using namespace MDBServer;
using namespace boost;
namespace beast     = boost::beast;
namespace http      = beast::http;
namespace websocket = beast::websocket;

template<uint64_t ModelId>
void SessionDispatcher<ModelId>::run() {
    // Set the timeout for getting the query
    stream.expires_after(Protocol::DEFAULT_CONNECTION_TIMEOUT_SECONDS);

    http::async_read(stream,
                     buffer,
                     request,
                     beast::bind_front_handler(&SessionDispatcher::on_read, this->shared_from_this()));
}


template<uint64_t ModelId>
void SessionDispatcher<ModelId>::on_read(boost::system::error_code& ec, std::size_t /*bytes_transferred*/) {
    if (ec) {
        stream.close();
        logger(Category::Error) << "Could not read the connection preamble";
        return;
    }

    // Handle WebSocket HTTP upgrade request
    if (websocket::is_upgrade(request)) {
        auto self      = this->shared_from_this();
        auto ws_stream = std::make_shared<websocket::stream<beast::tcp_stream>>(std::move(stream));

        // Try to handshake with the WebSocket client
        ws_stream->async_accept(request, [self, ws_stream](const boost::system::error_code& ec) {
            if (ec) {
                ws_stream->close(websocket::close_code::abnormal);
                logger(Category::Error) << "Could not perform the WebSocket handshake with the client";
                return;
            }

            logger(Category::Info) << "Dispatching StreamingWebSocketSession";
            std::make_shared<StreamingWebSocketSession<ModelId>>(self->server,
                                                                 std::move(*ws_stream),
                                                                 self->query_timeout)
              ->run();
        });
        return;
    }

    // Handle regular HTTP requests
    logger(Category::Info) << "Dispatching HTTPSession";
    if constexpr (ModelId == Protocol::QUAD_MODEL_ID) {
        std::make_shared<HttpQuadSession>(server, std::move(stream), std::move(request), query_timeout)->run();
    } else if constexpr (ModelId == Protocol::RDF_MODEL_ID) {
        std::make_shared<HttpRdfSession>(server, std::move(stream), std::move(request), query_timeout)->run();
    } else {
        throw std::runtime_error("Unhandled ModelId" + std::to_string(ModelId));
    }
}


template class MDBServer::SessionDispatcher<MDBServer::Protocol::QUAD_MODEL_ID>;
template class MDBServer::SessionDispatcher<MDBServer::Protocol::RDF_MODEL_ID>;
