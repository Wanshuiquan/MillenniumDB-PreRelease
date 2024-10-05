//
// Created by lhy on 10/2/24.
//

#ifndef MILLENNIUMDB_EXPR_COMPARE_H
#define MILLENNIUMDB_EXPR_COMPARE_H
#pragma once

#include <memory>

#include "query/parser/smt/smt_expr.h"

enum Operator {
    OP_GE,
    OP_G,
    OP_LE,
    OP_L,
    OP_EQ,
    OP_NEQ
};

inline std::string get_op_smt(Operator op){
    switch (op) {
        case Operator::OP_EQ: return  "=";
        case Operator::OP_NEQ: return "distinct ";
        case Operator::OP_GE: return ">=";
        case Operator::OP_G: return ">";
        case Operator::OP_LE: return "<=";
        case Operator::OP_L: return  "<";
    }
}

inline std::string get_op_str(Operator op){
    switch (op) {
        case Operator::OP_EQ: return  "=";
        case Operator::OP_NEQ: return "!=";
        case Operator::OP_GE: return ">=";
        case Operator::OP_G: return ">";
        case Operator::OP_LE: return "<=";
        case Operator::OP_L: return  "<";
    }
}
namespace SMT {
    class ExprComparasion : public Expr {
    public:
        std::unique_ptr<Expr> lhs;
        std::unique_ptr<Expr> rhs;
        Operator op;

        ExprComparasion(Operator op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs) :
                lhs (std::move(lhs)),
                rhs (std::move(rhs)),
                op (op) { }
        ExprComparasion( const ExprComparasion& expr):
                lhs (expr.lhs.get()), rhs (expr.rhs.get()) , op (expr.op)
        {

        }
        std::string to_smt_lib() const{
            return "(  "+ get_op_smt(op) +"   " + lhs -> to_smt_lib() + "  " + rhs -> to_smt_lib() + " ) ";

        }
        std::unique_ptr<Expr> clone() const override {
            return std::make_unique<ExprComparasion>(op, lhs->clone(), rhs->clone());
        }

        void accept_visitor(ExprVisitor& visitor) override {
            visitor.visit(*this);
        }

        bool has_aggregation() const override {
            return lhs->has_aggregation() || rhs->has_aggregation();
        }

        std::set<VarId> get_all_vars() const override {
            std::set<VarId> res = lhs->get_all_vars();
            for (auto& var : rhs->get_all_vars()) {
                res.insert(var);
            }
            return res;
        }

        std::set<std::tuple<std::string, ObjectId>> get_all_attrs() const override {
            std::set<std::tuple<std::string, ObjectId>> res = lhs->get_all_attrs();
            auto rhs_vars = rhs->get_all_attrs();
            res.insert(rhs_vars.begin(), rhs_vars.end());
            return res;
        }

        std::set<VarId> get_all_parameter() const override {
            std::set<VarId> res = lhs->get_all_parameter();
            auto rhs_vars = rhs->get_all_parameter();
            res.insert(rhs_vars.begin(), rhs_vars.end());
            return res;
        }
    };
} // namespace MQL


#endif //MILLENNIUMDB_EXPR_COMPARE_H
