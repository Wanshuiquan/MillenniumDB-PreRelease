#pragma once

#include <set>
#include <memory>
#include <utility>
#include "query/query_context.h"
#include "query/parser/smt/ir/SMT_IR.h"
#include "query/rewriter/smt/rewrite_rules/smt_rewrite_rule.h"
#include "rewrite_rules/distribute_plus_mult.h"
#include "rewrite_rules/flat_mul.h"
#include "rewrite_rules/flat_plus.h"
#include "rewrite_rules/flat_and.h"

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
            visit(expr);
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
        ExprRewriteRuleVisitor andflater;
        andflater.add_rule<FlatAnd>();
        andflater.start_visit(expr);

        ExprRewriteRuleVisitor distributer;

        distributer.add_rule<DistributeMulIntoPlusLeft>();
        distributer.add_rule<DistributeMulIntoPlusRight>();
        distributer.add_rule<SimplifyMUL>();
        distributer.add_rule<SimplifyPlus>();
        distributer.start_visit(expr);

        ExprRewriteRuleVisitor flater;
        flater.add_rule<FlatPlus>();
        flater.add_rule<FlatMul>();
        flater.add_rule<SimplifyMUL>();
        flater.add_rule<SimplifyPlus>();
        flater.start_visit(expr);

        ExprRewriteRuleVisitor normalizer;
        flater.add_rule<FlatPlus>();
        flater.add_rule<FlatMul>();
        normalizer.add_rule<Normalize>();
        normalizer.add_rule<SimplifyMUL>();
        normalizer.add_rule<SimplifyPlus>();
        normalizer.start_visit(expr);
    }

    inline void substitute_one_attr(App& expr, std::tuple<std::string, ObjectId> attribute , double_t value ){
        auto is_op =  [](App & expr){return expr.is_le() || expr.is_ge() || expr.is_eq() || expr.is_neq() || expr.is_and() || expr.is_mul() || expr.is_add();};
        if (expr.is_attr()){
            std::string curr_attr = std::get<1>(expr.attr.value());
            std::string val_attr = std::get<0>(attribute);
            if (val_attr == curr_attr){
                expr.attr = std::nullopt;
                expr.op = SMTOp::SMT_VAL;
                expr.val = std::to_string(value);
                return;
            }
            else {
                return;
            }
        } else if (is_op(expr)){
            for (auto& ele: expr.param){
                substitute_one_attr(ele, attribute, value);
            }
        } else{
            return;
        }
    }

    inline void subsitute(App & expr, std::map<std::tuple<std::string, ObjectId> , double_t>  attribute){
        for (auto& ele: attribute){
            substitute_one_attr(expr,std::get<0>(ele), std::get<1>(ele));
        }
    }

    inline void subsitute_str(App & expr, std::map<std::tuple<std::string, ObjectId> , std::string>  attribute){
        if (! expr.is_attr()) return;
        for (auto& ele: attribute){
                        std::string curr_attr = std::get<1>(expr.attr.value());
                        std::string val_attr =   std::get<0>(ele.first);
                        if (val_attr == curr_attr){
                            expr.attr = std::nullopt;
                            expr.op = SMTOp::SMT_VAL;
                            expr.val = ele.second;
                            return;
                        }

                 }
        }

    inline void replace_first(
            std::string& s,
            std::string const& toReplace,
            std::string const& replaceWith
    ) {
        std::size_t pos = s.find(toReplace);
        if (pos == std::string::npos) return;
        s.replace(pos, toReplace.length(), replaceWith);
    }

    inline std::string eval_str(App& expr, std::map<std::tuple<std::string, ObjectId> , std::string> attribute){
            std::vector<App> ele(expr.param);
            App * temp = new App(expr.op, ele, expr.var, expr.val, expr.attr);
            subsitute_str(*temp, std::move(attribute));
            std::string val = temp->val.value();
            replace_first(val, "\"", "");
            replace_first(val, "\"", "");
            delete temp;
            return val;
    }

    inline std::string eval( App & expr){
        if(expr.is_val()){
            return expr.val.value();
        }else if (expr.is_mul()){
            double res = 1;
            std::for_each(expr.param.begin(), expr.param.end(), [&res](App& a){res = res * std::stod(eval(a));});
            return std::to_string(res);
        }else if (expr.is_add()){
            double res = 0;
            std::for_each(expr.param.begin(), expr.param.end(), [&res](App& a){res = res + std::stod(eval(a));});
            return std::to_string(res);
        }else{
            return "";
        }
    }


     inline std::string evaluate(App& expr, std::map<std::tuple<std::string, ObjectId> , double_t> attribute){

         std::vector<App> ele(expr.param);
         App * temp = new App(expr.op, ele, expr.var, expr.val, expr.attr);
         subsitute(*temp, std::move(attribute));

         std::string val = eval(*temp);

         delete temp;
         return val;
    }




} // namespace SPARQL
