#pragma once

#include <cstdint>
#include <string>
#include <sstream>

#include "graph_models/object_id.h"
#include "query/executor/query_executor/mql/return_executor.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"

namespace MQL { namespace Conversions {

    constexpr int64_t INTEGER_MAX = 0x00FF'FFFF'FFFF'FFFFL;

    // The order, int < flt < inv is important
    constexpr uint8_t OPTYPE_INTEGER = 0x01;
    constexpr uint8_t OPTYPE_FLOAT   = 0x02;
    constexpr uint8_t OPTYPE_INVALID = 0x03;

    inline int64_t unpack_int(ObjectId oid) {
        switch (oid.get_type()) {
        case ObjectId::MASK_NEGATIVE_INT:
            return static_cast<int64_t>(~oid.id & ObjectId::VALUE_MASK) * -1;
        case ObjectId::MASK_POSITIVE_INT:
            return static_cast<int64_t>(oid.get_value());;
        default:
            throw LogicException("Called unpack_int with incorrect ObjectId type, this should never happen");
        }
    }

    inline float unpack_float(ObjectId oid) {
        assert(oid.get_type() == ObjectId::MASK_FLOAT);

        auto  value = oid.id;
        float flt;
        auto  dst = reinterpret_cast<char*>(&flt);

        dst[0] = value & 0xFF;
        dst[1] = (value >> 8) & 0xFF;
        dst[2] = (value >> 16) & 0xFF;
        dst[3] = (value >> 24) & 0xFF;

        return flt;
    }

    inline float unpack_double(ObjectId oid) {
        assert(oid.get_sub_type() == ObjectId::MASK_DOUBLE);

        std::stringstream ss;
        uint64_t external_id = oid.id & ObjectId::MASK_EXTERNAL_ID;

        switch (oid.get_mod()) {
            case ObjectId::MOD_TMP: {
                tmp_manager.print_str(ss, external_id);
                break;
            }
            case ObjectId::MOD_EXTERNAL: {
                string_manager.print(ss, external_id);
                break;
            }
        }

        double dbl;
        auto dst = reinterpret_cast<char*>(&dbl);
        ss.read(dst, 8);

        return dbl;
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

    inline ObjectId pack_int(int64_t i) {
        uint64_t mask = ObjectId::MASK_POSITIVE_INT;

        if (i < 0) {
            mask = ObjectId::MASK_NEGATIVE_INT;
            i *= -1;
            if (i > INTEGER_MAX) {
                return ObjectId::get_null();
            }
            i = (~i) & ObjectId::VALUE_MASK;
        } else {
            if (i > INTEGER_MAX) {
                return ObjectId::get_null();
            }
        }
        return ObjectId(mask | i);
    }

    inline ObjectId pack_float(float flt) {
        auto src = reinterpret_cast<unsigned char*>(&flt);

        auto oid = ObjectId::MASK_FLOAT;
        oid |= static_cast<uint64_t>(src[0]);
        oid |= static_cast<uint64_t>(src[1]) << 8;
        oid |= static_cast<uint64_t>(src[2]) << 16;
        oid |= static_cast<uint64_t>(src[3]) << 24;

        return ObjectId(oid);
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
