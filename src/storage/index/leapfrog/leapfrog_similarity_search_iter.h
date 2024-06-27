#pragma once
/*
 * LeapfrogSimilaritySearchIter is built with the result of a top-k similarity search query. In order to be able to work
 * with the Leapfrog algorithm the result is sorted by ObjectId instead of the similarity metric.
 */

#include "storage/index/leapfrog/leapfrog_iter.h"

class LeapfrogSimilaritySearchIter : public LeapfrogIter {
public:
    LeapfrogSimilaritySearchIter(bool*                                   interruption_requested,
                                 std::vector<std::unique_ptr<ScanRange>> initial_ranges,
                                 std::vector<VarId>                      intersection_vars,
                                 std::vector<VarId>                      enumeration_vars,
                                 std::vector<std::pair<uint64_t, float>> top_k);

    inline uint64_t get_key() const override { return (level == 0) ? current->first : current->second; }

    void down() override;

    bool next() override;

    bool seek(uint64_t key) override;

    bool open_terms(Binding& input_binding) override;

    void begin_enumeration() override;

    void reset_enumeration() override;

    bool next_enumeration(Binding& binding) override;

private:
    // Pairs { object_id, similarity } sorted by the first element
    std::vector<std::pair<uint64_t, uint64_t>> sorted_top_k;

    std::vector<std::pair<uint64_t, uint64_t>>::iterator current;

    // Whether the enumeration of the similarity was done
    bool similarity_was_enum;

    uint64_t saved_similarity;
};