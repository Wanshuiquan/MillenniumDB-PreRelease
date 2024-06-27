#pragma once

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "abstract_streaming_session.h"
#include "misc/logger.h"
#include "network/exceptions.h"
#include "network/new-server/request/request_handler.h"

namespace NewServer {

class TCPStreamingSession : public AbstractStreamingSession, public std::enable_shared_from_this<TCPStreamingSession> {
    using tcp_stream_type = boost::beast::tcp_stream;

public:
    explicit TCPStreamingSession(Server& server_, std::chrono::seconds timeout_, tcp_stream_type&& stream_) :
        AbstractStreamingSession { server_, timeout_ }, stream { std::move(stream_) }, request_handler { *this } { }

    ~TCPStreamingSession() override {
        if (stream.socket().is_open()) {
            stream.close();
            logger(Category::Debug) << "TCPSession: connection closed by destructor";
        }
    }

    void run() override {
        boost::asio::dispatch(
          stream.get_executor(),
          boost::beast::bind_front_handler(&TCPStreamingSession::start_session, shared_from_this()));
    }

    void write(const uint8_t* bytes, std::size_t num_bytes) override {
        stream.write_some(boost::asio::buffer(bytes, num_bytes), ec);

        if (ec) {
            stream.close();
            throw ConnectionException("TCPSession write error: " + ec.message());
        }
    }


private:
    boost::beast::error_code ec;

    tcp_stream_type stream;

    boost::beast::flat_buffer request_buffer;

    RequestHandler request_handler;

    void start_session() {
        while (stream.socket().is_open()) {
            stream.read_some(request_buffer.prepare(Protocol::BUFFER_SIZE), ec);

            if (ec) {
                logger(Category::Error) << "TCPSession read error: " << ec.message();
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
                stream.close();
                logger(Category::Debug) << "Interruption exception: Query timed out";
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
