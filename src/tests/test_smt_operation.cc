//
// Created by lhy on 9/6/24.
//
#include "query/parser/smt/smt_exprs.h"
#include "query/rewriter/smt/to_ir.h"
#include "query/rewriter/smt/smt_rewrite_rule_visitor.h"

#include "graph_models/quad_model/quad_object_id.h"
using namespace SMT;
std::ostream& print(std::ostream& os, ObjectId oid){
    os<<oid.get_value();
    return os;
}
int main(){
    QueryContext::_debug_print = print;
    QueryContext::set_query_ctx(new QueryContext());
//    auto expr1 = std::make_unique<ExprApp>(
//            Operator::OP_LE,
//            std::make_unique<ExprConstant>(QuadObjectId::get_value("2")),
//                                   std::make_unique<ExprApp>(Operator::OP_SUB,
//                                      std::make_unique<ExprConstant>(QuadObjectId::get_value("1")),
//                                      std::make_unique<ExprVar>(get_query_ctx().get_or_create_var("x"))));
//
//
//    auto expr2 = std::make_unique<ExprApp>(
//            Operator::OP_LE,
//            std::make_unique<ExprConstant>(QuadObjectId::get_value("2")),
//            std::make_unique<ExprApp>(Operator::OP_MUL,
//                                      std::make_unique<ExprConstant>(QuadObjectId::get_value("1")),
//                                      std::make_unique<ExprVar>(get_query_ctx().get_or_create_var("x"))));
    auto expr3 = std::make_unique<ExprApp>(
            Operator::OP_LE,
            std::make_unique<ExprApp>(Operator::OP_MUL,
                                      std::make_unique<ExprConstant>(QuadObjectId::get_value("2")),
                                      std::make_unique<ExprApp>(Operator::OP_ADD,
                                                                std::make_unique<ExprConstant>(QuadObjectId::get_value("1")),
                                                                std::make_unique<ExprAttr>(QuadObjectId::get_string("age"), "age"))),
            std::make_unique<ExprApp>(Operator::OP_MUL,
                                      std::make_unique<ExprConstant>(QuadObjectId::get_value("2")),
                                      std::make_unique<ExprApp>(Operator::OP_ADD,
                                                                std::make_unique<ExprConstant>(QuadObjectId::get_value("1")),
                                                                std::make_unique<ExprVar>(get_query_ctx().get_or_create_var("x"))))

                                                                );
    auto rewriter = ToIR();
    expr3->accept_visitor(rewriter);
    auto ir = rewriter.to_ir();
    normalize(ir);
    std::cout << ir.to_string() << std::endl;

}