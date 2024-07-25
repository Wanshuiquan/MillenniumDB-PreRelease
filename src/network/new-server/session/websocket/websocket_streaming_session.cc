#include "websocket_streaming_session.h"

#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/new-server/protocol.h"
#include "network/new-server/request/quad_request_handler.h"
#include "network/new-server/request/rdf_request_handler.h"
#include "network/new-server/server.h"


using namespace NewServer;
using namespace boost;

template<uint64_t ModelId>
WebSocketStreamingSession<ModelId>::WebSocketStreamingSession(
    Server<ModelId>&        server,
    std::chrono::seconds    timeout,
    websocket_stream_type&& stream_
) :
    server  (server),
    timeout (timeout),
    stream  (std::move(stream_))
{
    if constexpr (ModelId == Protocol::QUAD_MODEL_ID) {
        request_handler = std::make_unique<QuadRequestHandler>(*this);
    } else if constexpr (ModelId == Protocol::RDF_MODEL_ID) {
        request_handler = std::make_unique<RdfRequestHandler>(*this);
    } else {
        throw std::runtime_error("Unhandled ModelId" + std::to_string(ModelId));
    }

    stream.binary(true);
    stream.set_option(boost::beast::websocket::stream_base::timeout::suggested(boost::beast::role_type::server));
}


template<uint64_t ModelId>
WebSocketStreamingSession<ModelId>::~WebSocketStreamingSession() {
    if (stream.is_open()) {
        stream.close(boost::beast::websocket::close_code::normal, ec);
        logger(Category::Debug) << "WebSocketSession: connection closed by destructor";
        if (ec) {
            logger(Category::Error) << "Close failed:" << ec.what();
        }
    }
}


template<uint64_t ModelId>
void WebSocketStreamingSession<ModelId>::run() {
    boost::asio::dispatch(
      stream.get_executor(),
      boost::beast::bind_front_handler(&WebSocketStreamingSession::start_session, this->shared_from_this()));
}


template<uint64_t ModelId>
void WebSocketStreamingSession<ModelId>::write(const uint8_t* bytes, std::size_t num_bytes) {
    stream.write(boost::asio::buffer(bytes, num_bytes), ec);

    if (ec) {
        stream.close(boost::beast::websocket::close_code::internal_error);
        throw ConnectionException("WebSocketSession write error: " + ec.message());
    }
}


template<uint64_t ModelId>
void WebSocketStreamingSession<ModelId>::start_session() {
    while (stream.is_open()) {
        stream.read(request_buffer, ec);

        if (ec) {
            logger(Category::Error) << "WebSocketSession read error: " << ec.message();
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

            stream.close(boost::beast::websocket::close_code::normal, ec);
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
std::mutex& WebSocketStreamingSession<ModelId>::get_thread_info_vec_mutex() {
    return server.thread_info_vec_mutex;
}


template<uint64_t ModelId>
std::chrono::seconds WebSocketStreamingSession<ModelId>::get_timeout() {
    return timeout;
}

template class NewServer::WebSocketStreamingSession<NewServer::Protocol::QUAD_MODEL_ID>;
template class NewServer::WebSocketStreamingSession<NewServer::Protocol::RDF_MODEL_ID>;
