#include "smt_rewrite_rule.h"
namespace SMT {

    class Normalize : public ExprRewriteRule {
    private:
        void invert(App& expr){
            std::vector<App> new_para;
            new_para.emplace_back(SMTOp::SMT_VAL, "-1");
            if (expr.param.empty()){
                if (expr.is_var()){
                    new_para.emplace_back(SMTOp::SMT_PARA, expr.var.value());
                }
                else if (expr.is_val()){
                    new_para.emplace_back(SMTOp::SMT_VAL, expr.val.value());
                }
                else if (expr.is_attr()){
                    new_para.emplace_back(SMTOp::SMT_ATTR, expr.attr.value());
                }
            } else {
                std::for_each(expr.param.begin(), expr.param.end(), [&new_para](App &a) { new_para.push_back(a); });
            }
            expr.op = SMTOp::SMT_MUL;
            expr.param.clear();
            expr.param.swap(new_para);
        }


    public:
        bool is_possible_to_regroup(App& unknown_expr) override {
            if  (! (unknown_expr.is_eq() || unknown_expr.is_neq() || unknown_expr.is_ge() || unknown_expr.is_le()) ){
                return false;
            }
            else if (unknown_expr.to_string().find('\"') != std::string::npos ){
                return false;
            }
            else{
                return (! unknown_expr.param[1].get_all_vars().empty()) || (!unknown_expr.param[0].get_all_attributes().empty());
            }

        }

        App& regroup(App& expr) override {
            std::vector<App> new_lhs;
            std::vector<App> new_rhs;
            // reshuffle the lhs
            auto lhs = expr.param[0];
            if (lhs.is_val()) {
                new_lhs.push_back(lhs);
            }
            else if (lhs.is_var()) {
                new_lhs.push_back(lhs);
            }
            else if (lhs.is_attr()){
                invert(lhs);
                new_rhs.push_back(lhs);
            }
            else if (lhs.is_mul()){
                if (lhs.get_all_attributes().empty()) {
                    new_lhs.push_back(lhs);
                }
                else {
                    invert(lhs);
                    new_rhs.push_back(lhs);
                }
            }
            else{
                // lhs is add formula
                for (auto & e : lhs.param){

                    if (!e.get_all_attributes().empty()){
                        invert(e);
                        new_rhs.push_back(e);
                    }else{
                        new_lhs.push_back(e);
                    }
                }
            }

            // reshuffle ths rhs
            auto rhs = expr.param[1];
            if (rhs.is_val()) {
                new_rhs.push_back(rhs);
            }
            else if (rhs.is_var()) {
                invert(rhs);
                new_lhs.push_back(rhs);
            }
            else if (rhs.is_mul()){
                if (rhs.get_all_vars().empty()) {
                    new_rhs.push_back(rhs);
                }
                else {

                    invert(rhs);
                    new_lhs.push_back(rhs);
                }
            }
            else {
                for (auto &e: rhs.param) {
                    if (!e.get_all_vars().empty()) {
                        invert(e);
                        new_lhs.push_back(e);
                    } else {
                        new_rhs.push_back(e);
                    }
                }
            }
            // set lhs
            expr.param[0].param.clear();

            if (new_lhs.size() == 1){
                if (new_lhs[0].is_val()) {
                    expr.param[0].val.swap(new_lhs[0].val);
                    expr.param[0].op = SMTOp::SMT_VAL;
                }else if (new_lhs[0].is_var()){
                    expr.param[0].var.swap(new_lhs[0].var);
                    expr.param[0].op = SMTOp::SMT_PARA;
                } else if (new_lhs[0].is_mul()){
                    // flat the multiplication
                    expr.param[0].param.swap(new_lhs[0].param);
                    expr.param[0].op = SMTOp::SMT_MUL;

                }
            }
            else if (new_lhs.empty()){
                expr.param[0].param.swap(new_lhs);
                expr.param[0].val = "0";
                expr.param[0].op = SMTOp::SMT_VAL;
            }
            else {
                expr.param[0].param.swap(new_lhs);
                expr.param[0].op = SMTOp::SMT_ADD;
            }

            // new rhs
            expr.param[1].param.clear();

            if (new_rhs.size() == 1){
                if (new_rhs[0].is_val()) {
                    expr.param[1].val.swap(new_rhs[0].val);
                    expr.param[1].op = SMTOp::SMT_VAL;
                }else if (new_rhs[0].is_var()){
                    expr.param[1].var.swap(new_rhs[0].var);
                    expr.param[1].op = SMTOp::SMT_PARA;
                } else if (new_rhs[0].is_mul()){
                    // flat the multiplication
                    expr.param[1].param.swap(new_rhs[0].param);
                    expr.param[1].op = SMTOp::SMT_MUL;

                }
            } else if (new_rhs.empty()){
                expr.param[1].param.swap(new_rhs);
                expr.param[1].val = "0";
                expr.param[1].op = SMTOp::SMT_VAL;
            }
            else {
                expr.param[1].param.swap(new_rhs);
                expr.param[1].op = SMTOp::SMT_ADD;
            }
            return expr;
        }

    };


} // namespace SPARQL