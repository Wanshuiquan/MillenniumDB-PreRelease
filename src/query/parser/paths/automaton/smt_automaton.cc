//
// Created by lhy on 8/27/24.
//
#include "query/parser/paths/automaton/smt_automaton.h"
#include "graph_models/object_id.h"
#include <sstream>
#include <queue>
#include <stack>
#include <utility>
#include "query/parser/smt/smt_expr_printer.h"



// Print the automaton
void SMTAutomaton::print(std::ostream& os) const {
    for (size_t i = 0; i < from_to_connections.size(); i++) {
        for (auto& t : from_to_connections[i]) {
            // TODO: print data check



            os << t.from << "=[" << (t.inverse ? "^" : "") << t.type << " {" << t.property_checks << "}]=>" << t.to << "\n";

        }
    }
    os << "distance to end: \n";
    for (size_t i = 0; i < distance_to_final.size(); i++) {
        os << i << ":" << distance_to_final[i] << "\n";
    }
    os << "end states: { ";
    for (auto& state : end_states) {
        os << state << "  ";
    }
    os << "}\n";
    os << "start state: " << start << "\n";
    os << "final state: " << final_state << "\n" << std::endl;
    os << "total_states" << total_states << std::endl;
}


// Combine two automatons
void SMTAutomaton::rename_and_merge(SMTAutomaton& other) {
    // Add and rename 'other' states to this automaton
    // Renaming consists in the sum of the original states
    // quantity to the id of 'other' states
    auto initial_states = total_states;
    for (size_t i = 0; i < other.from_to_connections.size(); i++) {
        for (auto& t : other.from_to_connections[i]) {
            // Create a transition with renamed states
            // Edge transition
                auto transition = SMTTransition::make_transition(
                        t.from + initial_states,
                        t.to + initial_states,
                        t.inverse,
                        t.type,
                        std::move(t.property_checks));

                // Add transition to this automaton
                add_transition(transition);

        }
    }

    // Rename 'other' end states
    std::set<uint32_t> new_end;
    for (auto& end_state : other.end_states) {
        new_end.insert(initial_states + end_state);
    }
    other.end_states = std::move(new_end);

    // Rename start state for 'other'
    other.start = initial_states;
}


// Add new transition to automaton
void SMTAutomaton::add_transition(SMTTransition transition) {
    // Check if connections vector has slots to save from and to
    while (from_to_connections.size() <= transition.from ||
           from_to_connections.size() <= transition.to) {
        std::vector<SMTTransition> new_vec = std::vector<SMTTransition>();
        from_to_connections.push_back(std::move(new_vec));
    }
    while (to_from_connections.size() <= transition.from ||
           to_from_connections.size() <= transition.to) {
        std::vector<SMTTransition> new_vec = std::vector<SMTTransition>();
        to_from_connections.push_back(std::move(new_vec));
    }

    // Check if the new connection already exists
    bool exists = false;
    for (auto& t : from_to_connections[transition.from]) {
        if (transition == t) {
            exists = true;
            break;
        }
    }

    // Add new connection only if it doesn't exist
    if (!exists) {
        from_to_connections[transition.from].push_back(transition);
        to_from_connections[transition.to].push_back(transition);
    }
    // Update number of states
    total_states = from_to_connections.size();
}


// Transform automaton into a final automaton
void SMTAutomaton::transform_automaton(ObjectId(*f)(const std::string&)) {
    delete_epsilon_transitions();
    delete_unreachable_states();
    // Set transition ids
    for (size_t i = 0; i < from_to_connections.size(); i++) {
        for (auto& t : from_to_connections[i]) {
        if(t.type.c_str()[0] == ':') {
            t.type_id = f(t.type.erase(0, 1));
        }
        else{
            t.type_id = QuadObjectId::get_string(t.type);

        }
        }
    }
}
//
//// ----- Transformation handler methods -----
//
//
//// Collapses all end states into one final state
void SMTAutomaton::add_epsilon_transition(uint32_t from, uint32_t to){
    add_transition(SMTTransition(from, to, false, "epsilon", "epsilon"));
}
std::set<uint32_t> SMTAutomaton::get_epsilon_closure(uint32_t state) {
    // Automaton exploration is with dfs algorithm
    std::set<uint32_t>  epsilon_closure;
    // It is not necessary to force to state belong to it own epsilon closure
    std::set<uint32_t> visited;
    std::stack<uint32_t> open;
    open.push(state);
    while (!open.empty()) {
        auto current_state = open.top();
        open.pop();
        if (visited.find(current_state) == visited.end()) {
            visited.insert(current_state);
            for (auto& transition : from_to_connections[current_state]) {
                if (transition.property_checks == "epsilon") {
                    epsilon_closure.insert(transition.to);
                    open.push(transition.to);
                }
            }
        }
    }
    return epsilon_closure;
}

