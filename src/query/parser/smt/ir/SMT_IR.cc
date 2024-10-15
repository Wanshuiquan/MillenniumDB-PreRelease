#include "SMT_IR.h"
std::string App::to_string() const {
    std::string expr_operator;
    std::vector<std::string> para;

    for (const auto& expr: param){
        para.push_back(expr.to_string());
    }
    std::string parameters = boost::algorithm::join(para, " ");
    switch (op) {
    case SMT_ADD: return "( + " + parameters + " )";
    case SMT_SUB: return "( - " + parameters + " )";
    case SMT_MUL: return "( * " + parameters + " )";
    case SMT_AND: {
        if (param.size() == 1){
            return "( assert " + parameters+ ")";
        }
        else {
            return "( assert( and " + parameters + " ))";
        }
    }
    case SMT_LE: return "( <= " + parameters + " )";
    case SMT_GE: return "( >= " + parameters + " )";
    case SMT_EQ: return "( = " + parameters + " )";
    case SMT_NEQ: return "( distinct " + parameters + " )";
    case SMT_VAL: return val.value();
    case SMT_ATTR: return std::get<1>(attr.value());
    case SMT_PARA: return get_query_ctx().get_var_name(var.value());
    }
}


