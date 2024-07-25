#include "forest_index.h"

#include <algorithm>
#include <fstream>
#include <queue>

#include "graph_models/object_id.h"
#include "storage/index/tensor_store/lsh/forest_index_query_iter.h"
#include "storage/index/tensor_store/lsh/metric.h"
#include "storage/index/tensor_store/lsh/tree.h"
#include "storage/index/tensor_store/serialization.h"
#include "storage/index/tensor_store/tensor_store.h"

using namespace LSH;

ForestIndex::ForestIndex(const TensorStore& tensor_store_, MetricType metric_type_, uint64_t num_trees_, uint64_t max_bucket_size_, uint64_t max_depth_) :
    num_trees       (num_trees_),
    max_bucket_size (max_bucket_size_),
    max_depth       (max_depth_),
    tensor_store    (tensor_store_),
    metric_type     (metric_type_)
{
    assert(num_trees > 0);
    assert(max_bucket_size > 0);
    assert(max_depth > 0);

    // Bind metric functions
    switch (metric_type) {
    case MetricType::ANGULAR: {
        similarity_fn = &Metric::cosine_distance;
        break;
    }
    case MetricType::EUCLIDEAN: {
        similarity_fn = &Metric::euclidean_distance;
        break;
    }
    default: { // MetricType::MANHATTAN:
        similarity_fn = &Metric::manhattan_distance;
        break;
    }
    }

    // Initialize the trees
    for (uint_fast32_t i = 0; i < num_trees; ++i)
        trees.push_back(std::make_unique<Tree>(tensor_store, metric_type, max_bucket_size, max_depth));
}


ForestIndex::ForestIndex(const std::string& path, const TensorStore& tensor_store_) :
    tensor_store (tensor_store_)
{
    // Load trees from file
    deserialize(path);
    assert(num_trees > 0);
    assert(max_bucket_size > 0);
    assert(max_depth > 0);
}


void ForestIndex::build() {
    #ifdef _OPENMP
    #pragma omp parallel for
    #endif
    for (auto it = trees.begin(); it < trees.end(); ++it)
        (*it)->build();
}


std::vector<std::pair<uint64_t, float>> ForestIndex::query_top_k(
    const std::vector<float>& query_tensor,
    uint64_t                  k) const
{
    assert(k > 0);
    assert(query_tensor.size() == tensor_store.tensors_dim);

    const auto min_candidates = (num_trees < 3) ? 2 * k : num_trees * k;

    std::vector<TreeNode*>                   current_nodes;
    std::vector<uint_fast32_t>               current_depths;
    robin_hood::unordered_flat_set<uint64_t> candidate_nearest_neighbors;

    current_nodes.reserve(num_trees);
    current_depths.reserve(num_trees);
    candidate_nearest_neighbors.reserve(min_candidates);

    // Descend on each tree and collect the initial candidates
    for (auto tree_idx = 0U; tree_idx < num_trees; ++tree_idx) {
        auto [leaf, depth] = trees[tree_idx]->descend(query_tensor);
        current_nodes.push_back(leaf);
        current_depths.push_back(depth);
        candidate_nearest_neighbors.insert(leaf->object_ids.begin(), leaf->object_ids.end());
    }

    auto current_maximum_depth = *std::max_element(current_depths.begin(), current_depths.end());

    // Continue traversing the trees until we have enough candidates or we reach the root
    while (current_maximum_depth > 0 && candidate_nearest_neighbors.size() < min_candidates) {
        for (auto tree_idx = 0U; tree_idx < num_trees; ++tree_idx) {
            if (current_depths[tree_idx] != current_maximum_depth) {
                continue;
            }

            const auto sibling             = current_nodes[tree_idx]->sibling();
            const auto sibling_descendants = Tree::descendants(sibling);
            current_nodes[tree_idx]        = current_nodes[tree_idx]->parent;
            --current_depths[tree_idx];

            candidate_nearest_neighbors.insert(sibling_descendants.begin(), sibling_descendants.end());
        }
        --current_maximum_depth;
    }

    // Compute similarities
    std::vector<std::pair<uint64_t, float>> nearest_neighbors;
    nearest_neighbors.reserve(candidate_nearest_neighbors.size());

    std::vector<float> tensor_buffer(tensor_store.tensors_dim);
    for (const auto& object_id : candidate_nearest_neighbors) {
        tensor_store.get(object_id, tensor_buffer);
        nearest_neighbors.emplace_back(object_id, similarity_fn(query_tensor, tensor_buffer));
    }

    // Sort by similarity
    auto result_size = std::min(k, static_cast<uint64_t>(nearest_neighbors.size())); // in MAC .size() is u32, and min cannot infer
    std::partial_sort(nearest_neighbors.begin(),
                      nearest_neighbors.begin() + result_size,
                      nearest_neighbors.end(),
                      [](const std::pair<uint64_t, float>& lhs, const std::pair<uint64_t, float>& rhs) {
                          return lhs.second < rhs.second;
                      });
    nearest_neighbors.resize(result_size);

    return nearest_neighbors;
}


std::unique_ptr<ForestIndexQueryIter> ForestIndex::query_iter(const std::vector<float>& query_tensor) const {
    assert(query_tensor.size() == tensor_store.tensors_dim);
    return std::make_unique<ForestIndexQueryIter>(query_tensor, *this);
}


void ForestIndex::serialize(const std::string& path) const
{
    std::fstream ofs(path, std::ios::out | std::ios::binary | std::ios::trunc);
    Serialization::write_uint64(ofs, num_trees);
    Serialization::write_uint64(ofs, max_bucket_size);
    Serialization::write_uint64(ofs, max_depth);

    // Serialize metric
    Serialization::write_uint8(ofs, static_cast<uint8_t>(metric_type));

    // Serialize each tree adjacently
    for (auto& tree : trees)
        tree->serialize(ofs);
    assert(ofs.good());
    ofs.close();
}


void ForestIndex::deserialize(const std::string& path)
{
    std::fstream ifs(path, std::ios::in | std::ios::binary);
    num_trees       = Serialization::read_uint64(ifs);
    max_bucket_size = Serialization::read_uint64(ifs);
    max_depth       = Serialization::read_uint64(ifs);

    // Deserialize and bind similarity function
    metric_type = static_cast<MetricType>(Serialization::read_uint8(ifs));
    switch (metric_type) {
    case MetricType::ANGULAR:
        similarity_fn = &Metric::cosine_distance;
        break;
    case MetricType::EUCLIDEAN: {
        similarity_fn = &Metric::euclidean_distance;
        break;
    }
    default: { // MetricType::MANHATTAN
        similarity_fn = &Metric::manhattan_distance;
        break;
    }
    }

    // Deserialize each tree
    for (uint_fast32_t i = 0; i < num_trees; ++i)
        trees.push_back(std::make_unique<Tree>(ifs, tensor_store));
    assert(ifs.good());
    ifs.close();
}
