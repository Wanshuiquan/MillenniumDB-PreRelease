//
// Created by lhy on 9/2/24.
//
#include <cassert>

#include "bfs_check.h"

#include "query/var_id.h"
#include "query/executor/binding_iter/paths/path_manager.h"
#include "z3++.h"
using namespace std;
using namespace Paths::DataTest;

void BFSCheck::update_value(uint64_t obj) {
    for (const auto& ele: attributes){
        auto key = ele.first;
        ObjectId key_id = get<1>(key);
        uint64_t value_id = query_property(obj, key_id.id);
        double_t new_value = decoding_mask(ObjectId(value_id));
        attributes[key] = new_value;
    }
}

bool BFSCheck::eval_check(uint64_t obj, MacroState& macroState,  std::string  formula) {
    // Initialize context
    SMTContext context;
    for (const auto& ele: attributes){
        auto attr =  ele.first;
        std::string name = std::get<0>(attr);
        context.add_real_var(name);
    }
    for (const auto& ele: vars){
        auto var =  ele.first;
        context.add_real_var(get_query_ctx().get_var_name(var));
    }
    //Parse Formula
    auto property = context.parse(formula);
    //subsitution
    for (const auto& ele: attributes) {
            auto attr = ele.first;
            std::string name = std::get<0>(attr);
            double_t value = ele.second;
            property = context.subsitute_real(name, value, property);
        }
    // decompose
    auto vector = context.decompose(property);
    z3::ast_vector_tpl<z3::expr> new_vec = z3::ast_vector_tpl<z3::expr>(context.context);

    for (const auto& f: vector){
        // normalize formula into t ~ constant
        auto normal_form = context.normalizition(f);
        // get and update the bound
        auto bound = context.get_bound(normal_form);
        auto update_flag = macroState.update_bound(bound);
        // update the wrong value
        if (update_flag == 0){
            return false;
        }

        //check the sat for the current bound
        z3::solver s(context.context);
        s.add(context.bound_epsilon);
        for (const auto& parameter: macroState.collected_expr){
            std::string key_str = parameter.to_string();
            if (macroState.upper_bounds.find(key_str) != macroState.upper_bounds.end()){
                double val = macroState.upper_bounds[key_str];
                s.add(parameter <= context.add_real_val(val));
            }
            else if (macroState.lower_bounds.find(key_str) != macroState.lower_bounds.end()){
                double val = macroState.lower_bounds[key_str];
                s.add(parameter >= context.add_real_val(val));
            } else if (macroState.eq_vals.find(key_str) != macroState.eq_vals.end()){
                double val = macroState.eq_vals[key_str];
                s.add(parameter == context.add_real_val(val));
            }
        }

        switch (s.check()) {
            case z3::sat: return  true;
            case z3::unsat: return false;
            case z3::unknown: return false;
        }
    }
}


void BFSCheck::_begin(Binding& _parent_binding) {
    parent_binding = &_parent_binding;
    first_next = true;
    iter = make_unique<NullIndexIterator>();

    // Init start object id
    ObjectId start_object_id = start.is_var() ? (*parent_binding)[start.get_var()] : start.get_OID();

    // Store ID for end object
    end_object_id = end.is_var() ? (*parent_binding)[end.get_var()] : end.get_OID();
    // init the start node
    auto start_path_state = visited.add(start_object_id, ObjectId(), false, nullptr);
    auto start_macro_state =  std::make_shared<MacroState>(start_path_state, automaton.get_start());
    auto vec =  std::vector<std::shared_ptr<MacroState>>();

    for (auto& t: automaton.from_to_connections[automaton.get_start()]){
        bool check_succeeded = eval_check(start_object_id.id, *start_macro_state, t.property_checks);
        if (check_succeeded){
            start_macro_state->automaton_state = t.to;
            vec.emplace_back(std::move(start_macro_state));
        }
    }
    open.emplace(std::move(vec));


}


bool BFSCheck::_next() {
    // Check if first state is final
    if (first_next) {
        first_next = false;
        auto& current_state = open.front();

        // Return false if node does not exist in the database
        for (auto& location: current_state.state_vector)
        {
            if (!provider->node_exists(location -> path_state->node_id.id)) {
                open.pop();
                return false;
            }

            // Starting state is solution
            if (location -> path_state->node_id == end_object_id) {


            }
        }

    }

    while (open.size() > 0)
    {
        auto& current_state = open.front();
        for (auto& location: current_state.state_vector) {
            auto reached_final_state = expand_neighbors(*location);

            // Enumerate reached solutions
            if (reached_final_state != nullptr) {
                auto path_id = path_manager.set_path(reached_final_state, path_var);
                parent_binding->add(path_var, path_id);
                return true;
            } else {
                // Pop and visit next state
                assert(iter->at_end());
                open.pop();
            }
        }
    }
    return false;
}


const PathState* BFSCheck::expand_neighbors(const MacroState& current_state) {
    // Check if this is the first time that current_state is explored
    if (iter->at_end()) {
        current_transition = 0;
        // Check if automaton state has transitions
        if (automaton.from_to_connections[current_state.automaton_state].size() == 0) {
            return nullptr;
        }
        set_iter(current_state);
    }

    // Iterate over the remaining transitions of current_state
    // Don't start from the beginning, resume where it left thanks to current_transition and iter (pipeline)
    while (current_transition < automaton.from_to_connections[current_state.automaton_state].size()) {
        auto& transition = automaton.from_to_connections[current_state.automaton_state][current_transition];

        // Iterate over records until a final state is reached
        while (iter->next()) {
            // Reconstruct path and check if it's simple, discard paths that are not simple

            }

            // Special Cases: End node has been reached
            if (ObjectId(iter->get_reached_node()) == end_object_id) {
                // Return only if it's a solution, never expand
                if (automaton.is_final_state[transition.to]) {
                    return visited.add(ObjectId(iter->get_reached_node()),
                                       transition.type_id,
                                       transition.inverse,
                                       current_state.path_state);
                }
                continue;
            }

            // Add new path state to visited
            auto new_visited_ptr = visited.add(ObjectId(iter->get_reached_node()),
                                               transition.type_id,
                                               transition.inverse,
                                               current_state.path_state);
            // Add new state to open
            open.emplace(new_visited_ptr, transition.to);
        }

        // Construct new iter with the next transition (if there exists one)
        current_transition++;
        if (current_transition < automaton.from_to_connections[current_state.automaton_state].size()) {
            set_iter(current_state);
        }
    }
    return nullptr;
}


void BFSCheck::_reset() {
    // Empty open and visited
    queue<SearchState> empty;
    open.swap(empty);
    visited.clear();
    first_next = true;
    iter = make_unique<NullIndexIterator>();

    // Add starting states to open and visited
    ObjectId start_object_id = start.is_var() ? (*parent_binding)[start.get_var()] : start.get_OID();
    auto start_node_visited = visited.add(start_object_id, ObjectId(), false, nullptr);
    auto start_macro_state =  std::make_shared<MacroState>(start_node_visited, automaton.get_start());
    auto vec =  std::vector<std::shared_ptr<MacroState>>();
    vec.emplace_back(start_macro_state);
    open.emplace(vec);

    // Store ID for end object
    end_object_id = end.is_var() ? (*parent_binding)[end.get_var()] : end.get_OID();
}


void BFSCheck::accept_visitor(BindingIterVisitor& visitor) {
    visitor.visit(*this);
}


