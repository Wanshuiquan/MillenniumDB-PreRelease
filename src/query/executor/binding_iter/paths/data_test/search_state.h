#pragma once

#include <functional>
#include <ostream>
#include <vector>
#include <hash_map>

#include "graph_models/object_id.h"
#include "query/executor/binding_iter/paths/index_provider/path_index.h"
#include "z3++.h"


namespace Paths {
    namespace DataTest{

        // Represents a path in a recursive manner (prev_state points to previous path state)
struct PathState {
    ObjectId node_id;
    ObjectId type_id;
    bool inverse_dir;
    const PathState* prev_state;

    PathState() = default;

    PathState(ObjectId         object_id,
              ObjectId         type_id,
              bool             inverse_dir,
              const PathState* prev_state) :
        node_id     (object_id),
        type_id     (type_id),
        inverse_dir (inverse_dir),
        prev_state  (prev_state) { }

    void print(std::ostream& os,
               std::function<void(std::ostream& os, ObjectId)> print_node,
               std::function<void(std::ostream& os, ObjectId, bool)> print_edge,
               bool begin_at_left) const;
};


struct MacroState {
    const PathState* path_state;
    uint32_t automaton_state;
    std::unordered_map<z3::expr, double> bounds;
    MacroState(const PathState* path_state,
                uint32_t         automaton_state,
                std::unordered_map<z3::expr, double> bound
                ) :
        path_state      (path_state),
        automaton_state (automaton_state) ,
        bounds (bound)
        { }

};

struct SearchState {
    std::vector<std::shared_ptr<MacroState>> state_vector;
    SearchState(
            const std::vector<std::shared_ptr<MacroState>> vec
            ): state_vector(std::move(vec)) {}
};
    }
}