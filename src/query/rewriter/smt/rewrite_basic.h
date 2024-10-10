//
// Created by lhy on 10/2/24.
//

#ifndef MILLENNIUMDB_REWRITE_BASIC_H
#define MILLENNIUMDB_REWRITE_BASIC_H

#pragma once

#include <set>

#include "query/parser/smt/smt_exprs.h"
#include "query/var_id.h"
#include "graph_models/quad_model/quad_object_id.h"


namespace SMT {
    template<typename T>
    inline bool is_castable_to(std::unique_ptr<Expr> &unknown_expr) {
        if (dynamic_cast<T*>(unknown_expr.get()) != nullptr) {
            return true;
        }
        return false;
    }

    template<typename T>
    inline T* cast_to(std::unique_ptr<Expr> &unknown_expr) {
        assert(dynamic_cast<T*>(unknown_expr.get()) != nullptr);
        return  dynamic_cast<T*>(unknown_expr.get());
    }

    inline bool is_var(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprVar>(expr);
    }
    inline bool is_attr(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprAttr>(expr);
    }
    inline bool is_constant(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprConstant>(expr);
    }
    inline bool is_app(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprApp>(expr);
    }

    inline bool is_eq(std::unique_ptr<Expr> &expr){
        if (!is_app(expr)){
            return false;
        }
        else{
            auto val = cast_to<ExprApp>(expr);
            return val->op == Operator::OP_EQ;
        }
    }
    inline bool is_neq(std::unique_ptr<Expr> &expr){
        if (!is_app(expr)){
            return false;
        }
        else{
            auto val = cast_to<ExprApp>(expr);
            return val->op == Operator::OP_NEQ ;
        }
    }
    inline bool is_mul(std::unique_ptr<Expr> &expr){
        if (!is_app(expr)){
            return false;
        }
        else{
            auto val = cast_to<ExprApp>(expr);
            return val->op == Operator::OP_MUL ;
        }
    }
    inline bool is_add(std::unique_ptr<Expr> &expr){
        if (!is_app(expr)){
            return false;
        }
        else{
            auto val = cast_to<ExprApp>(expr);
            return val->op == Operator::OP_ADD ;
        }
    }
    inline bool is_compare(std::unique_ptr<Expr> &expr){
        if (!is_app(expr)){
            return false;
        }
        else{
            auto val = cast_to<ExprApp>(expr);
            return val->op == Operator::OP_NEQ || val -> op == Operator::OP_EQ || val -> op == Operator::OP_GE  || val -> op == Operator::OP_LE ;
        }
    }
};


#endif //MILLENNIUMDB_REWRITE_BASIC_H
