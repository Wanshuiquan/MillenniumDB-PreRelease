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

template<bool CYCLIC>
void BFSCheck<CYCLIC>::update_value(uint64_t obj) {
    for (const auto& ele: attributes){
        auto key = ele.first;
        ObjectId key_id = get<1>(key);
        uint64_t value_id = query_property(obj, key_id.id);
        double_t new_value = decoding_mask(ObjectId(value_id));
        attributes[key] = new_value;
    }
}

template<bool CYCLIC>
bool BFSCheck<CYCLIC>::eval_check(uint64_t obj, MacroState& macroState, std::string formula) {
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
    // normalize

    for (const auto& f: vector){
        auto normal_form = context.normalizition(f);
        auto bound = context.get_bound(normal_form);
    }



}
template <bool CYCLIC>
void BFSCheck<CYCLIC>::_begin(Binding& _parent_binding) {
    parent_binding = &_parent_binding;
    first_next = true;
    iter = make_unique<NullIndexIterator>();

    // Add starting states to open and visited
    ObjectId start_object_id = start.is_var() ? (*parent_binding)[start.get_var()] : start.get_OID();
    auto start_node_visited = visited.add(start_object_id, ObjectId(), false, nullptr);
    auto start_macro_state =  std::make_shared<MacroState>(start_node_visited, automaton.get_start());
    auto vec =  std::vector<std::shared_ptr<MacroState>>();
    vec.emplace_back(start_macro_state);
    open.emplace(make_unique<SearchState>(std::move(vec)));


    // Store ID for end object
    end_object_id = end.is_var() ? (*parent_binding)[end.get_var()] : end.get_OID();
}


template <bool CYCLIC>
bool BFSCheck<CYCLIC>::update_value(uint64_t obj){
auto attributes = automaton.get_attr();
for (auto& attr:attributes){
    auto name = get<0>(attr);
    auto attr_id = get<1>(attr).id;

    // Search B+Tree for *values* given <obj,key>
    array<uint64_t, 3> min_prop_ids;
    array<uint64_t, 3> max_prop_ids;
    min_prop_ids[0] = obj;
    max_prop_ids[0] = obj;
    min_prop_ids[1] = attr_id;
    max_prop_ids[1] = attr_id;
    min_prop_ids[2] = 0;
    max_prop_ids[2] = UINT64_MAX;
    auto prop_iter = quad_model.object_key_value->get_range(
            &get_query_ctx().thread_info.interruption_requested,
            Record<3>(min_prop_ids),
            Record<3>(max_prop_ids));
    auto prop_record = prop_iter.next();
    if (prop_record != nullptr){
        return false;
    }
    else {
        // query the value for each parameter
    }
}

}
template <bool CYCLIC>
bool BFSCheck<CYCLIC>::_next() {
    // Check if first state is final
    if (first_next) {
        first_next = false;
        auto& current_state = open.front();

        // Return false if node does not exist in the database
        for (auto& location: current_state. state_vector)
        {
            if (!provider->node_exists(location -> path_state->node_id.id)) {
                open.pop();
                return false;
            }

            // Starting state is solution
            if (location -> path_state->node_id == end_object_id) {

                if (automaton.end_states.count(automaton.get_start())) {
                    auto path_id = path_manager.set_path(location -> path_state, path_var);
                    parent_binding->add(path_var, path_id);
                    if (!CYCLIC) {  // Acyclic can only have this trivial solution when start node = end node
                        queue<SearchState> empty;
                        open.swap(empty);
                    }
                    return true;
                } else if (!CYCLIC) {  // Acyclic can't have any more solutions when start node = end node
                    queue<SearchState> empty;
                    open.swap(empty);
                    return false;
                }
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


template <bool CYCLIC>
const PathState* BFSCheck<CYCLIC>::expand_neighbors(const MacroState& current_state) {
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
            if (!is_simple_path(current_state.path_state, ObjectId(iter->get_reached_node()))) {
                // If path can be cyclic, return solution only when the new node is the starting node and is also final
                if (CYCLIC && automaton.is_final_state[transition.to]) {
                    ObjectId start_object_id = start.is_var() ? (*parent_binding)[start.get_var()] : start.get_OID();
                    // This case only happens if the starting node and end node are the same
                    if (start_object_id == end_object_id && ObjectId(iter->get_reached_node()) == start_object_id) {
                        return visited.add(ObjectId(iter->get_reached_node()),
                                           transition.type_id,
                                           transition.inverse,
                                           current_state.path_state);
                    }
                }
                continue;
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


template <bool CYCLIC>
void BFSCheck<CYCLIC>::_reset() {
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


template <bool CYCLIC>
void BFSCheck<CYCLIC>::accept_visitor(BindingIterVisitor& visitor) {
    visitor.visit(*this);
}


template class Paths::DataTest::BFSCheck<true>;
template class Paths::DataTest::BFSCheck<false>;

