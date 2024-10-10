#include "smt_rewrite_rule.h"
namespace SMT {

    class Normalize : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(std::unique_ptr<Expr>& unknown_expr) override {
            if  (! is_compare(unknown_expr)){
                return false;
            }
            else{
                auto compare_expr = dynamic_cast<ExprApp*>(unknown_expr.get());
                return compare_expr->rhs->get_all_vars().empty() && compare_expr -> lhs -> get_all_attrs().empty();
            }

        }

        std::unique_ptr<Expr> regroup(std::unique_ptr<Expr> unknown_expr) override {
            auto compare_expr = dynamic_cast<ExprApp*>(unknown_expr.get());

        }

    };


} // namespace SPARQL