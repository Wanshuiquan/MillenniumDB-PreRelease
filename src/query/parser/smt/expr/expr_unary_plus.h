#pragma once

#include "query/parser/smt/smt_expr.h"

namespace SMT {
class ExprUnaryPlus : public Expr {
public:
    std::unique_ptr<Expr> expr;

    ExprUnaryPlus(std::unique_ptr<Expr> expr) :
        expr (std::move(expr)) { }
    ExprUnaryPlus(const ExprUnaryPlus& expr) : expr (std::unique_ptr<SMT::Expr>(expr.expr.get())) { }
    std::unique_ptr<Expr> clone() const override {
        return std::make_unique<ExprUnaryPlus>(expr->clone());
    }

    void accept_visitor(ExprVisitor& visitor) override {
        visitor.visit(*this);
    }

    bool has_aggregation() const override {
        return expr->has_aggregation();
    }
    std::string to_smt_lib()const{throw std::runtime_error("Not Support");}

    std::set<VarId> get_all_vars() const override {
        return expr->get_all_vars();
    }
};
} // namespace MQL
