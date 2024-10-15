//
// Created by heli on 8/24/24.
//

#ifndef SMT_EXPR_PRINTER_H
#define SMT_EXPR_PRINTER_H
#include "smt_expr.h"
#include "query/parser/smt/smt_expr_visitor.h"

namespace SMT{

    class SmtPrinter : public ExprVisitor {
    public:
        std::ostream& os;
        SmtPrinter(std::ostream& os) : os(os) {}
        ~SmtPrinter() {}
        virtual void visit(SMT::ExprApp&) override;
        virtual void visit(SMT::ExprVar&)             override;
        virtual void visit(SMT::ExprConstant&)        override;

        virtual void visit(SMT::ExprAnd&)             override;
        virtual void visit(SMT::ExprAttr&) override;

    };
}


#endif //SMT_EXPR_PRINTER_H
