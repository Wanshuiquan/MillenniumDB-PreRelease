//
// Created by heli on 8/25/24.
//
#include "query/query_context.h"
#include "query/parser/smt/smt_expr.h"
#ifndef EXPR_IDENTIFIER_H
#define EXPR_IDENTIFIER_H
namespace SMT {
    class ExprAttr : public Expr {
    public:
        VarId var;

        ExprAttr(VarId var) :
            var (var) { }
        ExprAttr(ExprAttr& expr) :var(expr.var) { }
        std::unique_ptr<Expr> clone() const override {
            return std::make_unique<ExprAttr>(var);
        }

        void accept_visitor(ExprVisitor& visitor) override {
            visitor.visit(*this);
        }

        bool has_aggregation() const override { return false; }
        
        std::string to_smt_lib()const{
            std::string v =  get_query_ctx().get_var_name(var);
            return v.erase(0,2);
        }
        std::set<VarId> get_all_vars() const override {
            return { var };
        }
    };
}
#endif //EXPR_IDENTIFIER_H
