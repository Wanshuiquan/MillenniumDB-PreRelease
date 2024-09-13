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

BptIter<2> BFSCheck::query_label(uint64_t obj_id) const {
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
        // check_property
        bool check_succeeded = eval_check(start_object_id.id, *start_macro_state, t.property_checks);
        //check_label
        uint64_t label_id = QuadObjectId::get_string(t.type).id;
        bool label_matched = match_label(start_object_id.id, label_id);
        if (check_succeeded&&label_matched){
            start_macro_state->automaton_state = t.to;
            vec.emplace_back(std::move(start_macro_state));
        }
    }
//    open.emplace(std::move(vec));


}

std::tuple<bool, bool> BFSCheck::progress(Paths::DataTest::MacroState &macroState, std::vector<std::shared_ptr<MacroState>>& state_vec) {
    for (auto& transition_edge : automaton.from_to_connections[macroState.automaton_state]){
        set_iter(macroState, transition_edge);
        if (iter == nullptr){
            return {false, false};
        }
        // progress with edge
        uint64_t edge_id = iter ->get_edge();
        uint64_t target_id = iter -> get_reached_node();
        //edge type has checked, so we only check the properties
        if (eval_check(edge_id, macroState, transition_edge.property_checks)){
            macroState.automaton_state = transition_edge.to;
            if (true){

            }
            for (auto& transition_node : automaton.from_to_connections[macroState.automaton_state]){
                bool matched_label;
            }
        }
        state_vec.emplace_back(std::make_shared<MacroState>(macroState));
    }
return {true, true};
}

bool BFSCheck::_next() {
    // Check if first state is final
    if (first_next) {
        const auto& current_state = open.front();
        // if the state vector is empty, we do not have to explore
        if (current_state->state_vector.empty()) return false;

        // iterate over each macro state
        for (auto& location: current_state -> state_vector)
        {

            auto node_iter = quad_model.nodes ->get_range(&get_query_ctx().thread_info.interruption_requested,
                                                          Record<1>({location->path_state->node_id.id}),
                                                          Record<1>({location->path_state->node_id.id}));

            // node does not exists
            if (node_iter.next() == nullptr){
                open.pop();
                return false;
            }
            // Starting state is solution
            if (location -> path_state->node_id == end_object_id && automaton.decide_accept(location -> automaton_state)) {
                auto path_id = path_manager.set_path(location->path_state, path_var);
                parent_binding->add(path_var, path_id);
                queue<const SearchState*> empty;
                open.swap(empty);
                return true;

            }


        }

    }

    // iterate
    while (!open.empty())
    {
        // get a new state vector
        auto& current_state = open.front();

        // we make a edge transition, and then we make a node transition
        auto res = std::vector<std::shared_ptr<MacroState>>();

        for (auto& location: current_state -> state_vector) {
            //iterate over transitions
            for (auto& transition : automaton.from_to_connections[location->automaton_state]) {
                set_iter(*location, transition);
                // we step by v - e -> v1 and we check the property
                auto edge_id =  iter->get_edge();
                auto target_id = iter->get_reached_node();
                if (eval_check(edge_id, *location, transition.property_checks)){
                    location ->automaton_state = transition.to;
                    for (auto& _node_trans : automaton.from_to_connections[location->automaton_state]){
                        bool label_matched = match_label(target_id, QuadObjectId::get_string(_node_trans.type).id);
                        bool check_properties = eval_check(target_id, *location, transition.property_checks);

                    }
                }

            }
//
//            if (reached_final_state != nullptr) {
//                auto path_id = path_manager.set_path(reached_final_state, path_var);
//                parent_binding->add(path_var, path_id);
//                return true;
//            } else {
//                // Pop and visit next state
//                assert(iter->at_end());
//                open.pop();
//            }
        }
    }
    return false;
}





void BFSCheck::_reset() {
    // Empty open and visited
    queue<const SearchState*> empty;
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


