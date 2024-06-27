#pragma once

#include <cstdint>
#include <ostream>
#include <string>
#include <vector>

#include "graph_models/object_id.h"
#include "network/new-server/protocol.h"
#include "network/new-server/response/response_buffer.h"
#include "query/executor/binding.h"
#include "query/var_id.h"


namespace NewServer {

class AbstractStreamingSession;

class ResponseWriter {
public:
    ResponseWriter(AbstractStreamingSession& session_) :
        response_buffer { session_ }, response_ostream { &response_buffer } { }

    // Force the buffer to be flushed to the stream
    void flush();

    // Helpers


    void write_run_success(const std::vector<VarId>& projection_vars, float parser_duration, float optimizer_duration);
    void write_pull_success(bool has_next, uint_fast32_t num_records);
    void write_record(const std::vector<VarId>& projection_vars, const Binding& binding);
    void write_error(const std::string& message);

    // Primitive types
    void write_object_id(const ObjectId& oid) {
        write_object_id(response_ostream, oid);
    }
    void write_string(const std::string& value, Protocol::DataType data_type) {
        write_string(response_ostream, value, data_type);
    }
    void write_uint8(uint8_t value) {
        write_uint8(response_ostream, value);
    }
    void write_uint32(uint32_t value) {
        write_uint32(response_ostream, value);
    }
    void write_int64(int64_t value) {
        write_int64(response_ostream, value);
    }
    void write_float(float value) {
        write_float(response_ostream, value);
    }
    void write_bool(bool value) {
        write_bool(response_ostream, value);
    }
    void write_null() {
        write_null(response_ostream);
    }
    void write_path(uint64_t value) {
        write_path(response_ostream, value);
    }

    // Headers
    void write_map_header(uint32_t size);
    void write_list_header(uint32_t size);

    // Seals the buffer by calling ResponseBuffer::seal()
    void seal();

private:
    ResponseBuffer response_buffer;

    std::ostream response_ostream;

    // Data Type helpers
    static void write_object_id(std::ostream& os, const ObjectId& oid);
    static void write_string(std::ostream& os, const std::string& value, Protocol::DataType data_type);
    static void write_uint8(std::ostream& os, uint8_t value);
    static void write_uint32(std::ostream& os, uint32_t value);
    static void write_int64(std::ostream& os, int64_t value);
    static void write_float(std::ostream& os, float value);
    static void write_bool(std::ostream& os, bool value);
    static void write_null(std::ostream& os);
    static void write_path(std::ostream& os, uint64_t value);

    // Path helpers. write_path_edge receives a pointer to a number in order to track the path length
    static void write_path_node(std::ostream& os, ObjectId oid);
    static void write_path_edge(std::ostream& os, ObjectId oid, bool reverse, uint_fast32_t* path_length);

    // Convert an inlined object to its string representation
    static std::string inlined2string(uint64_t value);

    // Write the size prefix of a variable-size object
    static void write_size(std::ostream& os, uint_fast32_t size);
    void        write_size(uint_fast32_t size);
};
} // namespace NewServer