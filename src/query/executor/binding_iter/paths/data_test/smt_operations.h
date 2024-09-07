//
// Created by lhy on 9/7/24.
//

#ifndef MILLENNIUMDB_SMT_OPERATIONS_H
#define MILLENNIUMDB_SMT_OPERATIONS_H
//
// Created by lhy on 9/6/24.
//
#pragma once
#include <variant>
#include <iostream>

#include "graph_models/inliner.h"
#include "graph_models/quad_model/conversions.h"
#include "graph_models/quad_model/quad_object_id.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"
#include "z3++.h"

// Decode Object ID
using Result = std::variant<double, std::string, bool>;
Result decode_mask(ObjectId oid) {
    const auto mask        = oid.id & ObjectId::TYPE_MASK;
    const auto unmasked_id = oid.id & ObjectId::VALUE_MASK;
    std::stringstream escaped_os;
    std::stringstream os;
    switch (mask) {
        case ObjectId::MASK_NULL: {
            return "null";
        }

        case ObjectId::MASK_STRING_SIMPLE_INLINED: {
            Inliner::print_string_inlined<7>(escaped_os, unmasked_id);
            auto val = escaped_os.str();
            return val;
        }
        case ObjectId::MASK_STRING_SIMPLE_EXTERN: {
            string_manager.print(escaped_os, unmasked_id);
            auto val = escaped_os.str();
            return val;
        }
        case ObjectId::MASK_STRING_SIMPLE_TMP: {
            tmp_manager.print_str(escaped_os, unmasked_id);
            auto val = escaped_os.str();
            return val;

        }
        case ObjectId::MASK_NEGATIVE_INT:
        case ObjectId::MASK_POSITIVE_INT: {
            int64_t i = Common::Conversions::unpack_int(oid);
            return (double_t) i;
        }
        case ObjectId::MASK_FLOAT: {
            double_t f = Common::Conversions::unpack_float(oid);
            return f;
        }
        case ObjectId::MASK_BOOL: {
            return  unmasked_id != 0;
        }

        default:
            throw std::logic_error("Unmanaged mask in ReturnExecutor print: "
                                   + std::to_string(mask));
    }
}

class SMTContext{
private:
    z3::context context = z3::context();
    // The definition of Sorts
    z3::sort_vector sort = z3::sort_vector(context);
    z3::sort STRING = context.string_sort();
    z3::sort REAL = context.real_sort();
    z3::sort BOOL = context.bool_sort();
    //The definition of func vector
    z3::func_decl_vector dels = z3::func_decl_vector(context);

public:
    SMTContext(){}
    void add_bool_var(const std::string& name){
        dels.push_back(context.function(name.c_str(),0,0,BOOL));
    }
    void add_bool_val(bool val) {
        context.bool_val(val);

    }

    void add_real_var(const std::string& name) {
        dels.push_back(context.function(name.c_str(), 0, 0, REAL));
    }
    void add_real_val(double_t val){
        context.real_val(std::to_string(val).c_str());
    }

    void add_string_var(const std::string& name){
        dels.push_back(context.function(name.c_str(),0,0,STRING));

    }
    void add_string_val(const std::string& val){context.string_val(val.c_str());}

    void add_obj_var(const std::string&  name){
        dels.push_back(context.function(name.c_str(),0,0,REAL));

    }
    void add_obj_val(uint64_t val){context.real_val(val);}

    auto parse (const std::string& formula){
        auto f = context.parse_string(formula.c_str(), sort, dels);
        return f;
    }
};

#endif //MILLENNIUMDB_SMT_OPERATIONS_H
