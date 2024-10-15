//
// Created by lhy on 10/11/24.
//

#ifndef MILLENNIUMDB_TO_IR_H
#define MILLENNIUMDB_TO_IR_H
#include "query/parser/smt/smt_expr_visitor.h"
#include "query/parser/smt/ir/SMT_IR.h"
#include "query/parser/smt/smt_exprs.h"
namespace SMT{

    class ToIR: public ExprVisitor{
    private:
        App current_expr = App(SMTOp::SMT_VAL, "");
    public:
        ToIR() {}
        void visit(SMT::ExprVar& expr){
           current_expr = App(SMTOp::SMT_PARA, expr.var);
        }
        void visit(SMT::ExprConstant& expr){
            current_expr = App(SMTOp::SMT_VAL, expr.to_string());
        }
        void visit(SMT::ExprAttr& expr){
            current_expr = App(SMTOp::SMT_ATTR, {expr.var, expr.name});
        }

        void visit(SMT::ExprApp& expr)             {
            SMTOp op;
            switch (expr.op) {
                case OP_GE: op = SMTOp::SMT_GE; break;
                case OP_LE: op = SMTOp::SMT_LE; break;
                case OP_EQ: op = SMTOp::SMT_EQ; break;
                case OP_NEQ: op = SMTOp::SMT_NEQ; break;
                case OP_ADD: op = SMTOp::SMT_ADD; break;
                case OP_SUB: op = SMTOp::SMT_SUB; break;
                case OP_MUL: op = SMTOp::SMT_MUL; break;
            }
            std::vector<App> param;
            expr.lhs ->accept_visitor(*this);
            param.emplace_back(current_expr);
            expr.rhs ->accept_visitor(*this);
            param.emplace_back(current_expr);
            current_expr = App(op, param);
        }
        void visit(SMT::ExprAnd& expr) {
            std::vector<App> param;
            for (const auto& ele : expr.and_list){
                ele ->accept_visitor(*this);
                param.emplace_back(current_expr);
            }
            current_expr = App(SMTOp::SMT_AND, param);
        }

        App& to_ir(){
            return current_expr;
        }
    };
}
#endif //MILLENNIUMDB_TO_IR_H
