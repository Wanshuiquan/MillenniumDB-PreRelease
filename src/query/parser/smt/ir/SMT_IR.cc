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

z3::expr App::to_z3_ast() const {
    std::string expr_operator;

    switch (op) {
        case SMT_ADD: {
            z3::expr res  = get_smt_ctx().add_real_val(1);
            for (const auto & ele:param){
                res = res + ele.to_z3_ast();
            }
            return res;
        };
        case SMT_MUL: {
            z3::expr res  = get_smt_ctx().add_real_val(1);
            for (const auto & ele:param){
                res = res * ele.to_z3_ast();
            }
            return res;
        };
        case SMT_AND: {
            if (param.size() == 1){
                return param[0].to_z3_ast();
            }
            else {
                    z3::expr res  = get_smt_ctx().add_bool_val(true);
                    for (const auto & ele:param){
                        res = res && ele.to_z3_ast();
                    }
                    return res;

            }
        }

        case SMT_VAL: return get_smt_ctx().add_real_val(std::stod(val.value()));
        case SMT_PARA: {
            auto name = get_query_ctx().get_var_name(var.value());
            get_smt_ctx().add_real_var(name);
            return get_smt_ctx().get_var(name);
        }
        default:
            return get_smt_ctx().add_bool_val(true);
        }
    }


