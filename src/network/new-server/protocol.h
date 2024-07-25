#pragma once

#include <cstdint>
#include <string>

#include "graph_models/quad_model/quad_catalog.h"
#include "graph_models/rdf_model/rdf_catalog.h"

/**
 * Packet format:
 * [chunk_size][      chunk     ]
 * [ 2 bytes  ][chunk_size bytes]
 *
 * The seal that marks the end of a message is a "zero-sized chunk" [0x00 0x00]
 *
 * Theoretically the maximum chunk size is 65'535 bytes, but our buffer size is 1400 for optimizing the MTU
 * src: https://superuser.com/questions/343107/mtu-is-1500-why-the-first-fragment-length-is-1496-in-ipv6
 *
 * We could write more than one chunk in the same buffer. It is expected that the Session and its handlers
 * manage the flushing manually if this is not intended.
 */
namespace NewServer::Protocol {
static constexpr uint16_t BUFFER_SIZE       = 1400U;
static constexpr uint16_t CHUNK_HEADER_SIZE = sizeof(uint16_t);

static constexpr uint32_t HTTP_GET_PREAMBLE = 0x47'45'54'20UL; // "GET " as uint32_t
static constexpr uint32_t MDB_PREAMBLE      = 0x4D'44'42'20UL; // "MDB " as uint32_t

constexpr std::string_view DEFAULT_BROWSER_PATH = "./browser";

static constexpr uint_fast32_t DEFAULT_PORT = 1234;

static constexpr uint_fast32_t DEFAULT_BROWSER_PORT = 4321;

static constexpr uint_fast32_t DEFAULT_TIMEOUT_SECONDS = 60;

static constexpr uint64_t QUAD_MODEL_ID = QuadCatalog::MODEL_ID;

static constexpr uint64_t RDF_MODEL_ID = RdfCatalog::MODEL_ID;

enum class DataType : uint8_t {
    NULL_,
    BOOL_FALSE,
    BOOL_TRUE,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    INT64,
    FLOAT,
    DOUBLE,
    DECIMAL,
    STRING,
    STRING_LANG,
    STRING_DATATYPE,
    IRI,
    NAMED_NODE,
    EDGE,
    ANON,
    DATE,
    TIME,
    DATETIME,
    PATH,
    LIST,
    MAP,

    TOTAL,
};

inline std::string datatype_to_string(const DataType& data_type) {
    switch (data_type) {
    case DataType::NULL_:
        return "NULL";
    case DataType::BOOL_FALSE:
        return "BOOL_FALSE";
    case DataType::BOOL_TRUE:
        return "BOOL_TRUE";
    case DataType::UINT8:
        return "UINT8";
    case DataType::UINT16:
        return "UINT16";
    case DataType::UINT32:
        return "UINT32";
    case DataType::UINT64:
        return "UINT64";
    case DataType::INT64:
        return "INT64";
    case DataType::FLOAT:
        return "FLOAT";
    case DataType::DOUBLE:
        return "DOUBLE";
    case DataType::DECIMAL:
        return "DECIMAL";
    case DataType::STRING:
        return "STRING";
    case DataType::STRING_LANG:
        return "STRING_LANG";
    case DataType::STRING_DATATYPE:
        return "STRING_DATATYPE";
    case DataType::IRI:
        return "IRI";
    case DataType::NAMED_NODE:
        return "NAMED_NODE";
    case DataType::EDGE:
        return "EDGE";
    case DataType::ANON:
        return "ANON";
    case DataType::DATE:
        return "DATE";
    case DataType::TIME:
        return "TIME";
    case DataType::DATETIME:
        return "DATETIME";
    case DataType::PATH:
        return "PATH";
    case DataType::LIST:
        return "LIST";
    case DataType::MAP:
        return "MAP";
    default:
        return "UNKNOWN_DATA_TYPE (" + std::to_string(static_cast<uint8_t>(data_type)) + ")";
    }
}


enum class RequestType : uint8_t {
    RUN,
    PULL,
    DISCARD,
    CATALOG,

    TOTAL,
};

inline std::string request_type_to_string(const RequestType& request_type) {
    switch (request_type) {
    case RequestType::RUN:
        return "RUN";
    case RequestType::PULL:
        return "PULL";
    case RequestType::DISCARD:
        return "DISCARD";
    case RequestType::CATALOG:
        return "CATALOG";
    default:
        const auto ch = std::to_string(static_cast<uint8_t>(request_type));
        return "UNKNOWN_REQUEST_TYPE (" + ch + ")";
    }
}

enum class ResponseType : uint8_t {
    SUCCESS,
    ERROR,
    RECORD,

    TOTAL,
};

inline std::string response_type_to_string(const ResponseType& response_type) {
    switch (response_type) {
    case ResponseType::SUCCESS:
        return "SUCCESS";
    case ResponseType::ERROR:
        return "ERROR";
    case ResponseType::RECORD:
        return "RECORD";
    default:
        const auto ch = std::to_string(static_cast<uint8_t>(response_type));
        return "UNKNOWN_RESPONSE_TYPE (" + ch + ")";
    }
}

enum class ServerState : uint8_t {
    READY,
    STREAMING,

    TOTAL,
};

inline std::string server_state_to_string(const ServerState& server_state) {
    switch (server_state) {
    case ServerState::READY:
        return "READY";
    case ServerState::STREAMING:
        return "STREAMING";
    default:
        const auto ch = std::to_string(static_cast<uint8_t>(server_state));
        return "UNKNOWN_SERVER_STATE (" + ch + ")";
    }
}

} // namespace NewServer::Protocol
