//
// Created by lhy on 9/6/24.
//
#include "query/executor/binding_iter/paths/data_test/smt_operations.h"

int main(){
    auto context = SMTContext();
    context.add_obj_var("i");
    context.add_obj_var("j");

    auto f = context.parse("(assert(>= i (+ j 0.000)))")[0];
    auto f1 = context.subsitute_obj("i", 22, f);
    std::cout<< context.normalizition(f1);

}