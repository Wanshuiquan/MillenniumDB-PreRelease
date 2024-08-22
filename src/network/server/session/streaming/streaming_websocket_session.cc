#include "streaming_websocket_session.h"

#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/server/protocol.h"
#include "network/server/server.h"
#include "network/server/session/streaming/request/streaming_quad_request_handler.h"
#include "network/server/session/streaming/request/streaming_rdf_request_handler.h"


using namespace MDBServer;
using namespace boost;
namespace beast     = boost::beast;
namespace websocket = beast::websocket;


template<uint64_t ModelId>
StreamingWebSocketSession<ModelId>::StreamingWebSocketSession(Server<ModelId>&        server_,
                                                              websocket_stream_type&& stream_,
                                                              std::chrono::seconds    query_timeout_) :
    server(server_), query_timeout(query_timeout_), stream(std::move(stream_)) {
    // Bind the request handler depending on the database model
    if constexpr (ModelId == Protocol::QUAD_MODEL_ID) {
        request_handler = std::make_unique<StreamingQuadRequestHandler>(*this);
    } else if constexpr (ModelId == Protocol::RDF_MODEL_ID) {
        request_handler = std::make_unique<StreamingRdfRequestHandler>(*this);
    } else {
        throw std::runtime_error("Unhandled ModelId" + std::to_string(ModelId));
    }

    // Set WebSocket stream flags/options
    stream.binary(true);
    stream.set_option(websocket::stream_base::timeout::suggested(beast::role_type::server));
}


template<uint64_t ModelId>
StreamingWebSocketSession<ModelId>::~StreamingWebSocketSession() {
    if (stream.is_open()) {
        stream.close(websocket::close_code::normal, ec);
        logger(Category::Debug) << "WebSocketSession: connection closed by destructor";
        if (ec) {
            logger(Category::Error) << "Close failed:" << ec.what();
        }
    }
}


template<uint64_t ModelId>
void StreamingWebSocketSession<ModelId>::run() {
    boost::asio::dispatch(
      stream.get_executor(),
      beast::bind_front_handler(&StreamingWebSocketSession::start_session, this->shared_from_this()));
}


template<uint64_t ModelId>
void StreamingWebSocketSession<ModelId>::write(const uint8_t* bytes, std::size_t num_bytes) {
    stream.write(boost::asio::buffer(bytes, num_bytes), ec);

    if (ec) {
        stream.close(websocket::close_code::internal_error);
        throw ConnectionException("WebSocketSession write error: " + ec.message());
    }
}


template<uint64_t ModelId>
void StreamingWebSocketSession<ModelId>::start_session() {
    while (stream.is_open()) {
        stream.read(request_buffer, ec);

        if (ec) {
            if (ec != websocket::error::closed) {
                logger(Category::Error) << "WebSocketSession read error: " << ec.message();
            }
            return;
        }

        try {
            const auto request_bytes = boost::asio::buffer_cast<uint8_t*>(request_buffer.data());
            request_handler->handle(request_bytes, request_buffer.size());
            request_buffer.consume(request_buffer.size());
        }
        catch (const InterruptedException& e) {
            auto& response_writer = request_handler->response_writer;
            response_writer->write_error("Interruption exception: Query timed out");
            response_writer->flush();

            stream.close(websocket::close_code::normal, ec);
            logger(Category::Error) << "Interruption exception: Query timed out";
            if (ec) {
                logger(Category::Debug) << "Close failed:" << ec.what();
            }
        }
        catch (const ProtocolException& e) {
            logger(Category::Error) << "Protocol exception: " << e.what();
        }
        catch (const ConnectionException& e) {
            logger(Category::Error) << "Connection exception: " << e.what();
        }
        catch (const std::exception& e) {
            logger(Category::Error) << "Uncaught exception: " << e.what();
        }
        catch (...) {
            logger(Category::Error) << "Unexpected exception!";
        }
    }
}


template<uint64_t ModelId>
std::mutex& StreamingWebSocketSession<ModelId>::get_thread_info_vec_mutex() {
    return server.thread_info_vec_mutex;
}


template<uint64_t ModelId>
std::chrono::seconds StreamingWebSocketSession<ModelId>::get_timeout() {
    return query_timeout;
}

template class MDBServer::StreamingWebSocketSession<MDBServer::Protocol::QUAD_MODEL_ID>;
template class MDBServer::StreamingWebSocketSession<MDBServer::Protocol::RDF_MODEL_ID>;
