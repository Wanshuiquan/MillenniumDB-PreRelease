//
// Created by heli on 8/23/24.
//
#pragma once

#include <set>
#include <memory>
#include <ostream>

#include "query/var_id.h"
#include "query/parser/smt/smt_expr_visitor.h"

namespace SMT {
class Expr {
public:
    virtual ~Expr() = default;
    Expr& operator=(const Expr&)  = default;
    virtual std::unique_ptr<Expr> clone() const = 0;

    virtual void accept_visitor(ExprVisitor&) = 0;

    virtual std::set<VarId> get_all_vars() const = 0;
    virtual std::string to_smt_lib()  const =  0; 

    virtual bool has_aggregation() const = 0;
};
}