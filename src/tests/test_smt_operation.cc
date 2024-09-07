//
// Created by lhy on 9/6/24.
//
#include "query/executor/binding_iter/paths/data_test/smt_operations.h"

int main(){
    auto context = SMTContext();
    context.add_obj_var("i");
    auto f = context.parse("(assert(> i 1))")[0];
    auto f1 = context.subsitute_obj("i", 1, f);
    std::cout<< f1;

}