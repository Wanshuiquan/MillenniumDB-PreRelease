//
// Created by lhy on 10/8/24.
//

#ifndef MILLENNIUMDB_SMT_IR_H
#define MILLENNIUMDB_SMT_IR_H
#pragma once
#include "query/parser/smt/smt_exprs.h"
#
#include "boost/algorithm/string.hpp"
enum SMTOp{
    SMT_ADD,
    SMT_MUL,
    SMT_SUB,
    SMT_LE,
    SMT_GE,
    SMT_AND,
    SMT_EQ,
    SMT_NEQ,
};

class Var{
     VarId id;
public:
     std::string to_string() const {
         return get_query_ctx().get_var_name(id);
     }
};

class Value{
    std::string value;
public:
    std::string to_string() const {
        return value;
    }
};

class Attribute  {
    ObjectId var;
    std::string name;
public:
    std::string to_string() const {
        return name;
    }
};


class App{
private:
    SMTOp op;
    std::vector<std::variant<Value, Var, App>> param;
public:

    std::string to_string() const;

    bool is_add() const{
             return op == SMTOp::SMT_ADD;
         }
    bool is_sub() const{
        return op == SMTOp::SMT_SUB;
    }
    bool is_mul() const{
        return op == SMTOp::SMT_MUL;
    }
    bool is_eq() const{
        return op == SMTOp::SMT_EQ;
    }
    bool is_neq() const{
        return op == SMTOp::SMT_NEQ;
    }
    bool is_ge() const{
        return op == SMTOp::SMT_GE;
    }
    bool is_le() const{
        return op == SMTOp::SMT_LE;
    }
    bool is_and() const{
        return op == SMTOp::SMT_SUB;
    }

    std::vector<std::variant<Value, Var, App>> get_parameters(){
        return std::move(param);
    }


    static bool flat_add(App& app);
    static bool push_mul(App& app);

};
using SMT_AST = std::variant<Value, Attribute, App, Var>;
struct ToStr {
    std::string operator()(const Value& val) { return val.to_string();}
    std::string operator()(const Var& var) {return var.to_string();  }
    std::string operator()(const Attribute& attr) {return attr.to_string();  }
    std::string operator()(const App& app) {return app.to_string();}
};

struct GetMember {
    SMT_AST operator()(const Value& val) { return val;}
    SMT_AST operator()(const Var& var) {return var; }
    SMT_AST  operator()(const App& app) {return app;}
    SMT_AST  operator()(const Attribute&attr){return attr; }
};
#endif //MILLENNIUMDB_SMT_IR_H
