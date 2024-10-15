#pragma once
#include "smt_rewrite_rule.h"
namespace SMT {
/**
 * (E2 + E3)* E1 = (E1 * E2) + (E1 * E3)
 * We perform the distribution as long as the ast is a binary tree
 */
    class DistributeMulIntoPlusLeft : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(App & unknown_expr) override {
            if (! unknown_expr.is_mul()){
                return false;
            }
            return unknown_expr.param[0].is_add();
        }

        App& regroup(App &unknown_expr) override {
            std::vector<App> new_parameter;
            auto lhs = unknown_expr.param[0];
            auto rhs = unknown_expr.param[1];


            std::for_each(lhs.param.begin(), rhs.param.end(),
                                  [&new_parameter,&unknown_expr](App &a) {
                                      std::vector<App> para_vec;
                                      para_vec.push_back(unknown_expr.param[1]);
                                      para_vec.push_back(a);
                                      new_parameter.emplace_back(SMTOp::SMT_MUL, para_vec); });


            unknown_expr.param.clear();
            unknown_expr.param.swap(new_parameter);
            unknown_expr.op = SMTOp::SMT_ADD;
            return unknown_expr;
        }
    };


    /****
 *  E1 *(E2 + E3) = (E1 * E2) + (E1 * E3)
 * We perform the distribution as long as the ast is a binary tree
 */
    class DistributeMulIntoPlusRight : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(App & unknown_expr) override {
            if (! unknown_expr.is_mul()){
                return false;
            }
            return unknown_expr.param[1].is_add();
        }

        App& regroup(App &unknown_expr) override {
            std::vector<App> new_parameter;
            auto lhs = unknown_expr.param[0];
            auto rhs = unknown_expr.param[1];
            std::for_each(rhs.param.begin(), rhs.param.end(),
                              [&new_parameter,&unknown_expr](App &a) {
                                  std::vector<App> para_vec;
                                  para_vec.push_back(unknown_expr.param[0]);
                                  para_vec.push_back(a);
                                  new_parameter.emplace_back(SMTOp::SMT_MUL, para_vec); });


            unknown_expr.param.clear();
            unknown_expr.param.swap(new_parameter);
            unknown_expr.op = SMTOp::SMT_ADD;
            return unknown_expr;
        }
    };

}