#pragma once

#include "query/optimizer/plan/plan.h"

class IndexNestedLoopPlan : public Plan {
public:
    IndexNestedLoopPlan(
        std::unique_ptr<Plan> lhs,
        std::unique_ptr<Plan> rhs
    );

    IndexNestedLoopPlan(const IndexNestedLoopPlan& other) :
        lhs                   (other.lhs->clone()),
        rhs                   (other.rhs->clone()),
        estimated_cost        (other.estimated_cost),
        estimated_output_size (other.estimated_output_size)  { }

    std::unique_ptr<Plan> clone() const override {
        return std::make_unique<IndexNestedLoopPlan>(*this);
    }

    // only meant to be used by base plans, not joins
    int relation_size() const override { return 0; }

    double estimate_cost()        const override { return estimated_cost; }
    double estimate_output_size() const override { return estimated_output_size; }

    std::set<VarId> get_vars() const override;
    void set_input_vars(const std::set<VarId>& input_vars) override;

    std::unique_ptr<BindingIter> get_binding_iter() const override;

    bool get_leapfrog_iter(std::vector<std::unique_ptr<LeapfrogIter>>&,
                           std::vector<VarId>&,
                           uint_fast32_t&) const override { return false; }

    void print(std::ostream& os, int indent) const override;

private:
    std::unique_ptr<Plan> lhs;
    std::unique_ptr<Plan> rhs;

    double estimated_cost;
    double estimated_output_size;
};
