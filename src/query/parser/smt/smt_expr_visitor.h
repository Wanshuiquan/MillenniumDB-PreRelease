//
// Created by heli on 8/23/24.
//

#pragma once

#include "query/exceptions.h"

namespace SMT {
class ExprVar;
class ExprConstant;

class ExprAttr;
class ExprAnd;
class ExprApp;




class ExprVisitor {
public:
    virtual ~ExprVisitor() = default;
    virtual void visit(SMT::ExprVar&)             { throw LogicException("visit SMT::ExprVar not implemented"); }
    virtual void visit(SMT::ExprConstant&)        { throw LogicException("visit SMT::ExprConstant not implemented"); }
    virtual void visit(SMT::ExprApp&)             { throw LogicException("visit SMT::ExprAnd not implemented"); }
    virtual void visit(SMT::ExprAnd&)             { throw LogicException("visit SMT::ExprAnd not implemented"); }
    virtual void visit(SMT::ExprAttr&)            { throw LogicException("visit SMT::ExprAttr not implemented");}
};
}