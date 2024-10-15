#pragma once

#include <set>
#include <memory>
#include "query/query_context.h"
#include "query/parser/smt/ir/SMT_IR.h"
#include "query/rewriter/smt/rewrite_rules/smt_rewrite_rule.h"
#include "rewrite_rules/distribute_plus_mult.h"
#include "rewrite_rules/flat_mul.h"
#include "rewrite_rules/flat_plus.h"
#include "rewrite_rules/simplify_add.h"
#include "rewrite_rules/simplify_mul.h"
#include "rewrite_rules/normalize.h"




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
    class ExprRewriteRuleVisitor {

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
        void start_visit(App& expr){
            std::vector<App> temp_vec;
            temp_vec.push_back(expr);
            auto temp_expr_container = App(SMT_AND, temp_vec );
            visit(temp_expr_container);
            expr = temp_expr_container.param[0];
        }


        void visit(App& expr)             {
            for (auto& rule : rules) {
                for (auto& child : expr.param) {
                    if (rule->is_possible_to_regroup(child)) {
                        child = rule->regroup(child);
                        has_rewritten = true;
                    }
                }
            }
            for (auto& child : expr.param) {
                visit(child);
            }
        }
    };

    inline void normalize( App & expr){
        ExprRewriteRuleVisitor simplifier;
        std::cout << expr.to_string() << std::endl;

        simplifier.add_rule<DistributeMulIntoPlusLeft>();
        simplifier.add_rule<DistributeMulIntoPlusRight>();
        simplifier.add_rule<FlatPlus>();
        simplifier.add_rule<FlatMul>();
        simplifier.add_rule<SimplifyMUL>();
        simplifier.add_rule<SimplifyPlus>();
        simplifier.start_visit(expr);
        std::cout << expr.to_string() << std::endl;

        ExprRewriteRuleVisitor normalizer;
        normalizer.add_rule<Normalize>();
        normalizer.add_rule<SimplifyMUL>();
        normalizer.add_rule<SimplifyPlus>();
        normalizer.start_visit(expr);

    }

} // namespace SPARQL
