#pragma once

#include <cstdint>
#include <string>
#include <sstream>

#include "graph_models/common/conversions.h"
#include "query/executor/query_executor/mql/return_executor.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"
#include "graph_models/inliner.h"

namespace MQL { namespace Conversions {
    using namespace Common::Conversions;

    // The order, int < flt < inv is important
    constexpr uint8_t OPTYPE_INTEGER = 0x01;
    constexpr uint8_t OPTYPE_FLOAT   = 0x02;
    constexpr uint8_t OPTYPE_INVALID = 0x03;

    inline uint64_t unpack_blank(ObjectId oid) {
        return oid.get_value();
    }

    inline uint64_t unpack_edge(ObjectId oid) {
        return oid.get_value();
    }

    inline std::string unpack_string(ObjectId oid) {
        switch (oid.get_type()) {
        case ObjectId::MASK_STRING_SIMPLE_INLINED: {
            return Inliner::get_string_inlined<ObjectId::STR_INLINE_BYTES>(oid.get_value());
        }
        case ObjectId::MASK_STRING_SIMPLE_EXTERN: {
            std::stringstream ss;
            const uint64_t external_id = oid.id & ObjectId::MASK_EXTERNAL_ID;
            string_manager.print(ss, external_id);
            return ss.str();
        }
        case ObjectId::MASK_STRING_SIMPLE_TMP: {
            std::stringstream ss;
            const uint64_t external_id = oid.id & ObjectId::MASK_EXTERNAL_ID;
            tmp_manager.print_str(ss, external_id);
            return ss.str();
        }
        default: {
            throw LogicException("Called unpack_string with incorrect ObjectId type, this should never happen");
        }
        }
    }

    inline std::string unpack_named_node(ObjectId oid) {
        switch (oid.get_type()) {
        case ObjectId::MASK_NAMED_NODE_INLINED: {
            return Inliner::get_string_inlined<ObjectId::NAMED_NODE_INLINE_BYTES>(oid.get_value());
        }
        case ObjectId::MASK_NAMED_NODE_EXTERN: {
            std::stringstream ss;
            const uint64_t external_id = oid.id & ObjectId::MASK_EXTERNAL_ID;
            string_manager.print(ss, external_id);
            return ss.str();
        }
        case ObjectId::MASK_NAMED_NODE_TMP: {
            std::stringstream ss;
            const uint64_t external_id = oid.id & ObjectId::MASK_EXTERNAL_ID;
            tmp_manager.print_str(ss, external_id);
            return ss.str();
        }
        default: {
            throw LogicException("Called unpack_named_node with incorrect ObjectId type, this should never happen");
        }
        }
    }

    inline DateTime unpack_datetime(ObjectId oid) {
        return DateTime(oid);
    }


    /**
    *  @brief Calculates the generic datatypes of the operand in an expression.
    *  @param oid ObjectId of the operand involved in an expression.
    *  @return generic numeric datatype of the operand or OPTYPE_INVALID if oid is not numeric
    */
    inline uint8_t calculate_optype(ObjectId oid) {
        switch (oid.get_sub_type()) {
        case ObjectId::MASK_INT:     return OPTYPE_INTEGER;
        case ObjectId::MASK_FLOAT:   return OPTYPE_FLOAT;
        default:                     return OPTYPE_INVALID;
        }
    }

    inline uint8_t calculate_optype(ObjectId oid1, ObjectId oid2) {
        return std::max(calculate_optype(oid1), calculate_optype(oid2));
    }

    inline float to_float(ObjectId oid) {
        switch (oid.get_sub_type()) {
        case ObjectId::MASK_INT:
            return unpack_int(oid);
        case ObjectId::MASK_FLOAT:
            return unpack_float(oid);
        default:
            throw LogicException("Called to_float with incorrect ObjectId type, this should never happen");
        }
    }

    // Returns a string with the lexical representation of the value
    inline std::string to_lexical_str(ObjectId oid) {
        std::stringstream ss;
        MQL::ReturnExecutor<MQL::ReturnType::TSV>::print(ss, oid);
        return ss.str();
    }

    inline ObjectId to_boolean(ObjectId oid) {
        uint64_t value = oid.get_value();

        switch (oid.get_sub_type()) {
        case ObjectId::MASK_BOOL:
            return oid;
        // String
        // Note: Extern strings will never be empty
        case ObjectId::MASK_STRING_SIMPLE_INLINED:
            return ObjectId(ObjectId::MASK_BOOL | static_cast<uint64_t>(value != 0));
        case ObjectId::MASK_STRING_SIMPLE_EXTERN:
            return ObjectId(ObjectId::BOOL_TRUE);
        // Integer
        case ObjectId::MASK_NEGATIVE_INT:
        case ObjectId::MASK_POSITIVE_INT:
            return ObjectId(ObjectId::MASK_BOOL | static_cast<uint64_t>(value != 0));
        // Float
        case ObjectId::MASK_FLOAT: {
            auto f = unpack_float(oid);
            return ObjectId(ObjectId::MASK_BOOL | static_cast<uint64_t>(f != 0 && !std::isnan(f)));
        }
        // Double
        case ObjectId::MASK_DOUBLE: {
            auto d = unpack_double(oid);
            return ObjectId(ObjectId::MASK_BOOL | static_cast<uint64_t>(d != 0 && !std::isnan(d)));
        }
        // Decimal
        // Note: This assumes 0 is never represented as 0.0, 0.00, etc
        case ObjectId::MASK_DECIMAL_INLINED:
            return ObjectId(ObjectId::MASK_BOOL | static_cast<uint64_t>(value != 0));
        // Note: Extern decimals will never be zero
        case ObjectId::MASK_DECIMAL_EXTERN:
            return ObjectId(ObjectId::BOOL_TRUE);
        // Can not be converted to boolean
        default:
            return ObjectId::get_null();
        }
    }
}
} // namespace MQL::Conversions