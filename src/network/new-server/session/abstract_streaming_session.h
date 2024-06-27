// TODO: Use execution mutex on handler for write queries?
#pragma once

#include <chrono>

#include "network/new-server/protocol.h"
#include "network/new-server/server.h"

namespace NewServer {

class RequestHandler;

class AbstractStreamingSession {
    friend class RequestHandler;

public:
    explicit AbstractStreamingSession(Server& server_, std::chrono::seconds timeout_) :
        server { server_ }, timeout { timeout_ } {};

    virtual ~AbstractStreamingSession() = default;

    // Start the session. This method must finish immediately to not block the Listener/Dispatcher thread
    virtual void run() = 0;

    // Write bytes to the stream
    virtual void write(const uint8_t* bytes, std::size_t num_bytes) = 0;

protected:
    Server& server;

    std::chrono::seconds timeout;

    Protocol::ServerState state { Protocol::ServerState::READY };
};
} // namespace NewServer