//
// Created by lhy on 9/6/24.
//
#include "query/executor/binding_iter/paths/data_test/smt_operations.h"

int main(){
    auto context = SMTContext();
    context.add_obj_var("i");
    context.add_obj_var("j");

    auto vec = context.parse("(assert  (and (>= j 1) (>= i (+ j 0.012))))");
    auto vec1 = context.parse("(assert   (>= i (+ j 0.000)))");

    for (const z3::expr& formula:  vec){
        auto f1 = context.subsitute_obj("i", 22, formula);
        auto normal_form =  context.normalizition(f1);
        auto bound = context.get_bound(normal_form);
        context.print_bound(bound, std::cout);
    }

}