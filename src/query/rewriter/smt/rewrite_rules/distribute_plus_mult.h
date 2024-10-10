#include "smt_rewrite_rule.h"
namespace SMT {
/**
 * E1 OR (E2 AND E3) = (E1 OR E2) AND (E1 OR E3)
 */
    class DistributeMulIntoPlusLeft : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(std::unique_ptr<Expr>& unknown_expr) override {
            if (!is_mul(unknown_expr)) {
                return false;
            }
            auto plus_expr = dynamic_cast<ExprApp*>(unknown_expr.get());
            return (is_add(plus_expr ->rhs));
        }

        std::unique_ptr<Expr> regroup(std::unique_ptr<Expr> unknown_expr) override {
            auto plus_expr = dynamic_cast<ExprApp*>(unknown_expr.get());
            auto mul_expr = dynamic_cast<ExprApp*>(plus_expr->rhs.get());
            return std::make_unique<ExprApp>(
                    Operator::OP_ADD,
                    std::make_unique<ExprApp>(
                            Operator::OP_MUL,
                            plus_expr->lhs->clone(),
                            std::move(mul_expr->lhs)
                    ),
                    std::make_unique<ExprApp>(
                            Operator::OP_MUL,
                            plus_expr->lhs->clone(), // less error prone to clone
                            std::move(mul_expr->rhs)
                    )
            );
        }
    };

    class DistributeMulIntoPlusRight : public ExprRewriteRule {
    public:
        bool is_possible_to_regroup(std::unique_ptr<Expr>& unknown_expr) override {
            if (!is_mul(unknown_expr)) {
                return false;
            }
            auto plus_expr = dynamic_cast<ExprApp*>(unknown_expr.get());
            return (is_add(plus_expr ->lhs));
        }

        std::unique_ptr<Expr> regroup(std::unique_ptr<Expr> unknown_expr) override {
            auto plus_expr = dynamic_cast<ExprApp*>(unknown_expr.get());
            auto mul_expr = dynamic_cast<ExprApp*>(plus_expr->lhs.get());
            return std::make_unique<ExprApp>(
                    Operator::OP_ADD,
                    std::make_unique<ExprApp>(
                            Operator::OP_MUL,
                            plus_expr->rhs->clone(),
                            std::move(mul_expr->lhs)
                    ),
                    std::make_unique<ExprApp>(
                            Operator::OP_MUL,
                            plus_expr->rhs->clone(), // less error prone to clone
                            std::move(mul_expr->rhs)
                    )
            );
        }
    };
} // namespace SPARQL