std::set<uint32_t> SMTAutomaton::get_reachable_states(uint32_t source, bool inverse) {
    // Return all reachable states from 'source'. Get nodes using DFS algorithm
    std::stack<uint32_t> open;
    std::set<uint32_t> reachable_states;
    open.push(source);
    while (!open.empty()) {
        auto current_state = open.top();
        open.pop();

        // Check if state has not visited yet
        if (reachable_states.find(current_state) == reachable_states.end()) {
            reachable_states.insert(current_state);
            // Use inverse to get transitions check direction, inverse=true gets transitions
            // of to_from and inverse=false gets transitions of from_to
            auto next_states = inverse ?
                               to_from_connections[current_state] : from_to_connections[current_state];
            for (const auto& transition : next_states) {
                open.push(inverse ? transition.from : transition.to);
            }
        }
    }
    return reachable_states;
}

void SMTAutomaton::delete_epsilon_transitions() {
    for (size_t state = 0; state < from_to_connections.size(); state++) {
        // For each state, get his epsilon closure
        auto epsilon_closure = get_epsilon_closure(state);
        // If a end state is in closure, then state will be in end_state
        for (const auto s : epsilon_closure) {
            if (end_states.find(s) != end_states.end()) {
                end_states.insert(state);
            }
        }
        // Each epsilon transition of state will be replaced
        // by a non epsilon transition that reaches
        size_t transition_n = 0;
        while (transition_n < from_to_connections[state].size()) {
            // Epsilon transitions has empty type
            if (from_to_connections[state][transition_n].property_checks == "epsilon") {
                // Before delete transition, connect 'state' to states that
                // states of epsilon closure reaches without a epsilon transition
                for (const auto s : epsilon_closure) {
                    for (const auto& t : from_to_connections[s]) {
                        // Connect only if t is not epsilon transition. Always a state
                        // s connect with another state by a non epsilon transition.
                        if (t.property_checks != "epsilon") {
                            add_transition(SMTTransition(state, t.to, t.inverse, t.type, t.property_checks));
                        }
                    }
                }
                // delete epsilon transition
                from_to_connections[state].erase(
                        from_to_connections[state].begin() + transition_n);
            } else {
                transition_n++;
            }
        }
    }
}

void SMTAutomaton::delete_unreachable_states() {
    // Get reachable states from start state
    auto reachable_states = get_reachable_states(start, false);
    // Avoid iterate over start state
    for (size_t i = 1; i < from_to_connections.size(); i++) {
        // Check if 'i0 is reachable from start
        if (reachable_states.find(i) == reachable_states.end()) {
            // Delete all transitions from and to 'i' if is not reachable
            from_to_connections[i].clear();
            from_to_connections[i].clear();
            end_states.erase(i);

            // Delete all transitions that includes 'i' state
            for (size_t j = 0; j < from_to_connections.size(); j++) {
                // For each state 'j' check if it reaches to 'i' state
                auto iterator = from_to_connections[j].begin();
                while (iterator != from_to_connections[j].end()) {
                    if (iterator->to == i) {
                        // Delete transition
                        from_to_connections[j].erase(iterator);
                    } else {
                        // Go to next transition
                        iterator++;
                    }
                }
                iterator = to_from_connections[j].begin();
                // For each state 'j', check if it is reachable from 'i'
                while (iterator != to_from_connections[j].end()) {
                    if (iterator->from == i) {
                        // Delete transition
                        to_from_connections[j].erase(iterator);
                    } else {
                        // Go to next transition
                        iterator++;
                    }
                }
            }
        }
    }
}

