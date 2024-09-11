//
// Created by lhy on 9/2/24.
//

#ifndef MILLENNIUMDB_BFS_CHECK_H
#define MILLENNIUMDB_BFS_CHECK_H
#pragma  once
#include <queue>
#include "query/executor/binding_iter.h"
#include "search_state.h"
#include "query/parser/paths/automaton/smt_automaton.h"
#include "misc/arena.h"
#include "storage/index/record.h"
#include "graph_models/quad_model/quad_model.h"

namespace Paths {
    namespace DataTest{

        enum ParamType{
            String,
            Real
        };

        class BFSCheck: public BindingIter {
            // Attributes determined in the constructor
            VarId         path_var;
            Id            start;
            Id            end;
            const SMTAutomaton automaton;
            std::unique_ptr<IndexProvider> provider;

            // where the results will be written, determined in begin()
            Binding* parent_binding;

            // if `end` is an ObjectId, this has the same value
            // if `end` is a variable, this has its the value in the binding
            // its value is setted in begin() and reset()
            ObjectId end_object_id;

            // struct with all simple paths
            Arena<PathState> visited;

            // Queue for BFS
            std::queue<SearchState> open;

            // Iterator for current node expansion
            std::unique_ptr<EdgeIter> iter;

            // The index of the transition being currently explored
            uint_fast32_t current_transition;

            // true in the first call of next() and after a reset()
            bool first_next = true;

            // Optimal distance to target node. UINT64_MAX means the node has not been explored yet.
            uint64_t optimal_distance = UINT64_MAX;
            // variables
            std::map<VarId, double_t> vars;
            // attributes
            std::map<std::tuple<std::string, ObjectId>, double_t> attributes;


        public:
            // Statistics
            uint_fast32_t idx_searches = 0;

            BFSCheck(
                    VarId                          path_var,
                    Id                             start,
                    Id                             end,
                    SMTAutomaton                    automaton,
                    std::unique_ptr<IndexProvider>  provider
            ) :
                    path_var      (path_var),
                    start         (start),
                    end           (end),
                    automaton     (automaton),
                    provider      (std::move(provider)) {
                    for (auto& ele: automaton.get_attributes()){
                        attributes.emplace(ele, 0);
                    }
                    for (auto& ele: automaton.get_parameters()){
                        vars.emplace(ele, 0);
                    }
            }

            // Explore neighbors searching for a solution.
            // returns a pointer to the object added to visited when a solution is found
            // or nullptr when there are no more results
            const PathState* expand_neighbors(const MacroState& current_state);

            void accept_visitor(BindingIterVisitor& visitor) override;

            void _begin(Binding& parent_binding) override;

            void _reset() override;

            bool _next() override;
            bool eval_check(uint64_t obj, MacroState&, std::string );
            void update_value(uint64_t);
            void assign_nulls() override {
                parent_binding->add(path_var, ObjectId::get_null());
            }

            inline uint64_t query_property (uint64_t obj_id, uint64_t key_id) const {
                // Search B+Tree for *values* given <obj,key>
                std::array<uint64_t, 3> min_prop_ids;
                std::array<uint64_t, 3> max_prop_ids;
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
            // Set iterator for current node + transition
            inline void set_iter(const MacroState& s) {
                // Get current transition object from automaton
                auto& transition = automaton.from_to_connections[s.automaton_state][current_transition];

                // Get iterator from custom index
                iter = provider->get_iter(transition.type_id.id, transition.inverse, s.path_state->node_id.id);
                idx_searches++;
            }
        };
    }
}



#endif //MILLENNIUMDB_BFS_CHECK_H
