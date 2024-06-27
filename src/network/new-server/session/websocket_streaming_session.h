#pragma once

#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>

#include "abstract_streaming_session.h"
#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/new-server/request/request_handler.h"

namespace NewServer {

class WebSocketStreamingSession :
    public AbstractStreamingSession,
    public std::enable_shared_from_this<WebSocketStreamingSession> {
    using websocket_stream_type = boost::beast::websocket::stream<boost::asio::ip::tcp::socket>;

public:
    explicit WebSocketStreamingSession(Server&                 server_,
                                       std::chrono::seconds    timeout_,
                                       websocket_stream_type&& stream_) :
        AbstractStreamingSession { server_, timeout_ }, stream { std::move(stream_) }, request_handler { *this } {
        stream.binary(true);
        stream.set_option(boost::beast::websocket::stream_base::timeout::suggested(boost::beast::role_type::server));
    }

    ~WebSocketStreamingSession() override {
        if (stream.is_open()) {
            stream.close(boost::beast::websocket::close_code::normal, ec);
            logger(Category::Debug) << "WebSocketSession: connection closed by destructor";
            if (ec) {
                logger(Category::Error) << "Close failed:" << ec.what();
            }
        }
    }

    void run() override {
        boost::asio::dispatch(
          stream.get_executor(),
          boost::beast::bind_front_handler(&WebSocketStreamingSession::start_session, shared_from_this()));
    }

    void write(const uint8_t* bytes, std::size_t num_bytes) override {
        stream.write(boost::asio::buffer(bytes, num_bytes), ec);

        if (ec) {
            stream.close(boost::beast::websocket::close_code::internal_error);
            throw ConnectionException("WebSocketSession write error: " + ec.message());
        }
    }

private:
    boost::beast::error_code ec;

    websocket_stream_type stream;

    boost::beast::flat_buffer request_buffer;

    RequestHandler request_handler;

    void start_session() {
        while (stream.is_open()) {
            stream.read(request_buffer, ec);

            if (ec) {
                logger(Category::Error) << "WebSocketSession read error: " << ec.message();
                return;
            }

            try {
                const auto request_bytes = boost::asio::buffer_cast<uint8_t*>(request_buffer.data());
                request_handler.handle(request_bytes, request_buffer.size());
                request_buffer.consume(request_buffer.size());
            }
            catch (const InterruptedException& e) {
                auto& response_writer = request_handler.get_response_writer();
                response_writer.write_error("Interruption exception: Query timed out");
                response_writer.flush();

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
};
} // namespace NewServer
