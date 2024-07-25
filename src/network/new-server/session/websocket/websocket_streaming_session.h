#pragma once

#include <boost/asio.hpp>
#include <boost/beast/websocket.hpp>

#include "network/new-server/request/request_handler.h"
#include "network/new-server/session/streaming_session.h"

namespace NewServer {

template<uint64_t ModelId>
class Server;

template<uint64_t ModelId>
class WebSocketStreamingSession :
    public StreamingSession,
    public std::enable_shared_from_this<WebSocketStreamingSession<ModelId>>
{
    using websocket_stream_type = boost::beast::websocket::stream<boost::asio::ip::tcp::socket>;

public:
    explicit WebSocketStreamingSession(Server<ModelId>&        server_,
                                       std::chrono::seconds    timeout,
                                       websocket_stream_type&& stream_);

    ~WebSocketStreamingSession();

    void run() override;

    void write(const uint8_t* bytes, std::size_t num_bytes) override;

    std::mutex& get_thread_info_vec_mutex() override;

    std::chrono::seconds get_timeout() override;

private:
    boost::beast::error_code ec;

    Server<ModelId>& server;

    std::chrono::seconds timeout;

    websocket_stream_type stream;

    boost::beast::flat_buffer request_buffer;

    std::unique_ptr<RequestHandler> request_handler;

    void start_session();
};
} // namespace NewServer
