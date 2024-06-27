#pragma once

#include <memory>
#include <vector>

#include "query/executor/binding_iter/scan_ranges/term.h"
#include "storage/index/leapfrog/leapfrog_bpt_iter.h"
#include "storage/index/leapfrog/leapfrog_iter.h"

class LeapfrogEstimator {
private:
    VarId join_var;
    std::vector<std::unique_ptr<LeapfrogIter>> leapfrog_iters;

    size_t seeks = 0;

    // returns false on error
    template<size_t N>
    bool try_estimate(std::vector<double>& initial_estimations, std::vector<double>& after_estimations, LeapfrogBptIter<N>* casted) {
        if (casted == nullptr) {
            return false;
        }
        Record<N> min;
        Record<N> max;
        Record<N> after;

        // Will estimate ranges min-max, and min-after
        for (size_t i = 0; i < casted->initial_ranges.size(); i++) {
            auto term = dynamic_cast<Term*>(casted->initial_ranges[i].get());
            if (term == nullptr) {
                return false;
            }

            min[i] = term->get_oid().id;
            max[i] = term->get_oid().id;
            after[i] = term->get_oid().id;
        }

        min[casted->initial_ranges.size()] = 0;
        max[casted->initial_ranges.size()] = UINT64_MAX;
        after[casted->initial_ranges.size()] = casted->get_key();

        for (size_t i = casted->initial_ranges.size() + 1; i < N; i++) {
            min[i] = 0;
            max[i] = UINT64_MAX;
            after[i] = UINT64_MAX;
        }

        // std::cout << "Min: [" << min[0]   << ", " << min[1]   << ", " << min[2]   << "]\n";
        // std::cout << "Max: [" << max[0]   << ", " << max[1]   << ", " << max[2]   << "]\n";
        // std::cout << "Aft: [" << after[0] << ", " << after[1] << ", " << after[2] << "]\n";

        auto& bpt_root = casted->get_root();
        initial_estimations.push_back(
            BPlusTree<N>::estimate_records(bpt_root, min, max)
        );
        after_estimations.push_back(
            BPlusTree<N>::estimate_records(bpt_root, min, after)
        );

        return true;
    }

public:
    static constexpr size_t MAX_SEEKS = 1000;

    LeapfrogEstimator(
        VarId join_var,
        std::vector<std::unique_ptr<LeapfrogIter>>&& leapfrog_iters
    ) :
        join_var (join_var),
        leapfrog_iters (std::move(leapfrog_iters)) { }

    // returns -1 on error
    double estimate_var_cost() {
        bool finished = false;

        // for (const auto& lf_iter : leapfrog_iters) {
        //     auto var_size = lf_iter->get_relation_size();
        //     std::cout << "var size " << var_size << "\n";
        // }

        auto estimation_output = do_seeks(&finished);

        if (finished) {
            // std::cout << "Finished with " << seeks << " seeks\n";
            return 0;
        }

        std::vector<double> initial_estimations;
        std::vector<double> after_estimations;

        for (const auto& lf_iter : leapfrog_iters) {
            auto var_size = lf_iter->get_relation_size();
            // std::cout << "var size " << var_size << "\n";
            switch (var_size) {
            case 2: {
                auto ok = try_estimate<2>(initial_estimations, after_estimations, dynamic_cast<LeapfrogBptIter<2>*>(lf_iter.get()));
                if (!ok) return -1;
                break;
            }
            case 3: {
                auto ok = try_estimate<3>(initial_estimations, after_estimations, dynamic_cast<LeapfrogBptIter<3>*>(lf_iter.get()));
                if (!ok) return -1;
                break;
            }
            case 4: {
                auto ok = try_estimate<4>(initial_estimations, after_estimations, dynamic_cast<LeapfrogBptIter<4>*>(lf_iter.get()));
                if (!ok) return -1;
                break;
            }
            default: {
                return -1;
            }
            }
        }

        double cost = 0;
        for (size_t i = 0; i < initial_estimations.size(); i++) {
            assert(initial_estimations[i] >= after_estimations[i]);
            cost += initial_estimations[i] / (1+after_estimations[i]);
            // auto a = initial_estimations[i] / (1+after_estimations[i]);
            // std::cout << "initial_estimations: " << initial_estimations[i] << "\n";
            // std::cout << "after_estimations: " << after_estimations[i] << "\n";
            // std::cout << "Cost: " << a << "\n";
        }
        // std::cout << "Estimation output: " << estimation_output << "\n";
        // std::cout << "initial_estimations.size(): " << initial_estimations.size() << "\n";
        // Average
        return cost / initial_estimations.size() * (estimation_output + 1);
    }

    // returns how many results encounters in MAX_SEEKS (or less if it ends) seeks
    size_t do_seeks(bool* finished) {
        Binding binding;
        std::vector<LeapfrogIter*> iters;
        for (const auto& lf_iter : leapfrog_iters) {
            if (!lf_iter->open_terms(binding)) {
                *finished = true;
                return 0;
            }
            lf_iter->down();
            iters.push_back(lf_iter.get());
        }

        // sort the corresponding iterators using insertion sort
        for (int_fast32_t i = 1; i < (int_fast32_t) iters.size(); i++) {
            auto aux = iters[i];
            int_fast32_t j;
            for (j = i - 1; j >= 0 && iters[j]->get_key() > aux->get_key(); j--) {
                iters[j + 1] = iters[j];
            }
            iters[j + 1] = aux;
        }

        int current_min_index = 0;

        assert(!iters.empty());
        auto min = iters.front()->get_key();
        auto max = iters.back()->get_key();

        size_t results = 0;

        while (++seeks < MAX_SEEKS) { // min = max means all are equal
            if (iters[current_min_index]->seek(max)) {
                // after the seek, the previous min is the max
                max = iters[current_min_index]->get_key();

                // update the min
                current_min_index = (current_min_index + 1) % iters.size();
                min = iters[current_min_index]->get_key();
            } else {
                *finished = true;
                return results;
            }

            if (min == max) {
                results++;

                if (iters[current_min_index]->next()) {
                    // after the next, the previous min is the max
                    max = iters[current_min_index]->get_key();

                    // update the min
                    current_min_index = (current_min_index + 1) % iters.size();
                    min = iters[current_min_index]->get_key();
                } else {
                    *finished = true;
                    return results;
                }
            }
        }
        *finished = false;
        return results;
    }

};
