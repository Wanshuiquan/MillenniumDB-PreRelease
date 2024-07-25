#include "forest_index_top_k.h"

#include <cassert>
#include <memory>
#include <vector>

#include "graph_models/quad_model/conversions.h"
#include "macros/likely.h"

using namespace LSH;

ForestIndexTopK::ForestIndexTopK(VarId object_var_,
                                 VarId similarity_var_,
                                 std::vector<std::pair<uint64_t, float>>&& top_k_) :
    object_var     (object_var_),
    similarity_var (similarity_var_),
    top_k          (std::move(top_k_)) { }


void ForestIndexTopK::accept_visitor(BindingIterVisitor& visitor) {
    visitor.visit(*this);
}


void ForestIndexTopK::_begin(Binding& parent_binding) {
    this->parent_binding = &parent_binding;
    current_index        = 0;
}


bool ForestIndexTopK::_next() {
    if (MDB_unlikely(get_query_ctx().thread_info.interruption_requested))
        throw InterruptedException();

    if (current_index < top_k.size()) {
        parent_binding->add(object_var, ObjectId(top_k[current_index].first));
        parent_binding->add(similarity_var, MQL::Conversions::pack_float(top_k[current_index].second));
        ++current_index;
        return true;
    }
    return false;
}


void ForestIndexTopK::_reset() {
    current_index = 0;
}


void ForestIndexTopK::assign_nulls() {
    parent_binding->add(object_var, ObjectId::get_null());
    parent_binding->add(similarity_var, ObjectId::get_null());
}