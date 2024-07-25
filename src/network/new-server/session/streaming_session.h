// TODO: Use execution mutex on handler for write queries?
#pragma once

#include <chrono>
#include <mutex>

#include "network/new-server/protocol.h"

namespace NewServer {

class StreamingSession {
public:
    Protocol::ServerState state { Protocol::ServerState::READY };

    virtual ~StreamingSession() = default;

    // Start the session. This method must finish immediately to not block the Listener/Dispatcher thread
    virtual void run() = 0;

    // Write bytes to the stream
    virtual void write(const uint8_t* bytes, std::size_t num_bytes) = 0;

    // Getters used in query execution
    virtual std::mutex& get_thread_info_vec_mutex() = 0;

    virtual std::chrono::seconds get_timeout() = 0;
};
} // namespace NewServer
