//
// Created by lhy on 10/14/24.
//

#ifndef MILLENNIUMDB_SIMPLIFY_MUL_H
#define MILLENNIUMDB_SIMPLIFY_MUL_H
#pragma once
#include "smt_rewrite_rule.h"
namespace SMT {
/**
 * n1 * n2 = val(n1*n2)
 */
    class SimplifyMUL : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(App &unknown_expr) override {
            if (!unknown_expr.is_mul()) {
                return false;
            }
            int val_count = 0;
            for (auto &expr: unknown_expr.param) {
                if (expr.is_val()) {
                    val_count = val_count + 1;
                }
            }

            return val_count >= 2;
        }

        App &regroup(App &unknown_expr) override {
            std::vector<App> values;
            std::vector<App> new_param;
            for (auto &expr: unknown_expr.param) {
                if (expr.is_val()) {
                    values.push_back(expr);
                } else {
                    new_param.push_back(expr);
                }
            }
                // calculate the val
                 double_t simpl = 1;
                for (const auto &val: values) {
                    simpl = simpl * std::stod(val.val.value());
                }
                if (new_param.empty()) {
                    unknown_expr.val= std::to_string(simpl);
                    unknown_expr.op = SMTOp::SMT_VAL;
                } else{
                    new_param.emplace_back(SMTOp::SMT_VAL, std::to_string(simpl));
                    unknown_expr.param.clear();
                    unknown_expr.param.swap(new_param);
                }

            return unknown_expr;


        }
    };
}
#endif //MILLENNIUMDB_SIMPLIFY_MUL_H
