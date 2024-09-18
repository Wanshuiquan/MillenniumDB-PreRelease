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

uint64_t BFSCheck::query_property(uint64_t obj_id, uint64_t key_id) const  {
    // Search B+Tree for *values* given <obj,key>
    std::array<uint64_t, 3> min_prop_ids {};
    std::array<uint64_t, 3> max_prop_ids {};
    min_prop_ids[0] = obj_id;
    max_prop_ids[0] = obj_id;
    min_prop_ids[1] = key_id;
    max_prop_ids[1] = key_id;
    min_prop_ids[2] = 0;
    max_prop_ids[2] = UINT64_MAX;
    auto prop_iter = quad_model.object_key_value->get_range(
            &get_query_ctx().thread_info.interruption_requested,
            Record<3>(min_prop_ids),
            Record<3>(max_prop_ids));
    auto prop_record = prop_iter.next();
    assert(prop_record != nullptr);
    auto record_value_id = (*prop_record)[2];
    return record_value_id;
}

BptIter<2> BFSCheck::query_label(uint64_t obj_id) {
    std::array<uint64_t ,2> min_prop_ids{};
    std::array<uint64_t, 2> max_prop_ids{};
    max_prop_ids[0] = obj_id;
    min_prop_ids[0] = obj_id;
    max_prop_ids[1] = UINT64_MAX,
            min_prop_ids[1] = 0;
    auto prop_iter = quad_model.node_label->get_range(
            &get_query_ctx().thread_info.interruption_requested,
            Record<2>(min_prop_ids),
            Record<2>(max_prop_ids));
    return prop_iter;
}

bool BFSCheck::match_label(uint64_t obj_id, uint64_t label_id) {
    auto labels_iter = query_label(obj_id);
    auto label_record = labels_iter.next();
    while(label_record != nullptr){
        if ((*label_record)[1] == label_id) {
            return true;
        }
        else {
            label_record = labels_iter.next();
        }
    }
    return false;
}
void BFSCheck::update_value(uint64_t obj) {
    for (const auto& ele: attributes){
        auto key = ele.first;
        ObjectId key_id = get<1>(key);
        uint64_t value_id = query_property(obj, key_id.id);
        double_t new_value = decoding_mask(ObjectId(value_id));
        attributes[key] = new_value;
    }
}

bool BFSCheck::eval_check(uint64_t obj, MacroState& macroState, std::string formula) {
    // update_value
    update_value(obj);
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
    z3::solver s(context.context);
    s.add(context.bound_epsilon);
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


    }
    switch (s.check()) {
        case z3::sat: return  true;
        case z3::unsat: return false;
        case z3::unknown: return false;
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
    auto start_path_state = visited.add(start_object_id, ObjectId::get_null(), ObjectId::get_null() , false, nullptr);
    auto* start_macro_state =  new MacroState(start_path_state, automaton.get_start());

    // explore from the init state
    for (auto& t: automaton.from_to_connections[automaton.get_start()]){
        // check_property
        bool check_succeeded = eval_check(start_object_id.id, *start_macro_state, t.property_checks);
        //check_label
        uint64_t label_id = QuadObjectId::get_string(t.type).id;
        bool label_matched = match_label(start_object_id.id, label_id);
        if (check_succeeded&&label_matched&&even){
            // the next transition should be an edge transition
            even = false;
            open.emplace(start_macro_state->path_state, t.to, start_macro_state->upper_bounds, start_macro_state->lower_bounds, start_macro_state->eq_vals, start_macro_state->collected_expr);
        }
    }
    // insert the init state vector to the state
}

