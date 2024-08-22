#pragma once

#include <chrono>
#include <mutex>

#include "network/server/protocol.h"

namespace MDBServer {

/**
 * This class is meant to be overriden by any streaming protocol. For example, if in the future we would like to
 * implement raw TCP, this class should be inherited from. Then the other streaming classes should be able to be
 * reused.
 */
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
} // namespace MDBServer
