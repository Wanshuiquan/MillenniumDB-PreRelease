#pragma once

#include "query/query_context.h"
#include "query/parser/smt/smt_expr.h"

namespace SMT {
class ExprVarProperty : public Expr {
public:
    VarId var_without_property; // ?x

    ObjectId key;

    VarId var_with_property; // ?x.key

    ExprVarProperty(VarId var_without_property, ObjectId key, VarId var_with_property) :
        var_without_property (var_without_property),
        key                  (key),
        var_with_property    (var_with_property) { }
    ExprVarProperty(ExprVarProperty& exp) : var_without_property(exp.var_without_property), key(exp.key), var_with_property(exp.var_with_property) { }
    std::unique_ptr<Expr> clone() const override {
        return std::make_unique<ExprVarProperty>(
            var_without_property,
            key,
            var_with_property
        );
    }

    void accept_visitor(ExprVisitor& visitor) override {
        visitor.visit(*this);
    }
//
    bool has_aggregation() const override { return false; }

    std::set<VarId> get_all_vars() const override {
        return { var_with_property };
    }
};
} // namespace MQL
