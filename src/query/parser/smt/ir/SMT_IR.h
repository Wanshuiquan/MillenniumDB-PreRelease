//
// Created by lhy on 10/8/24.
//

#ifndef MILLENNIUMDB_SMT_IR_H
#define MILLENNIUMDB_SMT_IR_H
#pragma once
#include <optional>
#include <utility>
#include  <functional>
#include "query/parser/smt/smt_exprs.h"
#include "boost/algorithm/string.hpp"
#include "z3++.h"
enum SMTOp{
    SMT_ADD,
    SMT_MUL,
    SMT_SUB,
    SMT_LE,
    SMT_GE,
    SMT_AND,
    SMT_EQ,
    SMT_NEQ,
    SMT_PARA,
    SMT_ATTR,
    SMT_VAL,
};


inline std::hash<std::string> str_hash;
inline std::map<size_t, std::string> str_map;

class App{
public:
    SMTOp op;
    std::vector<App> param;

    App(SMTOp op, std::vector<App>& p): op(op), param(std::move(p)), hash(str_hash(to_smt_lib())){}
    App(SMTOp op,
        std::vector<App>& p,
        std::optional<VarId> var,
        std::optional<std::string> val,
        std::optional<std::tuple<ObjectId, std::string>> attr,
        size_t hash
        ): op(op), param(std::move(p)), var(var), val(std::move(val)), attr(std::move(attr)), hash(hash){}

    App(SMTOp op, VarId v): op(op), var(v),hash(str_hash(to_smt_lib())){}
    App(SMTOp op, std::string v): op(op), val(v), hash(str_hash(to_smt_lib())){}
    App(SMTOp op, std::tuple<ObjectId, std::string> attr): op(op), attr(attr), hash(str_hash(to_string())){}

    std::optional<VarId> var = std::nullopt;
    std::optional<std::string> val = std::nullopt;
    std::optional<std::tuple<ObjectId, std::string>> attr = std::nullopt;
    size_t hash;

    std::string to_string() const{
        auto res = str_map.find(hash);
        if (res == str_map.end()){
            str_map[hash] = to_smt_lib();
            return str_map[hash];
        } else{
            return res->second;
        }
    };

    std::string to_smt_lib() const;
    z3::expr to_z3_ast() const;

    App* copy(){
        return new App(op, param);
    }

    std::unique_ptr<App> clone(){
        return std::make_unique<App>(
                op,
                param,
                var,
                val,
                attr,
                hash
                );
    }

    bool is_add() const{
        return op == SMTOp::SMT_ADD;
         }
    bool is_sub() const{
        return op == SMTOp::SMT_SUB;
    }
    bool is_mul() const{
        return op == SMTOp::SMT_MUL;
    }
    bool is_eq() const{
        return op == SMTOp::SMT_EQ;
    }
    bool is_neq() const{
        return op == SMTOp::SMT_NEQ;
    }
    bool is_ge() const{
        return op == SMTOp::SMT_GE;
    }
    bool is_le() const{
        return op == SMTOp::SMT_LE;
    }
    bool is_and() const{
        return op == SMTOp::SMT_AND;
    }
    bool is_attr() const{
        return op == SMTOp::SMT_ATTR;
    }
    bool is_var() const{
        return op == SMTOp::SMT_PARA;
    }
    bool is_val() const{
        return op == SMTOp::SMT_VAL;
    }
    std::vector<App> get_parameters(){
        return std::move(param);
    }

    std::set<VarId> get_all_vars(){
        if (var.has_value()){
            return {var.value()};
        }
        else{
            auto res = std::set<VarId>();
            for (auto& para: param){
                auto v = para.get_all_vars();
                std::for_each(v.begin(), v.end(), [&res](VarId const & a){res.insert(a);});
            }
            return  res;
        }
    }
    std::set<std::string> get_all_attributes(){
        if (attr.has_value()){
            return {std::get<1>(attr.value())};
        }
        else{
            auto res = std::set<std::string>();
            for (auto& para: param){
                auto v = para.get_all_attributes();
                std::for_each(v.begin(), v.end(), [&res](std::string const & a){res.insert(a);});
            }
            return  res;
        }
    }


};


class IR_CTX{
public:
    std::map<std::string, App> lhs_terms;
    std::map<std::string, std::tuple<SMTOp, App, App>> bounded_terms;
    std::map<std::string, std::tuple<SMTOp, App, App>> str_terms;
    std::map<std::string, std::tuple<SMTOp, App, App>> terms_without_vars;
    std::map<std::string, App> formula_map;

    void reset(){
        lhs_terms.clear();
        bounded_terms.clear();
        str_terms.clear();
        formula_map.clear();
    }
};

inline IR_CTX* ctx_ir = new IR_CTX();

inline  IR_CTX& get_ir_ctx(){
    return *ctx_ir;
}
#endif //MILLENNIUMDB_SMT_IR_H
