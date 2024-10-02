//
// Created by lhy on 10/2/24.
//

#ifndef MILLENNIUMDB_NORMALIZE_H
#define MILLENNIUMDB_NORMALIZE_H
#pragma  once
#include "query/parser/smt/smt_exprs.h"
#include "query/parser/smt/smt_expr_visitor.h"
namespace  SMT {
    class Normalize: ExprVisitor {

        void visit(SMT::ExprVar&)             override;
        void visit(SMT::ExprConstant&)        override;
        void visit(SMT::ExprAddition&)        override;
        void visit(SMT::ExprSubtraction&)     override;
        void visit(SMT::ExprMultiplication&)  override;
        void visit(SMT::ExprEquals&)          override;
        void visit(SMT::ExprGreaterOrEquals&) override;
        void visit(SMT::ExprGreater&)         override;
        void visit(SMT::ExprLessOrEquals&)    override;
        void visit(SMT::ExprLess&)            override;
        void visit(SMT::ExprNotEquals&)       override;
        void visit(SMT::ExprAnd&)             override;
        void visit(SMT::ExprAttr&)            override;



        void visit(SMT::ExprVarProperty&)     { throw LogicException("visit SMT::ExprVarProperty not implemented");}
        void visit(SMT::ExprUnaryMinus&)      { throw LogicException("visit SMT::ExprUnaryMinus not implemented"); }
        void visit(SMT::ExprUnaryPlus&)       { throw LogicException("visit SMT::ExprUnaryPlus not implemented"); }
        void visit(SMT::ExprDivision&)        { throw LogicException("visit SMT::ExprDivision not implemented"); }

    };

    class VarToLeft:ExprVisitor{
    private:
        std::unique_ptr<SMT::Expr> curr_expr;
        std::unique_ptr<SMT::Expr> curr_lhs;
        std::unique_ptr<SMT::Expr> curr_rhs;
    public:
        void visit(SMT::ExprVar&)             override;
        void visit(SMT::ExprConstant&)        override;
        void visit(SMT::ExprAddition&)        override;
        void visit(SMT::ExprSubtraction&)     override;
        void visit(SMT::ExprMultiplication&)  override;
        void visit(SMT::ExprEquals&)          override;
        void visit(SMT::ExprGreaterOrEquals&) override;
        void visit(SMT::ExprGreater&)         override;
        void visit(SMT::ExprLessOrEquals&)    override;
        void visit(SMT::ExprLess&)            override;
        void visit(SMT::ExprNotEquals&)       override;
        void visit(SMT::ExprAnd&)             override;
        void visit(SMT::ExprAttr&)            override;


        void visit(SMT::ExprVarProperty&)      { throw LogicException("visit SMT::ExprVarProperty not implemented"); }
        void visit(SMT::ExprUnaryMinus&)      { throw LogicException("visit SMT::ExprUnaryMinus not implemented"); }
        void visit(SMT::ExprUnaryPlus&)       { throw LogicException("visit SMT::ExprUnaryPlus not implemented"); }
        void visit(SMT::ExprDivision&)        { throw LogicException("visit SMT::ExprDivision not implemented"); }
    };

    class AttrToRight:ExprVisitor{
    private:
        std::unique_ptr<SMT::Expr> curr_expr;
        std::unique_ptr<SMT::Expr> curr_lhs;
        std::unique_ptr<SMT::Expr> curr_rhs;
    public:
        void visit(SMT::ExprVar&)             override;
        void visit(SMT::ExprConstant&)        override;
        void visit(SMT::ExprAddition&)        override;
        void visit(SMT::ExprSubtraction&)     override;
        void visit(SMT::ExprMultiplication&)  override;
        void visit(SMT::ExprEquals&)          override;
        void visit(SMT::ExprGreaterOrEquals&) override;
        void visit(SMT::ExprGreater&)         override;
        void visit(SMT::ExprLessOrEquals&)    override;
        void visit(SMT::ExprLess&)            override;
        void visit(SMT::ExprNotEquals&)       override;
        void visit(SMT::ExprAnd&)             override;
        void visit(SMT::ExprAttr&)            override;

        void visit(SMT::ExprVarProperty&)      { throw LogicException("visit SMT::ExprVarProperty not implemented"); }
        void visit(SMT::ExprUnaryMinus&)      { throw LogicException("visit SMT::ExprUnaryMinus not implemented"); }
        void visit(SMT::ExprUnaryPlus&)       { throw LogicException("visit SMT::ExprUnaryPlus not implemented"); }
        void visit(SMT::ExprDivision&)        { throw LogicException("visit SMT::ExprDivision not implemented"); }
    };
}

#endif //MILLENNIUMDB_NORMALIZE_H
