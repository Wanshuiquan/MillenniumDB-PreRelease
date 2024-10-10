#pragma once

#include <set>
#include <memory>
#include "query/query_context.h"
#include "query/parser/smt/smt_expr_visitor.h"
#include "query/parser/smt/smt_exprs.h"
#include "query/rewriter/smt/rewrite_rules/smt_rewrite_rule.h"

namespace SMT {
    /**
     * This visitor uses a rewrite rule that implements
     * is_possible_to_regroup and regroup and uses these
     * functions to implement the rule. The visitor checks
     * every rule in rules at each position sequentially,
     * if the idea is to do the rewrite rules one at a time
     * without this logic, it is necessary to pass the visitors
     * one after the other. The visitor only passes once,
     * to pass multiple times the bool value has_rewritten
     * is checked with reset_and_check_if_has_rewritten_a_rule
     */
    class ExprRewriteRuleVisitor : public ExprVisitor {

    private:
        std::vector<std::unique_ptr<ExprRewriteRule>> rules;
        bool has_rewritten = false;
        // bool has_rewritten_father = false;

    public:
        template <typename Rule>
        void add_rule() {
            rules.push_back(std::make_unique<Rule>());
        }

        void remove_rules() {
            rules.clear();
        }

        bool reset_and_check_if_has_rewritten_a_rule() {
            auto out = has_rewritten;
            has_rewritten = false;
            return out;
        }

        /************************************************************************
         * It is necessary to always start visitation from start_visit, because *
         * that way the first expr container is modified.\ Not is used because  *
         * it only contains an expr, it is removed after this visitation.       *
         ************************************************************************/
        void start_visit(std::unique_ptr<Expr>& expr) {
            std::vector<std::unique_ptr<Expr>> tmp_vec;
            tmp_vec.push_back(std::move(expr));
            auto temp_expr_container = std::make_unique<ExprAnd>(std::move(tmp_vec));
            temp_expr_container->accept_visitor(*this);
            expr = std::move(temp_expr_container->and_list[0]);
        }

        void visit(SMT::ExprVar&)             {}
        void visit(SMT::ExprVarProperty&)     {}
        void visit(SMT::ExprConstant&)        {}
        void visit(SMT::ExprAttr&)            {}

        void visit(SMT::ExprApp& expr)             {
            visit_expr_with_lhs_and_rhs(expr);
        }
        void visit(SMT::ExprAnd& expr)             {
            for (auto& rule : rules) {
                for (auto& child : expr.and_list) {
                    if (rule->is_possible_to_regroup(child)) {
                        child = rule->regroup(std::move(child));
                        has_rewritten = true;
                    }
                }
            }
            for (auto& child : expr.and_list) {
                if (child != nullptr) {
                    child->accept_visitor(*this);
                }
            }}


    private:
        template <typename T>
        void visit_lhs(T& expr) {
            for (auto& rule : rules) {
                if (rule->is_possible_to_regroup(expr.lhs)) {
                    expr.lhs = rule->regroup(std::move(expr.lhs));
                    has_rewritten = true;
                }
            }
            if (expr.lhs != nullptr)
                expr.lhs->accept_visitor(*this);
        }

        template <typename T>
        void visit_rhs(T& expr) {
            for (auto& rule : rules) {
                if (rule->is_possible_to_regroup(expr.rhs)) {
                    expr.rhs = rule->regroup(std::move(expr.rhs));
                    has_rewritten = true;
                }
            }
            if (expr.rhs != nullptr)
                expr.rhs->accept_visitor(*this);
        }

        template <typename T>
        void visit_expr_with_lhs_and_rhs(T& expr) {
            visit_lhs<T>(expr);
            visit_rhs<T>(expr);
        }




    };
} // namespace SPARQL
