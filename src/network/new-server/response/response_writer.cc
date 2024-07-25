#include "response_writer.h"

#include <sstream>

#include "query/executor/binding_iter/paths/path_manager.h"
#include "query/query_context.h"

using namespace NewServer;

void ResponseWriter::flush() {
    response_ostream.flush();
}


void ResponseWriter::write_run_success(const std::vector<VarId>& projection_vars) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(1UL);
    write_string("projectionVariables", Protocol::DataType::STRING);
    write_list_header(projection_vars.size());
    for (const auto& var_id : projection_vars) {
        const auto var_name = get_query_ctx().get_var_name(var_id);
        write_string(var_name, Protocol::DataType::STRING);
    }

    seal();
}


void ResponseWriter::write_pull_success_has_next() {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(1UL);
    write_string("hasNext", Protocol::DataType::STRING);
    write_bool(true);

    seal();
}


void ResponseWriter::write_discard_success() {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(0UL);

    seal();
}


void ResponseWriter::write_pull_success_final(uint64_t result_count,
                                              uint64_t parser_duration_ms,
                                              uint64_t optimizer_duration_ms,
                                              uint64_t execution_duration_ms) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(5UL);
    write_string("hasNext", Protocol::DataType::STRING);
    write_bool(false);
    write_string("resultCount", Protocol::DataType::STRING);
    write_uint64(result_count);
    write_string("parserDurationMs", Protocol::DataType::STRING);
    write_uint64(parser_duration_ms);
    write_string("optimizerDurationMs", Protocol::DataType::STRING);
    write_uint64(optimizer_duration_ms);
    write_string("executionDurationMs", Protocol::DataType::STRING);
    write_uint64(execution_duration_ms);

    seal();
}


void ResponseWriter::write_catalog_success() {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(2UL);
    write_string("modelId", Protocol::DataType::STRING);
    write_uint64(get_model_id());
    write_string("version", Protocol::DataType::STRING);
    write_uint64(get_catalog_version());

    seal();
}


void ResponseWriter::write_record(const std::vector<VarId>& projection_vars, const Binding& binding) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::RECORD));

    write_string("payload", Protocol::DataType::STRING);
    write_list_header(projection_vars.size());
    for (const auto& var : projection_vars) {
        write_object_id(binding[var]);
    }

    seal();
}


void ResponseWriter::write_error(const std::string& message) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::ERROR));

    write_string("payload", Protocol::DataType::STRING);
    write_string(message, Protocol::DataType::STRING);

    seal();
}


std::string ResponseWriter::encode_null() const {
    return std::string(1, static_cast<char>(Protocol::DataType::NULL_));
}


std::string ResponseWriter::encode_bool(bool value) const {
    return std::string(1, static_cast<char>(value ? Protocol::DataType::BOOL_TRUE : Protocol::DataType::BOOL_FALSE));
}


