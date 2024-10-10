#include "SMT_IR.h"
std::string App::to_string() const {
    std::string expr_operator;
    std::vector<std::string> para;

    for (const auto& expr: param){
        para.push_back(std::visit(ToStr{}, expr));
    }
    std::string parameters = boost::algorithm::join(para, " ");
    switch (op) {
    case SMT_ADD: return "( + " + parameters + " )";
    case SMT_SUB: return "( - " + parameters + " )";
    case SMT_MUL: return "( * " + parameters + " )";
    case SMT_AND: return "( and " + parameters + " )";
    case SMT_LE: return "( >= " + parameters + " )";
    case SMT_GE: return "( <= " + parameters + " )";
    case SMT_EQ: return "( = " + parameters + " )";
    case SMT_NEQ: return "( distinct " + parameters + " )";
    }
}

bool App::flat_add(App &app) {

   auto param = app.get_parameters();
   std::vector<SMT_AST> new_params;
   for (const auto& expression:param){
       if (std::holds_alternative<App>(expression)){
            auto app_expr = std::get<App>(expression);
            if (app_expr.is_add()){

            }
            else if (app_expr.is_sub()){

            }
       }
       // else the expression do not have to handle
       else{
           new_params.push_back(std::visit(GetMember{}, expression));
       }
   }
}