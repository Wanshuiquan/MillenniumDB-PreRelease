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

enum Bound {
    Ge,
    Le,
    EQ,
};
// Decode Object ID
using Result = std::variant<double, std::string, bool>;
Result inline decode_mask(ObjectId oid) {
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
    void add_obj_val(uint64_t val){
        context.real_val(val);
    }

    z3::ast_vector_tpl<z3::expr> parse (const std::string& formula){
        auto f = context.parse_string(formula.c_str(), sort, dels)[0];
        if (f.is_and()) {
            auto res = f.args();
            return res;
        }
        else {
            auto vec = z3::ast_vector_tpl<z3::expr>(context);
            vec.push_back(f);
            return vec;
        }
    }

    z3::expr subsitute_obj(std::string name, uint64_t val, z3::expr formula){
        Z3_ast var[] = {context.real_const(name.c_str())};
        Z3_ast value[] = {context.real_val(val)};
        z3::expr novi_expr = z3::to_expr(context, Z3_substitute(context, formula, 1, var, value ));
        return novi_expr;
    }

    z3::expr subsitute_real(std::string name, uint64_t val, z3::expr formula){
        Z3_ast var[] = {context.real_const(name.c_str())};
        Z3_ast value[] = {context.real_val(val)};
        z3::expr novi_expr = z3::to_expr(context, Z3_substitute(context, formula, 1, var, value ));
        return novi_expr;
    }

    z3::expr subsitute_string(std::string name, std::string val, z3::expr formula){
        Z3_ast var[] = {context.string_const(name.c_str())};
        Z3_ast value[] = {context.string_val(val)};
        z3::expr novi_expr = z3::to_expr(context, Z3_substitute(context, formula, 1, var, value ));
        return novi_expr;
    }

    z3::expr normalizition(z3::expr formula) {
        z3::params params(context);
        params.set("arith_lhs", true);
        params.set("arith_ineq_lhs", true);
        z3::tactic t = z3::with(z3::tactic(context, "simplify"),params);
        z3::goal g(context);
        g.add(formula);
        auto res = t(g);
        z3::goal subgoal = res[0];
        return subgoal.as_expr().simplify();
    }

    std::tuple<Bound, z3::expr, z3::expr> get_bound(z3::expr formula){
       if (formula.is_app()){
           z3::expr lhs = formula.arg(0);
           z3::expr rhs = formula.arg(1);
           switch (formula.decl().decl_kind()) {
               case Z3_OP_EQ: return {Bound::EQ, lhs, rhs};
               case Z3_OP_GE: return {Bound::Ge, lhs, rhs};
               case Z3_OP_LE: return {Bound::Le, lhs, rhs};
               default: throw std::logic_error("Not support");
           }
       }
       else{
           throw std::logic_error("Should be app formulas");
       }
    }

    void print_bound(std::tuple<Bound, z3::expr, z3::expr> bound, std::ostream& os){
        auto lhs = std::get<1>(bound);
        auto rhs = std::get<2>(bound);
        switch (std::get<0>(bound)) {
            case Bound::EQ: os<< "EQ" <<" " << lhs <<  " "<< rhs << std::endl; break;
            case Bound::Le: os << "Le" << " " << lhs << " " << rhs << std::endl; break;
            case Bound::Ge: os << "Ge" << " " << lhs << " "<< rhs << std::endl; break;
        }
    }

};

#endif //MILLENNIUMDB_SMT_OPERATIONS_H
