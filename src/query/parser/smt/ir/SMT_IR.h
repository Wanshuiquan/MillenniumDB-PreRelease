//
// Created by lhy on 10/8/24.
//

#ifndef MILLENNIUMDB_SMT_IR_H
#define MILLENNIUMDB_SMT_IR_H
#pragma once
#include <optional>
#include "query/parser/smt/smt_exprs.h"
#include "boost/algorithm/string.hpp"
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




class App{
public:
    SMTOp op;
    std::vector<App> param;
    App(SMTOp op, std::vector<App>& p ): op(op), param(std::move(p)){}
    App(SMTOp op, VarId v): op(op), var(v){}
    App(SMTOp op, std::string v): op(op), val(v){}
    App(SMTOp op, std::tuple<ObjectId, std::string> attr): op(op), attr(attr){}

    std::optional<VarId> var = std::nullopt;
    std::optional<std::string> val = std::nullopt;
    std::optional<std::tuple<ObjectId, std::string>> attr = std::nullopt;
    std::string to_string() const;

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
        return op == SMTOp::SMT_SUB;
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

#endif //MILLENNIUMDB_SMT_IR_H
