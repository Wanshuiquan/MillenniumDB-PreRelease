#pragma once

#include <boost/asio.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/beast/websocket.hpp>

#include "network/server/session/streaming/request/streaming_request_handler.h"
#include "network/server/session/streaming/streaming_session.h"

namespace MDBServer {

template<uint64_t ModelId>
class Server;

template<uint64_t ModelId>
class StreamingWebSocketSession :
    public StreamingSession,
    public std::enable_shared_from_this<StreamingWebSocketSession<ModelId>> {
    using websocket_stream_type = boost::beast::websocket::stream<boost::beast::tcp_stream>;

public:
    explicit StreamingWebSocketSession(Server<ModelId>&        server,
                                       websocket_stream_type&& stream,
                                       std::chrono::seconds    query_timeout);

    ~StreamingWebSocketSession();

    void run() override;

    void write(const uint8_t* bytes, std::size_t num_bytes) override;

    std::mutex& get_thread_info_vec_mutex() override;

    std::chrono::seconds get_timeout() override;

private:
    boost::beast::error_code ec;

    Server<ModelId>& server;

    std::chrono::seconds query_timeout;

    websocket_stream_type stream;

    boost::beast::flat_buffer request_buffer;

    std::unique_ptr<StreamingRequestHandler> request_handler;

    void start_session();
};
} // namespace MDBServer
