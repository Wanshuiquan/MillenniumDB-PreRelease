#pragma once

#include "query/parser/smt/smt_expr.h"

namespace SMT {
class ExprMultiplication : public Expr {
public:
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;

    ExprMultiplication(std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs) :
        lhs (std::move(lhs)),
        rhs (std::move(rhs)) { }
    ExprMultiplication( const ExprMultiplication& expr):
     lhs (expr.lhs.get()), rhs (expr.rhs.get())
    {

    }
   std::unique_ptr<Expr> clone() const override {
        return std::make_unique<ExprMultiplication>(lhs->clone(), rhs->clone());
    }

        std::string to_smt_lib()const{
        return '(' +  + "*"  + lhs -> to_smt_lib() +  rhs -> to_smt_lib() + ')';
        }

    void accept_visitor(ExprVisitor& visitor) override {
        visitor.visit(*this);
    }

    bool has_aggregation() const override {
        return lhs->has_aggregation() || rhs->has_aggregation();
    }

    std::set<VarId> get_all_vars() const override {
        std::set<VarId> res = lhs->get_all_vars();
        auto rhs_vars = rhs->get_all_vars();
        res.insert(rhs_vars.begin(), rhs_vars.end());
        return res;
    }
};
} // namespace MQL
