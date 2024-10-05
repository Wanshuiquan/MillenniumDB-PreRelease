//
// Created by lhy on 10/2/24.
//

#ifndef MILLENNIUMDB_ARITH_LHS_H
#define MILLENNIUMDB_ARITH_LHS_H

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
    inline bool is_mul(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprMultiplication>(expr);
    }
    inline bool is_add(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprAddition>(expr);
    }
    inline bool is_sub(std::unique_ptr<Expr> &expr){
        return is_castable_to<ExprSubtraction>(expr);
    }

    inline std::set<std::vector<std::string>> get_monomials(std::unique_ptr<Expr>& expr, bool flag){
        if (is_var(expr)){
            auto set = std::set<std::vector<std::string>>();
            if (flag) {
                set.insert({"+", std::to_string(1), expr->to_string()});
                return set;
            }
            else {
                auto vec = std::vector<std::string>();
                set.insert({"-", std::to_string(-1), expr->to_string()});
                return set;
            }

        }
        else if (is_mul(expr)){
            auto set = std::set<std::vector<std::string>>();
            if (expr->get_all_vars().empty()) {
                return {};
            }
            auto mul = cast_to<ExprMultiplication>(expr);
            auto lhs = mul ->lhs -> to_string();
            auto rhs = mul -> rhs -> to_string();
            if (flag){
                set.insert({"+", lhs, rhs});
                return set;
            }
            else{
                set.insert({"-", lhs, rhs});
                return set;
            }
        }
        else if(is_add(expr)){
            assert(is_castable_to<ExprAddition>(expr));
            auto add = cast_to<ExprAddition>(expr);
            auto l = get_monomials(add->lhs, true);
            auto r = (get_monomials(add -> rhs, true));
            for (const auto& ele:l) r.insert(ele);
            return r;
        }
        else if (is_sub(expr)){
            assert(is_castable_to<ExprSubtraction>(expr));
            auto add = cast_to<ExprSubtraction>(expr);
            auto l = get_monomials(add->lhs, true);
            auto r = (get_monomials(add -> rhs, false));
            for (const auto& ele:l) r.insert(ele);
            return r;
        }
        else{
            return {};
        }
    }

    inline std::set<std::vector<std::string>> get_attr(std::unique_ptr<Expr>& expr, bool flag){
            if (is_attr(expr)){
                auto set = std::set<std::vector<std::string>>();
                if (flag) {
                    set.insert({"+", std::to_string(1), expr->to_string()});
                    return set;
                }
                else {
                    auto vec = std::vector<std::string>();
                    set.insert({"-", std::to_string(-1), expr->to_string()});
                    return set;
                }

            }
            else if (is_constant(expr)){
                auto set = std::set<std::vector<std::string>>();
                if (flag) {
                    set.insert({"+", std::to_string(1), expr->to_string()});
                    return set;
                }
                else {
                    auto vec = std::vector<std::string>();
                    set.insert({"-", std::to_string(-1), expr->to_string()});
                    return set;
                }

            }
            else if (is_mul(expr)){
                auto set = std::set<std::vector<std::string>>();
                if (! expr->get_all_vars().empty()) {
                    return {};
                }
                auto mul = cast_to<ExprMultiplication>(expr);
                auto lhs = mul ->lhs -> to_string();
                auto rhs = mul -> rhs -> to_string();
                if (flag){
                    set.insert({"+", lhs, rhs});
                    return set;
                }
                else{
                    set.insert({"-", lhs, rhs});
                    return set;
                }
            }
            else if(is_add(expr)){
                assert(is_castable_to<ExprAddition>(expr));
                auto add = cast_to<ExprAddition>(expr);
                auto l = get_monomials(add->lhs, true);
                auto r = (get_monomials(add -> rhs, true));
                for (const auto& ele:l) r.insert(ele);
                return r;
            }
            else if (is_sub(expr)){
                assert(is_castable_to<ExprSubtraction>(expr));
                auto add = cast_to<ExprSubtraction>(expr);
                auto l = get_monomials(add->lhs, true);
                auto r = (get_monomials(add -> rhs, false));
                for (const auto& ele:l) r.insert(ele);
                return r;
            }
            else{
                return {};
            }
        }
};


#endif //MILLENNIUMDB_ARITH_LHS_H
