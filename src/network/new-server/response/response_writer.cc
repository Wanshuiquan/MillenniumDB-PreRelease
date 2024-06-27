#include "response_writer.h"

#include <sstream>

#include "graph_models/rdf_model/conversions.h"
#include "graph_models/rdf_model/datatypes/datetime.h"
#include "query/executor/binding_iter/paths/path_manager.h"
#include "query/query_context.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"

using namespace NewServer;

void ResponseWriter::flush() {
    response_ostream.flush();
}


void ResponseWriter::write_run_success(const std::vector<VarId>& projection_vars,
                                       float                     parser_duration,
                                       float                     optimizer_duration) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(3UL);
    write_string("projectionVariables", Protocol::DataType::STRING);
    write_list_header(projection_vars.size());
    for (const auto& var_id : projection_vars) {
        const auto var_name = get_query_ctx().get_var_name(var_id);
        write_string(var_name, Protocol::DataType::STRING);
    }
    write_string("parserDuration", Protocol::DataType::STRING);
    write_float(parser_duration);
    write_string("optimizerDuration", Protocol::DataType::STRING);
    write_float(optimizer_duration);

    seal();
}


void ResponseWriter::write_pull_success(bool has_next, uint_fast32_t num_records) {
    write_map_header(2UL);
    write_string("type", Protocol::DataType::STRING);
    write_uint8(static_cast<uint8_t>(Protocol::ResponseType::SUCCESS));

    write_string("payload", Protocol::DataType::STRING);
    write_map_header(2UL);
    write_string("hasNext", Protocol::DataType::STRING);
    write_bool(has_next);
    write_string("numRecords", Protocol::DataType::STRING);
    write_uint32(num_records);

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


void ResponseWriter::seal() {
    response_buffer.seal();
}


void ResponseWriter::write_uint8(std::ostream& os, uint8_t value) {
    uint8_t bytes[2];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::UINT8);
    bytes[1] = value;
    os.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


void ResponseWriter::write_uint32(std::ostream& os, uint32_t value) {
    uint8_t bytes[5];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::UINT32);
    bytes[1] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[3] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[4] = static_cast<uint8_t>(value & 0xFF);
    os.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


void ResponseWriter::write_int64(std::ostream& os, int64_t value) {
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
    os.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


void ResponseWriter::write_float(std::ostream& os, float value_) {
    auto* value = reinterpret_cast<uint32_t*>(&value_);
    uint8_t bytes[5];
    bytes[0] = static_cast<uint8_t>(Protocol::DataType::FLOAT);
    bytes[1] = static_cast<uint8_t>((*value >> 24) & 0xFF);
    bytes[2] = static_cast<uint8_t>((*value >> 16) & 0xFF);
    bytes[3] = static_cast<uint8_t>((*value >> 8) & 0xFF);
    bytes[4] = static_cast<uint8_t>(*value & 0xFF);
    os.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}


void ResponseWriter::write_string(std::ostream& os, const std::string& value, Protocol::DataType data_type) {
    os.put(static_cast<char>(data_type));
    write_size(os, value.size());
    os.write(value.c_str(), value.size());
}


void ResponseWriter::write_map_header(uint32_t size) {
    response_ostream.put(static_cast<char>(Protocol::DataType::MAP));
    write_size(size);
}


void ResponseWriter::write_list_header(uint32_t size) {
    response_ostream.put(static_cast<char>(Protocol::DataType::LIST));
    write_size(size);
}


void ResponseWriter::write_bool(std::ostream& os, bool value_) {
    const auto value = value_ ? static_cast<char>(Protocol::DataType::BOOL_TRUE)
                              : static_cast<char>(Protocol::DataType::BOOL_FALSE);
    os.put(value);
}


void ResponseWriter::write_null(std::ostream& os) {
    os.put(static_cast<char>(Protocol::DataType::NULL_));
}


void ResponseWriter::write_object_id(std::ostream& os, const ObjectId& oid) {
    const auto type  = oid.id & ObjectId::TYPE_MASK;
    const auto value = oid.id & ObjectId::VALUE_MASK;
    switch (type) {
    case ObjectId::MASK_NULL: {
        write_null(os);
        break;
    }
    case ObjectId::MASK_ANON_INLINED: {
        write_string(os, "_a" + std::to_string(value), Protocol::DataType::ANON);
        break;
    }
    case ObjectId::MASK_NAMED_NODE_INLINED: {
        write_string(os, inlined2string(value), Protocol::DataType::NAMED_NODE);
        break;
    }
    case ObjectId::MASK_NAMED_NODE_EXTERN: {
        std::stringstream ss;
        string_manager.print(ss, value);
        write_string(os, ss.str(), Protocol::DataType::NAMED_NODE);
        break;
    }
    case ObjectId::MASK_NAMED_NODE_TMP: {
        std::stringstream ss;
        tmp_manager.print_str(ss, value);
        write_string(os, ss.str(), Protocol::DataType::NAMED_NODE);
        break;
    }
    case ObjectId::MASK_STRING_SIMPLE_INLINED: {
        write_string(os, inlined2string(value), Protocol::DataType::STRING);
        break;
    }
    case ObjectId::MASK_STRING_SIMPLE_EXTERN: {
        std::stringstream ss;
        string_manager.print(ss, value);
        write_string(os, ss.str(), Protocol::DataType::STRING);
        break;
    }
    case ObjectId::MASK_STRING_SIMPLE_TMP: {
        std::stringstream ss;
        tmp_manager.print_str(ss, value);
        write_string(os, ss.str(), Protocol::DataType::STRING);
        break;
    }
    case ObjectId::MASK_NEGATIVE_INT: {
        const int64_t neg_id = -((~value) & ObjectId::VALUE_MASK);
        write_int64(os, neg_id);
        break;
    }
    case ObjectId::MASK_POSITIVE_INT: {
        write_int64(os, static_cast<int64_t>(value));
        break;
    }
    case ObjectId::MASK_FLOAT: {
        float f;
        auto  bytes = reinterpret_cast<char*>(&f);

        bytes[0] = value & 0xFF;
        bytes[1] = (value >> 8) & 0xFF;
        bytes[2] = (value >> 16) & 0xFF;
        bytes[3] = (value >> 24) & 0xFF;
        write_float(os, f);
        break;
    }
    case ObjectId::MASK_BOOL: {
        write_bool(os, value != 0);
        break;
    }
    case ObjectId::MASK_EDGE: {
        write_string(os, "_e" + std::to_string(value), Protocol::DataType::EDGE);
        break;
    }
    case ObjectId::MASK_DT_DATE:
    case ObjectId::MASK_DT_DATETIME:
    case ObjectId::MASK_DT_DATETIMESTAMP:
    case ObjectId::MASK_DT_TIME: {
        const auto datetime_str = SPARQL::Conversions::unpack_date(oid).get_value_string();
        write_string(os, datetime_str, Protocol::DataType::DATETIME);
        break;
    }
    case ObjectId::MASK_PATH: {
        write_path(os, value);
        break;
    }
    default: {
        throw std::logic_error("Unmanaged type in ResponseWriter::write_object_id: " + std::to_string(type));
    }
    }
}

void ResponseWriter::write_path(std::ostream& os, uint64_t value) {
    using namespace std::placeholders;
    uint_fast32_t     path_length = 0UL;
    std::stringstream ss;
    path_manager.print(ss,
                       value,
                       std::bind(&ResponseWriter::write_path_node, _1, _2),
                       std::bind(&ResponseWriter::write_path_edge, _1, _2, _3, &path_length));

    os.put(static_cast<char>(Protocol::DataType::PATH));
    write_size(os, path_length);
    const auto path_bytes = ss.str();
    os.write(path_bytes.c_str(), path_bytes.size());
}


void ResponseWriter::write_path_node(std::ostream& os, ObjectId oid) {
    write_object_id(os, oid);
}


void ResponseWriter::write_path_edge(std::ostream& os, ObjectId oid, bool reverse, uint_fast32_t* path_length) {
    write_bool(os, reverse);
    write_object_id(os, oid);
    ++(*path_length);
}


void ResponseWriter::write_size(std::ostream& os, uint_fast32_t value) {
    uint8_t bytes[4];
    bytes[0] = static_cast<uint8_t>((value >> 24) & 0xFF);
    bytes[1] = static_cast<uint8_t>((value >> 16) & 0xFF);
    bytes[2] = static_cast<uint8_t>((value >> 8) & 0xFF);
    bytes[3] = static_cast<uint8_t>(value & 0xFF);
    os.write(reinterpret_cast<const char*>(bytes), sizeof(bytes));
}

void ResponseWriter::write_size(uint_fast32_t value) {
    write_size(response_ostream, value);
}


std::string ResponseWriter::inlined2string(uint64_t value) {
    std::string res;
    for (size_t i = 1; i < 8; ++i) {
        uint8_t byte = (value >> (8 * (8 - i - 1))) & 0xFF;
        if (byte == 0U) {
            break;
        }
        res += static_cast<char>(byte);
    }
    return res;
}