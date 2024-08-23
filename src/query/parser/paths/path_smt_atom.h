//
// Created by heli on 8/22/24.
//

//
// Created by lhy on 8/9/24.
//

#pragma  once
#include <boost/algorithm/string/join.hpp>
#include <sstream>
#include <algorithm>
#include <variant>
#include <vector>
#include "graph_models/quad_model/quad_object_id.h"
#include "query/var_id.h"
#include "query/parser/paths/regular_path_expr.h"
#include "query/parser/expr/mql/bool_expr/expr_and.h"
#include "query/parser/expr/sparql/binary/expr_and.h"
#include "query/parser/expr/mql_expr_printer.h"
#include "query/parser/expr/sparql_expr_printer.h"

using object_atom = std::variant<std::monostate,std::string, ObjectId>;
// using formula = std::variant<std::monostate, std::unique_ptr<MQL::ExprAnd>, std::unique_ptr<SPARQL::ExprAnd>>;
using Formula = std::unique_ptr<MQL::ExprAnd>;
class SMTAtom: public RegularPathExpr{
public:
    object_atom atom;
    bool inverse;
    Formula property_checks;

    SMTAtom(object_atom atom, bool inverse,
              Formula  property_checks) :
         atom    (atom),
         inverse (inverse),
         property_checks (std::move(property_checks)) {
    }

    SMTAtom(const SMTAtom& other) :
        atom    (other.atom),
        inverse (other.inverse),
        property_checks(std::make_unique<MQL::ExprAnd>(std::move(other.property_checks.get() -> and_list)) )
         {

    }


    std::unique_ptr<RegularPathExpr> clone() const override {

        return std::make_unique<SMTAtom>(atom, inverse, std::make_unique<MQL::ExprAnd>(std::move(property_checks.get() -> and_list)));
    }

    PathType type() const override {
        return PathType::SMT_ATOM;
    }
    bool nullable() const override {
        return false;
    }

    RPQ_NFA get_rpq_base_automaton() const override {
        // Create a simple automaton
        auto automaton = RPQ_NFA();
        automaton.end_states.insert(1);
        // Connect states with atom as label
        // automaton.add_transition(RPQ_NFA::Transition(0, 1, &atom, inverse));
        return automaton;
    }

    RDPQAutomaton get_rdpq_base_automaton() const override {
        // Create a simple automaton
        auto automaton = RDPQAutomaton();

        //        // Empty data check first (D-state)
        //        automaton.add_transition(RDPQTransition::make_data_transition(0, 1));
        //
        //        // Add edge transition (E-state)
        //        auto data_checks = std::vector<property>();
        //        for (auto& property: property_checks) {
        //            data_checks.push_back(property);
        //        }
        //        std::sort(data_checks.begin(), data_checks.end());
        //        data_checks.erase(unique(data_checks.begin(), data_checks.end()), data_checks.end());
        //        automaton.add_transition(RDPQTransition::make_edge_transition(1, 2, inverse, atom, std::move(data_checks)));
        //
        //        // Add another empty data check (D-state)
        //        automaton.end_states.insert(3);
        //        automaton.add_transition(RDPQTransition::make_data_transition(2, 3));
        return automaton;
    }
    std::unique_ptr<RegularPathExpr> invert() const override {

        return std::make_unique<SMTAtom>(atom, !inverse, std::make_unique<MQL::ExprAnd>(std::move(property_checks.get() -> and_list)));
    }

     std::string to_string() const override {
             std::vector<std::string> f;
             std::stringstream sstream;

              MQL::ExprPrinter printer(sstream);

              printer.visit(*property_checks);


             std::string property_string = sstream.str();
             f.push_back(property_string);

         std::string property = boost::algorithm::join(f, "&&");
         std::string atom_string = "";
         if (std::holds_alternative<std::monostate>(atom))
         {
             atom_string = "";
         }
        else if (std::holds_alternative<std::string>(atom))
        {
            atom_string = std::get<std::string>(atom);
        }
        else if (std::holds_alternative<ObjectId>(atom))
        {
            auto atomic = std::get<ObjectId>(atom);
            atom_string = std::to_string(atomic.get_value());
        }
         if (inverse) {
             return "^:" + atom_string  + "," + property;
         }
         return ":" + atom_string + "," +  property;
    }
     std::ostream& print_to_ostream(std::ostream& os, int indent = 0) const override {
       os << std::string(indent, ' ');
       os << "OpSMTAtom(" <<this -> to_string()<<")\n";
     return os;
    }
};











