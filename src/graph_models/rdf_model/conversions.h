#pragma once

#include <cstdint>
#include <string>

#include "graph_models/object_id.h"
#include "graph_models/rdf_model/datatypes/datetime.h"
#include "graph_models/rdf_model/datatypes/decimal.h"
#include "graph_models/rdf_model/rdf_object_id.h"

namespace SPARQL { namespace Conversions {

    // special value for lang and datatypes
    // that indicates the lang/dtt is inlined in the string
    // example: "external_string@tmp-lang"
    //          "external_string^tmp-datatype"
    static constexpr uint64_t LAST_TMP_ID = ObjectId::MASK_LITERAL_TAG;

    static constexpr uint64_t TMP_SHIFT = 44;

    // All unpacks assumes type were checked before calling
    bool        unpack_bool(ObjectId oid);
    uint64_t    unpack_blank(ObjectId oid);
    DateTime    unpack_date(ObjectId oid);
    std::string unpack_iri(ObjectId oid);
    std::string unpack_string(ObjectId oid);

    uint64_t get_datatype_id(const std::string& datatype);
    uint64_t get_language_id(const std::string& lang);

    // returns <lang, str>
    std::pair<std::string, std::string> unpack_string_lang(ObjectId oid);

    // returns <datatype, str>
    std::pair<std::string, std::string> unpack_string_datatype(ObjectId oid);

    void print_string(ObjectId oid, std::ostream&);
    void print_iri(ObjectId oid, std::ostream&);

    // Doesn't print the language
    void print_string_lang(ObjectId oid, std::ostream&);

    // Doesn't print the datatype
    void print_string_datatype(ObjectId oid, std::ostream&);

    ObjectId string_simple_to_xsd(ObjectId oid);

    inline ObjectId pack_blank_inline(uint64_t id) {
        return ObjectId(ObjectId::MASK_ANON_INLINED | id);
    }

    inline ObjectId pack_blank_tmp(uint64_t blank_id) {
        return ObjectId(blank_id | ObjectId::MASK_ANON_TMP);
    }

    ObjectId pack_iri_inline(const char* str, uint_fast8_t prefix_id);
    ObjectId pack_string_simple_inline(const char* str);
    ObjectId pack_string_xsd_inline(const char* str);
    ObjectId pack_string_datatype_inline(uint64_t datatype_id, const char* str);
    ObjectId pack_string_lang_inline(uint64_t lang_id, const char* str);

    ObjectId pack_string_lang(const std::string& lang, const std::string& str);
    ObjectId pack_string_datatype(const std::string& dt, const std::string& str);
    ObjectId try_pack_string_datatype(const std::string& dt, const std::string& str);
    ObjectId try_pack_integer(const std::string& dt, const std::string& str);

    constexpr ObjectId pack_empty_string() {
        return ObjectId(ObjectId::STRING_SIMPLE_EMPTY);
    }

    constexpr uint64_t get_path_id(ObjectId oid) {
        return oid.id & 0x00FF'FFFF'FFFF'FFFFUL;
    }

    constexpr ObjectId pack_bool(bool b) {
        return b ? ObjectId(ObjectId::MASK_BOOL | 1)
                 : ObjectId(ObjectId::MASK_BOOL | 0);
    }


    constexpr uint64_t DECIMAL_SIGN_MASK      = 0x0080'0000'0000'0000UL;
    constexpr uint64_t DECIMAL_NUMBER_MASK    = 0x007F'FFFF'FFFF'FFF0UL;
    constexpr uint64_t DECIMAL_SEPARATOR_MASK = 0x0000'0000'0000'000FUL;
    constexpr uint64_t FLOAT_SIGN_MASK        = 0x0000'0000'8000'0000UL;

    constexpr int64_t  INTEGER_MAX            = 0x00FF'FFFF'FFFF'FFFFL;

    // The order, int < dec < flt < inv is important
    constexpr uint8_t OPTYPE_INTEGER = 0x01;
    constexpr uint8_t OPTYPE_DECIMAL = 0x02;
    constexpr uint8_t OPTYPE_FLOAT   = 0x03;
    constexpr uint8_t OPTYPE_DOUBLE  = 0x04;
    constexpr uint8_t OPTYPE_INVALID = 0x05;

    int64_t unpack_int(ObjectId oid);
    Decimal unpack_decimal(ObjectId oid);
    float   unpack_float(ObjectId oid);
    double  unpack_double(ObjectId oid);

    uint8_t calculate_optype(ObjectId oid1, ObjectId oid2);
    uint8_t calculate_optype(ObjectId oid);

    inline ObjectId pack_date(const DateTime& dt) { return ObjectId(dt.id); }

    ObjectId pack_iri(const std::string& str);
    ObjectId pack_string_simple(const std::string& str);
    ObjectId pack_string_xsd(const std::string& str);
    ObjectId pack_int(int64_t i);
    ObjectId pack_decimal(Decimal dec);
    ObjectId pack_float(float flt);
    ObjectId pack_double(double dbl);

    int64_t     to_integer(ObjectId oid);
    Decimal     to_decimal(ObjectId oid);
    float       to_float(ObjectId oid);
    double      to_double(ObjectId oid);
    ObjectId    to_boolean(ObjectId oid);

    // Returns a string with the lexical representation of the value
    std::string to_lexical_str(ObjectId oid);

    std::ostream& debug_print(std::ostream& os, ObjectId object_id);
}} // namespace SPARQL::Conversions