const PathState* BFSCheck::expand_neighbors(MacroState& macroState){
    // stop if automaton state has not outgoing transitions
    if (automaton.from_to_connections[macroState.automaton_state].empty()) {
        return nullptr;
    }
    current_transition = 0;
    set_iter(macroState);

    while (current_transition < automaton.from_to_connections[macroState.automaton_state].size()) {
        auto &transition_edge = automaton.from_to_connections[macroState.automaton_state][current_transition];
        if (iter->at_end()) {
            // set the iter, we only set iter with edge transitions
            set_iter(macroState);
            // get the edge of edge and target
            uint64_t edge_id = iter->get_edge();
            uint64_t target_id = iter->get_reached_node();
            // progress with edges
            // edges type has checked, so we only check the properties
            // we do not progress if it is not sat with the edge transition, or the transition is not
            if ((!even) || (!eval_check(edge_id, macroState, transition_edge.property_checks))) {
                return nullptr;
            }

            // the odd states and the even states should be disjoint
            if (macroState.automaton_state != transition_edge.to) {
                macroState.automaton_state = transition_edge.to;
                even = !even;
            } else {
                return nullptr;
            }

            // else we explore a successor transition as a node transition
            for (auto &transition_node: automaton.from_to_connections[macroState.automaton_state]) {
                auto label_id = QuadObjectId::get_string(transition_node.type);
                bool matched_label = match_label(target_id, label_id.id);
                bool check_value = eval_check(target_id, macroState, transition_node.property_checks);
                const PathState *new_visited_ptr = visited.add(
                        ObjectId(target_id),
                        QuadObjectId::get_edge(transition_edge.type),
                        ObjectId(edge_id),
                        transition_edge.inverse,
                        macroState.path_state
                );
                if (matched_label && check_value) {
                    if (even && macroState.automaton_state != transition_edge.to) {
                        macroState.automaton_state = transition_edge.to;
                        even = !even;
                    } else {
                        return nullptr;
                    }
                    if (automaton.decide_accept(macroState.automaton_state) && target_id == end_object_id.id) {
                        return new_visited_ptr;
                    } else {
                        open.emplace(
                                new_visited_ptr,
                                transition_edge.to,
                                macroState.upper_bounds,
                                macroState.lower_bounds,
                                macroState.eq_vals,
                                macroState.collected_expr
                        );
                    }
                }
            }
            current_transition++;
            if (current_transition < automaton.from_to_connections[macroState.automaton_state].size()) {
                set_iter(macroState);
            }

        }
    }
    return nullptr;
}
bool BFSCheck::_next() {
    // Check if first state is final
    if (first_next) {
        const auto& current_state = open.front();

        // iterate over each macro state



        auto node_iter = provider ->node_exists(current_state.path_state->node_id.id);
        if (!node_iter){
                open.pop();
                return false;
            }
        // start state is the solution
        if (current_state. path_state->node_id == end_object_id && automaton.decide_accept(current_state. automaton_state)) {
                auto path_id = path_manager.set_path(current_state.path_state, path_var);
                parent_binding->add(path_var, path_id);
                queue<MacroState> empty;
                open.swap(empty);
                return true;

            }




    }

    // iterate
    while (!open.empty()) {
        // get a new state vector
        auto &current_state = open.front();
        auto reached_final_state = expand_neighbors(current_state);

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
    return false;
}





void BFSCheck::_reset() {
    // Empty open and visited
    queue<MacroState> empty;
    open.swap(empty);
    visited.clear();
    first_next = true;
    iter = make_unique<NullIndexIterator>();

    // Add starting states to open and visited
    ObjectId start_object_id = start.is_var() ? (*parent_binding)[start.get_var()] : start.get_OID();
    auto start_path_state = visited.add(start_object_id, ObjectId::get_null(), ObjectId::get_null() , false, nullptr);

    auto* start_macro_state =  new MacroState(start_path_state, automaton.get_start());

    // explore from the init state
    for (auto& t: automaton.from_to_connections[automaton.get_start()]){
        // check_property
        bool check_succeeded = eval_check(start_object_id.id, *start_macro_state, t.property_checks);
        //check_label
        uint64_t label_id = QuadObjectId::get_string(t.type).id;
        bool label_matched = match_label(start_object_id.id, label_id);
        if (check_succeeded&&label_matched&&even){
            // the next transition should be an edge transition
            even = false;
            open.emplace(start_macro_state->path_state,
                         t.to,
                         start_macro_state->upper_bounds,
                         start_macro_state->lower_bounds,
                         start_macro_state->eq_vals,
                         start_macro_state->collected_expr);
        }
    }
    // insert the init state vector to the state
    // Store ID for end object
    end_object_id = end.is_var() ? (*parent_binding)[end.get_var()] : end.get_OID();
}


void BFSCheck::accept_visitor(BindingIterVisitor& visitor) {
    visitor.visit(*this);
}


