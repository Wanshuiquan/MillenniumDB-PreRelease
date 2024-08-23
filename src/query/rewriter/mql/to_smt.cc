//
// Created by heli on 8/23/24.
//
#include "to_smt.h"
#include "query/parser/expr/mql_exprs.h"

using namespace MQL;
void ToSMT::visit(ExprConstant& expr) {
  current_smt_expr =  std::make_unique<SMT::ExprConstant>(expr.value);
}

void ToSMT::visit(ExprVar& expr){
  current_smt_expr =  std::make_unique<SMT::ExprVar>(expr.var);
}
void ToSMT::visit(ExprVarProperty& expr){
  current_smt_expr = std::make_unique<SMT::ExprVarProperty>(expr.var_without_property, expr.key, expr.var_with_property);
}
void ToSMT::visit(ExprAddition& expr) {
  auto lhs =  expr.lhs.get();
  lhs->accept_visitor(*this);
  auto l = std::move(current_smt_expr);
  auto rhs =  expr.rhs.get();
  rhs ->accept_visitor(*this);
  auto r = std::move(current_smt_expr);
  current_smt_expr = std::make_unique<SMT::ExprAddition>(std::move(l), std::move(r));
}

void visit(ExprMultiplication&) override;
void visit(ExprSubtraction&) override;
void visit(ExprUnaryMinus&) override;
void visit(ExprUnaryPlus&) override;
void visit(ExprEquals&) override;
void visit(ExprGreaterOrEquals&) override;
void visit(ExprGreater&) override;
void visit(ExprIs&) override;
void visit(ExprLessOrEquals&) override;
void visit(ExprLess&) override;
void visit(ExprNotEquals&) override;
void visit(ExprAnd&) override;