//
// Created by lhy on 10/14/24.
//

#ifndef MILLENNIUMDB_FLAT_MUL_H
#define MILLENNIUMDB_FLAT_MUL_H
#pragma once
#include "smt_rewrite_rule.h"
namespace SMT {
/**
 * E1 * (E2 * E3) = E1 * E2 * E3
 */
    class FlatMul : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(App &unknown_expr) override {
            if (!unknown_expr.is_mul()) {
                return false;
            }
            for (auto &expr: unknown_expr.param) {
                if (expr.is_mul()) {
                    return true;
                }
            }
            return false;
        }

        App &regroup(App &unknown_expr) override {
            std::vector<App> new_parameter;
            for (auto &expr: unknown_expr.param) {
                if (expr.is_mul()) {
                    std::for_each(expr.param.begin(), expr.param.end(),
                                  [&new_parameter](App &a) { new_parameter.push_back(a); });
                } else {
                    new_parameter.push_back(expr);
                }
            }
            unknown_expr.param.clear();
            unknown_expr.param.swap(new_parameter);
            return unknown_expr;
        }
    };

#endif //MILLENNIUMDB_FLAT_MUL_H
}