#include "forest_index.h"

#include <algorithm>
#include <fstream>
#include <unordered_set>

#include "graph_models/object_id.h"
#include "graph_models/quad_model/conversions.h"
#include "query/exceptions.h"
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

    // Initialize containers and variables
    auto num_trees = trees.size();
    auto search_k  = (num_trees < 3) ? 2 * k : num_trees * k;

    std::vector<TreeNode*> nodes;
    std::vector<uint64_t>  depths;
    std::vector<uint64_t>  candidate_nearest_neighbors;

    nodes.reserve(num_trees);
    depths.reserve(num_trees);
    candidate_nearest_neighbors.reserve(search_k);

    for (auto it = trees.begin(); it < trees.end(); ++it) {
        auto [leaf, depth] = (*it)->descend(query_tensor);
        nodes.push_back(leaf);
        depths.push_back(depth);
        candidate_nearest_neighbors.insert(
            candidate_nearest_neighbors.end(),
            leaf->object_ids.begin(),
            leaf->object_ids.end()
        );
    }
    auto current_maximum_depth = *std::max_element(depths.begin(), depths.end());

    // Get the candidate nearest neighbors
    while (current_maximum_depth > 0 && candidate_nearest_neighbors.size() < search_k) {
        for (uint_fast32_t i = 0; i < nodes.size(); ++i) {
            if (depths[i] != current_maximum_depth)
                continue;

            const auto sibling             = nodes[i]->sibling();
            const auto sibling_descendants = Tree::descendants(sibling);
            nodes[i]                       = nodes[i]->parent;
            --depths[i];
            candidate_nearest_neighbors.insert(
                candidate_nearest_neighbors.end(),
                sibling_descendants.begin(),
                sibling_descendants.end()
            );
        }
        --current_maximum_depth;
    }

    // Sort by object_id to avoid duplicates
    std::sort(candidate_nearest_neighbors.begin(), candidate_nearest_neighbors.end());

    // Compute similarities
    std::vector<std::pair<uint64_t, float>> nearest_neighbors;
    nearest_neighbors.reserve(k);
    uint64_t previous_object_id = ObjectId::NULL_ID;
    std::vector<float> tensor_buffer(tensor_store.tensors_dim);
    for (const auto& object_id : candidate_nearest_neighbors) {
        if (object_id == previous_object_id)
            continue;
        tensor_store.get(object_id, tensor_buffer);
        nearest_neighbors.emplace_back(object_id, similarity_fn(query_tensor, tensor_buffer));
        previous_object_id = object_id;
    }

    // Sort by similarity
    auto result_size = std::min(k, static_cast<uint64_t>(nearest_neighbors.size()));
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
