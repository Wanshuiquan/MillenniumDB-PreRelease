//
// Created by lhy on 10/9/24.
//

#ifndef MILLENNIUMDB_SMT_REWRITE_RULE_H
#define MILLENNIUMDB_SMT_REWRITE_RULE_H
#pragma once

#include <set>
#include <memory>

#include "query/parser/smt/ir/SMT_IR.h"
#include "query/rewriter/smt/rewrite_basic.h"
namespace SMT {
    /**
     * The abstract class for writing a rewrite rule. It can be assumed
     * that is_possible_to_regroup will always be called before regroup.
     */
    class ExprRewriteRule {

    public:
        virtual ~ExprRewriteRule() = default;

        virtual bool is_possible_to_regroup(App &) = 0;
        virtual App& regroup(App&) = 0;


    };
} // namespace SPARQL

#endif //MILLENNIUMDB_SMT_REWRITE_RULE_H
