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

std::vector<std::string> query = {
    "Match (?x) =[DATA_TEST(:T2 {age > ?p AND age < ?p + 114154})/(:N1 {name == ?c})]=> (?y)  Return ?x",
    "Match (?x) =[DATA_TEST(:N1 {name == \"Wang\" })|(:N1 {?p > 0})]=>(?y) Return ?y",
    "Match (?x) =[DATA_TEST(:N1 {name == \"Wang\" })|(:N1 {?p > 0})+]=>(?y) Return ?p",
    "Match (?x) =[DATA_TEST(:N1 {name == \"Wang\" })|(:N1 {?p > 0})*]=>(?y) Return ?y",
    "Match (?x) =[DATA_TEST((:N1 {name == \"Wang\" })|(:N1 {?p > 0}))*]=>(?y) Return ?y",
    "Match (?x) =[DATA_TEST(:N1 {age *2 == ?q })|(:N1 {?p > 0})]=>(?y) Return ?y",
};


// std::string query =  "Match (?x :fuck {age : 20}) Return ?x";

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
int try_parser()
{
    QueryContext::_debug_print = print;
    QueryContext::set_query_ctx(new QueryContext());
    antlr4::MyErrorListener error_listener;
    for (auto&q : query)
    {
        auto plan = MQL::QueryParser::get_query_plan(q, &error_listener);
    
        std::cout<<*plan<< std::endl;
    }

    return 0;
}

int main(){
    try_parser();
    return 0;
}