std::string ResponseWriter::encode_uint8(uint8_t value) const {
    uint8_t bytes[2];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::UINT8);
    bytes[1] = static_cast<uint8_t>(value);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_size(uint32_t value) const {
    uint8_t bytes[4];
    bytes[0] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[1] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[3] = static_cast<uint8_t>(value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_float(float value_) const {
    auto*   value = reinterpret_cast<uint32_t*>(&value_);
    uint8_t bytes[5];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::FLOAT);
    bytes[1] = static_cast<uint8_t>((*value >> 24) & 0xFF);
    bytes[2] = static_cast<uint8_t>((*value >> 16) & 0xFF);
    bytes[3] = static_cast<uint8_t>((*value >> 8) & 0xFF);
    bytes[4] = static_cast<uint8_t>(*value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_double(double value_) const {
    auto*   value = reinterpret_cast<uint64_t*>(&value_);
    uint8_t bytes[9];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::DOUBLE);
    bytes[1] = static_cast<uint8_t>((*value >> 56) & 0xFF);
    bytes[2] = static_cast<uint8_t>((*value >> 48) & 0xFF);
    bytes[3] = static_cast<uint8_t>((*value >> 40) & 0xFF);
    bytes[4] = static_cast<uint8_t>((*value >> 32) & 0xFF);
    bytes[5] = static_cast<uint8_t>((*value >> 24) & 0xFF);
    bytes[6] = static_cast<uint8_t>((*value >> 16) & 0xFF);
    bytes[7] = static_cast<uint8_t>((*value >> 8) & 0xFF);
    bytes[8] = static_cast<uint8_t>(*value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_uint32(uint32_t value) const {
    uint8_t bytes[5];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::UINT32);
    bytes[1] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[3] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[4] = static_cast<uint8_t>(value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_uint64(uint64_t value) const {
    uint8_t bytes[9];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::UINT64);
    bytes[1] = static_cast<uint8_t>((value >> 56) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 48) & 0xFF);
    bytes[3] = static_cast<uint8_t>((value >> 40) & 0xFF);
    bytes[4] = static_cast<uint8_t>((value >> 32) & 0xFF);
    bytes[5] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[6] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[7] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[8] = static_cast<uint8_t>(value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_int64(int64_t value) const {
    uint8_t bytes[9];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::INT64);
    bytes[1] = static_cast<uint8_t>((value >> 56) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 48) & 0xFF);
    bytes[3] = static_cast<uint8_t>((value >> 40) & 0xFF);
    bytes[4] = static_cast<uint8_t>((value >> 32) & 0xFF);
    bytes[5] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[6] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[7] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[8] = static_cast<uint8_t>(value & 0xFF);
    return std::string(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


std::string ResponseWriter::encode_string(const std::string& value, Protocol::DataType data_type) const {
    std::string res;
    res += static_cast<char>(data_type);
    res += encode_size(value.size());
    res += value;
    return res;
}


std::string ResponseWriter::encode_path(uint64_t path_id) const {
    using namespace std::placeholders;
    uint_fast32_t     path_length = 0UL;
    std::stringstream ss;
    path_manager.print(ss,
                       path_id,
                       std::bind(&ResponseWriter::write_path_node, this, _1, _2),
                       std::bind(&ResponseWriter::write_path_edge, this, _1, _2, _3, &path_length));

    std::string res;
    res += static_cast<char>(Protocol::DataType::PATH);
    res += encode_size(path_length);
    res += ss.str();
    return res;
}


std::string ResponseWriter::encode_date(DateTime datetime) const {
    bool          error;
    const int64_t year          = datetime.get_year(&error);
    const int64_t month         = datetime.get_month(&error);
    const int64_t day           = datetime.get_day(&error);
    const int64_t tz_min_offset = datetime.get_tz_min_offset(&error);

    std::string res;
    res += static_cast<char>(Protocol::DataType::DATE);
    res += encode_int64(year);
    res += encode_int64(month);
    res += encode_int64(day);
    res += encode_int64(error ? 0 : tz_min_offset);

    return res;
}


std::string ResponseWriter::encode_time(DateTime datetime) const {
    bool          error;
    const int64_t hour          = datetime.get_hour(&error);
    const int64_t minute        = datetime.get_minute(&error);
    const int64_t second        = datetime.get_second(&error);
    const int64_t tz_min_offset = datetime.get_tz_min_offset(&error);

    std::string res;
    res += static_cast<char>(Protocol::DataType::TIME);
    res += encode_int64(hour);
    res += encode_int64(minute);
    res += encode_int64(second);
    res += encode_int64(error ? 0 : tz_min_offset);
    return res;
}


std::string ResponseWriter::encode_datetime(DateTime datetime) const {
    bool          error;
    const int64_t year          = datetime.get_year(&error);
    const int64_t month         = datetime.get_month(&error);
    const int64_t day           = datetime.get_day(&error);
    const int64_t hour          = datetime.get_hour(&error);
    const int64_t minute        = datetime.get_minute(&error);
    const int64_t second        = datetime.get_second(&error);
    const int64_t tz_min_offset = datetime.get_tz_min_offset(&error);

    std::string res;
    res += static_cast<char>(Protocol::DataType::DATETIME);
    res += encode_int64(year);
    res += encode_int64(month);
    res += encode_int64(day);
    res += encode_int64(hour);
    res += encode_int64(minute);
    res += encode_int64(second);
    res += encode_int64(error ? 0 : tz_min_offset);
    return res;
}


void ResponseWriter::seal() {
    response_buffer.seal();
}


void ResponseWriter::write_path_node(std::ostream& os, ObjectId oid) const {
    const auto encoded_oid = encode_object_id(oid);
    os.write(encoded_oid.c_str(), encoded_oid.size());
}


void ResponseWriter::write_path_edge(std::ostream& os, ObjectId oid, bool reverse, uint_fast32_t* path_length) const {
    const auto encoded_reverse = encode_bool(reverse);
    os.write(encoded_reverse.c_str(), encoded_reverse.size());

    const auto encoded_oid = encode_object_id(oid);
    os.write(encoded_oid.c_str(), encoded_oid.size());

    ++(*path_length);
}


void ResponseWriter::write_size(uint_fast32_t value) {
    uint8_t bytes[4];
    bytes[0] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[1] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[3] = static_cast<uint8_t>(value & 0xFF);
    response_ostream.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}
