#pragma once

#include "query/executor/binding_iter.h"

namespace LSH {

class ForestIndexTopK : public BindingIter {
public:
    const VarId                                   object_var;
    const VarId                                   similarity_var;
    const std::vector<std::pair<uint64_t, float>> top_k;

    ForestIndexTopK(VarId object_var, VarId similarity_var, std::vector<std::pair<uint64_t, float>>&& top_k);

    void accept_visitor(BindingIterVisitor& visitor) override;
    void _begin(Binding& parent_binding) override;
    bool _next() override;
    void _reset() override;
    void assign_nulls() override;

private:
    uint64_t current_index;

    Binding* parent_binding;
};
} // namespace LSH