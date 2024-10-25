//
// Created by lhy on 10/2/24.
//

#include "normalize.h"
using namespace SMT;
using namespace std;

void VarToLeft::visit(SMT::ExprAnd & expr) {
    for (auto& exp: expr.and_list){
        exp ->accept_visitor(*this);
    }
}

