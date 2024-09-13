//
// Created by lhy on 8/27/24.
//

#ifndef MILLENNIUMDB_SMT_AUTOMATON_H
#define MILLENNIUMDB_SMT_AUTOMATON_H


#pragma once

#include <functional>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "query/var_id.h"
#include "query/parser/smt/smt_exprs.h"
/*
This automaton also supports RDPQs (Data RPQs), where each node or edge
can evaluate it's properties (key: value) as a part of the path.

This automaton worked based on domain property graph model
// TODO: explain automaton structure (data transitions only have data checks, edge transitions have
// both data checks (for the edge) and type)
*/



// Transitions in the automaton (Edge & Data)
class SMTTransition {
public:
    // States connected by this transition
    uint_fast32_t from;
    uint_fast32_t to;

    // Direction of the transition (only applies to edge transitions)
    // false: from->to
    // true: to->from
    bool inverse;

    // Type of the transition for edge transitions
    // if is data transition type will be ""
    std::string type;

    ObjectId type_id = ObjectId::get_null();

    // List of property checks for the transition
    std::string property_checks;

    // constructor
    SMTTransition(uint_fast32_t from, uint_fast32_t to, bool inverse, std::string type, std::string property):
    from (from),
    to (to),
    inverse (inverse),
    type (std::move(type)),
    property_checks(property)
    {

    }

    //copy constructor
    SMTTransition(const SMTTransition& other) :
            from (other.from),
            to (other.to),
            inverse (other.inverse),
            type (other.type),

            property_checks(other.property_checks)
    {

    }
    //clone function
    SMTTransition clone() const {
        return SMTTransition(from, to, inverse, type, property_checks);
    }

    // Transition equality
    bool operator==(SMTTransition other) {
        // Data check transitions
        auto data = from == other.from && to == other.to && property_checks == other.property_checks;
        auto is_inverse = inverse == other.inverse;
        auto same_type = type ==other.type;
        return data && is_inverse && same_type;
    }

    SMTTransition& operator=(const SMTTransition& other){
         if (this ==  &other){
             return *this;
         }
         from = other.from;
         to = other.to;
         type =  other.type;
         inverse = other.inverse;
         type_id = other.type_id;
         property_checks = other.property_checks;
        return  *this;


    }

    // Data transition constructor
    // We only consider edge transition
    static SMTTransition make_data_transition(uint_fast32_t from,
                                               uint_fast32_t to,
                                               std::string
                                               property_checks )
    {
        return SMTTransition(from, to, false, "", property_checks);
    }

    // Edge transition constructor
    static std::unique_ptr<SMTTransition> make_edge_transition(uint_fast32_t from,
                                               uint_fast32_t to,
                                               bool inverse,
                                               const std::string& type,
                                               std::string
                                               property_checks)
    {
        return std::make_unique<SMTTransition>(from, to, inverse, type, std::move(property_checks));
    }

    // Edge transition constructor
    static SMTTransition make_transition(uint_fast32_t from,
                                         uint_fast32_t to,
                                         bool inverse,
                                         const std::string& type,
                                         std::string
                                              property_checks)
    {

               return {from, to, inverse, type, property_checks};

    }
};


/*
RDPQAutomaton represents a special Non-Deterministic Finite Automaton (NFA).
This class builds the automaton and transforms it into an optimal one.

This automaton will be referred to as a DE automaton (Data-Edge automaton), where each state can be of
type D (only has data check 'out' transitions) or type E (only has edge 'out' transitions). After a data check transition there
will always be an E-State. After an edge transition there will always be a D-State.

The following rules will allow the DE properties to be maintained properly (as well as the shortest paths property with BFS):

- There is only one START state, of type D, and it can't be an END state.
- The START state does NOT have any 'in' transitions (Ex: x -> START).
- All END states are of type E.
- An END state does NOT have any 'out' transitions (Ex: END -> x).

After the initial construction, the automaton is then transformed into a final automaton by using set_final_state.

The states of the automaton are not emulated by a specific class. A state is only represented
by an integer i, that indicates that the transitions of the current state are stored in the i-th
position of the from_to_connections, to_from_connections and transition vectors.

The distance to the final state results in a metric that can be used as a heuristic
by a path finder algorithm to select the state which is nearest to the final state.
*/
class SMTAutomaton {
private:
    // Start state, is always 0
    uint32_t start = 0;

