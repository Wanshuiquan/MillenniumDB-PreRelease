#pragma once

#include <memory>

#include "graph_models/rdf_model/conversions.h"
#include "query/executor/binding_iter/binding_expr/binding_expr.h"

namespace SPARQL {
class BindingExprSeconds : public BindingExpr {
public:
    std::unique_ptr<BindingExpr> expr;

    BindingExprSeconds(std::unique_ptr<BindingExpr> expr) :
        expr (std::move(expr)) { }

    ObjectId eval(const Binding& binding) override {
        auto expr_oid = expr->eval(binding);

        switch(RDF_OID::get_generic_sub_type(expr_oid)) {
        case RDF_OID::GenericSubType::DATE: {
            bool error;
            auto res = DateTime(expr_oid).get_second(&error);
            if (error) {
                return ObjectId::get_null();
            }
            return Conversions::pack_decimal(Decimal(res));
        }
        default:
            return ObjectId::get_null();
        }
    }

    void accept_visitor(BindingExprVisitor& visitor) override {
        visitor.visit(*this);
    }
};
} // namespace SPARQL