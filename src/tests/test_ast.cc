//
// Created by lhy on 8/5/24.
//

#include "query/parser/mql_query_parser.h"
#include "query/parser/grammar/error_listener.h"
#include "query/query_context.h"


#include <iostream>
#include <string>
#include<vector>
#include "z3++.h"

std::string query =  "Match (?x) =[:T2]=> (?y) WHERE ?y.start > 20 Return ?x";
int verify_z3_expression(){
    std::cout << "de-Morgan example\n";

    z3::context c;

    z3::expr x = c.bool_const("x");
    z3::expr y = c.bool_const("y");
    z3::expr conjecture = (!(x && y)) == (!x || !y);

    z3::solver s(c);
    // adding the negation of the conjecture as a constraint.
    s.add(!conjecture);
    std::cout << s << "\n";
    std::cout << s.to_smt2() << "\n";
    switch (s.check()) {
        case z3::unsat:   std::cout << "de-Morgan is valid\n"; break;
        case z3::sat:     std::cout << "de-Morgan is not valid\n"; break;
        case z3::unknown: std::cout << "unknown\n"; break;
    }
    return 0;
}

std::ostream& print(std::ostream& os, ObjectId oid){
    os<<oid.get_value();
    return os;
}
int try_parser(){
    QueryContext::_debug_print = print;
    QueryContext::set_query_ctx(new QueryContext());
    antlr4::MyErrorListener error_listener;
    auto plan = MQL::QueryParser::get_query_plan(query, &error_listener);
    
    std::cout<<*plan<< std::endl;
    return 0;
}

int main(){
    try_parser();
    return 0;
}