    // Final state, will be set at the end of the automaton transformation
    uint32_t final_state = 0;

    // Number of states
    uint32_t total_states = 1;

    // the set of attributes 
    std::set<std::tuple<std::string, ObjectId>> attributes;

    // the set of parameters 
    std::set<VarId> parameter; 

    // ----- Methods to handle automaton transformations -----

    // Collapse end states to generate a unique final state
    void set_final_state();

    // ----- Auxiliary methods -----

    // Compute the minimum distance between the final_state and a state of the automaton
    void calculate_distance_to_final_state();

    // Sort the transitions for each state according to their distance to the final state
    void sort_state_transition(uint32_t state);
    void sort_transitions();


    // get all epsilon states
    std::set<uint32_t> get_epsilon_closure(uint32_t state);
    std::set<uint32_t> get_reachable_states(uint32_t source, bool inverse);
    //remove epsilon transitions
    void delete_epsilon_transitions();
    void delete_unreachable_states();
public:
    // Transitions that start from the i-th state (stored in the i-th position)
    std::vector<std::vector<SMTTransition>> from_to_connections;

    // Transitions that reach the i-th state (stored in the i-th position)
    // These transitions will be invalid after transforming the automaton (prefer using from_to_connections)
    std::vector<std::vector<SMTTransition>> to_from_connections;

    // End states before the automaton transformation
    std::set<uint32_t> end_states;

    // Stores the distance to the end state. It can be used by the
    // A* algorithm in enum and check binding_iter algorithms.
    std::vector<uint32_t> distance_to_final;

    // Access attribute methods
    inline uint32_t get_start() const noexcept { return start; }
    inline uint32_t get_total_states() const noexcept  { return total_states; }
    inline bool decide_accept(uint64_t state) const noexcept {
        return (end_states.find(state)!= end_states.end());
    }
    inline std::set<std::tuple<std::string, ObjectId>> get_attr() const noexcept {return attributes;}
    // Print the automaton
    void print(std::ostream& os) const;

    // Add states from 'other' automaton to this automaton, rename 'other' states, update 'other'
    // end states to be consistent with rename. Don't update 'other' connections.
    void rename_and_merge(SMTAutomaton& other);

    // Add a transition to the automaton
    void add_transition(SMTTransition transition);

    // Apply transformations to get the final automaton
    void transform_automaton(ObjectId(*str_to_oid)(const std::string&));

    //add epsilon transition
    void add_epsilon_transition(uint32_t from, uint32_t to);
    // TODO: Refactor to modify the automaton instead of returning a new one
    // Returns the inverse automaton (invalidating this one)
    // RDPQAutomaton invert_automaton();


    // only for test
    void set_start(uint32_t x){
        start = x;
    }

    uint32_t get_start(){
        return start;
    }
    void set_final(std::set<uint32_t> x){
        end_states  = std::move(x);
    }

    u_int32_t get_total_state(){
        return total_states;
    }

    void set_attr(std::set<std::tuple<std::string, ObjectId>> attr){
        attributes = std::move(attr); 
    }

        // the set of attributes 
    std::set<std::tuple<std::string, ObjectId>> get_attributes() {return attributes;};

    // the set of parameters 
    std::set<VarId> get_parameters(){return parameter;}; 

    void set_para(std::set<VarId> para){
        parameter = std::move(para); 
    }
};



#endif //MILLENNIUMDB_SMT_AUTOMATON_H
