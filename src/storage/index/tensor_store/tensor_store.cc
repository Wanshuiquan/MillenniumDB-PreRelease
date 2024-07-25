#include "tensor_store.h"

#include <cassert>
#include <cstdio>
#include <fstream>
#include <stdexcept>

#include "query/exceptions.h"
#include "storage/file_manager.h"
#include "storage/filesystem.h"
#include "storage/index/tensor_store/lsh/forest_index.h"
#include "storage/index/tensor_store/lsh/forest_index_query_iter.h"
#include "storage/index/tensor_store/lsh/tree.h"
#include "storage/index/tensor_store/serialization.h"
#include "storage/index/tensor_store/tensor_buffer_manager.h"

TensorStore::TensorStore(const std::string& name_, uint64_t tensors_dim_, uint64_t tensor_page_buffer_size_in_bytes) :
    name(name_),
    tensors_dim(tensors_dim_),
    tensors_file_id(FileId::UNASSIGNED),
    mapping_path(file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name_ + ".mapping")),
    index_path(file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name_ + ".index")) {
    if (tensors_dim < 1)
        throw std::invalid_argument("Tensor dimension must be at least 1");

    // Create the tensor stores directory if it does not exist
    std::string tensor_stores_path = file_manager.get_file_path(TENSOR_STORES_DIR);
    if (!Filesystem::is_directory(tensor_stores_path))
        Filesystem::create_directories(tensor_stores_path);

    // Create a new tensors file
    std::string tensors_path = file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name + ".tensors");
    if (Filesystem::is_regular_file(tensors_path))
        std::remove(tensors_path.c_str());
    tensors_file_id = file_manager.get_file_id(TENSOR_STORES_DIR + "/" + name + ".tensors");

    // Create a new mapping file with the initial header
    std::fstream ofs;
    ofs.open(mapping_path, std::ios::out | std::ios::binary | std::ios::trunc);
    Serialization::write_bool(ofs, false);
    Serialization::write_uint64(ofs, tensors_dim);
    Serialization::write_uint64(ofs, 0ULL);
    ofs.close();

    set_tensor_buffer_manager(tensor_page_buffer_size_in_bytes, false);
}


TensorStore::TensorStore(const std::string& name_, uint64_t tensor_buffer_page_size_in_bytes, bool preload) :
    name(name_),
    tensors_file_id (FileId::UNASSIGNED),
    mapping_path    (file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name_ + ".mapping")),
    index_path      (file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name_ + ".index")) {
    if (!exists(name))
        throw std::invalid_argument("Tensor store " + name + " does not exist");

    // Load tensors file
    tensors_file_id = file_manager.get_file_id(TENSOR_STORES_DIR + "/" + name + ".tensors");

    // Load object_id2tensor_offset and forest_index (if it exists) from disk
    deserialize();
    assert(tensors_dim > 0);

    set_tensor_buffer_manager(tensor_buffer_page_size_in_bytes, preload);
}


TensorStore::~TensorStore() {
    // Save object_id2tensor_offset and forest_index to disk
    // Disabled because no updates will occur during server execution
    // serialize();
}


bool TensorStore::exists(const std::string& name) {
    if (!Filesystem::is_regular_file(file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name + ".tensors")))
        return false;
    else if (!Filesystem::is_regular_file(file_manager.get_file_path(TENSOR_STORES_DIR + "/" + name + ".mapping")))
        return false;
    return true;
}


bool TensorStore::contains(uint64_t object_id) const {
    return object_id2tensor_offset.find(object_id) != object_id2tensor_offset.end();
}


bool TensorStore::get(uint64_t object_id, std::vector<float>& vec) const {
    assert(vec.size() == tensors_dim && "Vector size must match tensor dimension");
    auto it = object_id2tensor_offset.find(object_id);
    if (it == object_id2tensor_offset.end())
        return false;

    auto vec_bytes      = reinterpret_cast<char*>(vec.data());
    auto vec_bytes_size = vec.size() * sizeof(float);

    // Start from the corresponding page and offset
    auto page_number         = it->second / TensorPage::SIZE;
    auto page_offset         = it->second % TensorPage::SIZE;
    TensorPage* current_page = &tensor_buffer_manager->get_page(page_number);

    // Read the tensor directly to the vector bytes
    size_t remaining = sizeof(float) * vec.size();
    while (remaining > 0) {
        size_t max_read   = (TensorPage::SIZE - page_offset);
        char* current_ptr = current_page->get_bytes() + page_offset;
        if (remaining < max_read) {
            // All the remaining bytes are in the current page
            std::memcpy(&vec_bytes[vec_bytes_size - remaining], current_ptr, remaining);
            tensor_buffer_manager->unpin(*current_page);
            break;
        } else {
            // There are remaining bytes in the next page
            std::memcpy(&vec_bytes[vec_bytes_size - remaining], current_ptr, max_read);
            tensor_buffer_manager->unpin(*current_page);
            remaining -= max_read;
            ++page_number;
            current_page = &tensor_buffer_manager->get_page(page_number);
        }
    }

    return true;
}


void TensorStore::insert(uint64_t object_id, const std::vector<float>& tensor) {
    assert(tensor.size() == tensors_dim);
    uint64_t tensor_offset;
    auto     it = object_id2tensor_offset.find(object_id);
    if (it != object_id2tensor_offset.end()) {
        // Replace an existing tensor
        tensor_offset = it->second;
    } else {
        // Insert a new tensor
        tensor_offset = object_id2tensor_offset.size() * sizeof(float) * tensors_dim;
        object_id2tensor_offset.insert({ object_id, tensor_offset });
    }

    auto vec_bytes      = reinterpret_cast<const char*>(tensor.data());
    auto vec_bytes_size = tensor.size() * sizeof(float);

    // Start from the corresponding page and offset
    auto page_number         = tensor_offset / TensorPage::SIZE;
    auto page_offset         = tensor_offset % TensorPage::SIZE;
    TensorPage* current_page = &tensor_buffer_manager->get_or_append_page(page_number);

    // Write the tensor directly from the vector bytes
    size_t remaining = sizeof(float) * tensor.size();
    while (remaining > 0) {
        size_t max_write  = (TensorPage::SIZE - page_offset);
        char* current_ptr = current_page->get_bytes() + page_offset;
        if (remaining < max_write) {
            // All the remaining bytes fit in the current page
            std::memcpy(current_ptr, &vec_bytes[vec_bytes_size - remaining], remaining);
            current_page->make_dirty();
            tensor_buffer_manager->unpin(*current_page);
            break;
        } else {
            // There are remaining bytes that wont fit in the current page
            std::memcpy(current_ptr, &vec_bytes[vec_bytes_size - remaining], max_write);
            current_page->make_dirty();
            tensor_buffer_manager->unpin(*current_page);
            remaining -= max_write;
            ++page_number;
            current_page = &tensor_buffer_manager->get_or_append_page(page_number);
        }
    }
}


size_t TensorStore::size() const {
    return object_id2tensor_offset.size();
}


void TensorStore::build_forest_index(LSH::MetricType metric_type, uint64_t num_trees, uint64_t max_bucket_size, uint64_t max_depth) {
    if (size() == 0)
        throw std::logic_error("Cannot build forest index because the store is empty!");
    forest_index = std::make_unique<LSH::ForestIndex>(*this, metric_type, num_trees, max_bucket_size, max_depth);
    forest_index->build();

}


std::vector<std::pair<uint64_t, float>>
  TensorStore::query_top_k(const std::vector<float>& query_tensor, int64_t k) const {
    if (forest_index == nullptr)
        throw LogicException("Forest index is not built for this tensor store \"" + name + "\"");
    if (k <= 0)
        throw LogicException("k must be positive");
    return forest_index->query_top_k(query_tensor, uint64_t(k));
}


std::unique_ptr<LSH::ForestIndexQueryIter> TensorStore::query_iter(const std::vector<float>& query_tensor) const {
    if (forest_index == nullptr)
        throw LogicException("Forest index is not built for this tensor store \"" + name + "\"");
    return forest_index->query_iter(query_tensor);
}


void TensorStore::serialize() const {
    // Serialize mapping
    std::fstream ofs(mapping_path, std::ios::out | std::ios::binary | std::ios::trunc);
    Serialization::write_uint64(ofs, tensors_dim);
    Serialization::write_uint64(ofs, object_id2tensor_offset.size());
    Serialization::write_uint642uint64_unordered_map(ofs, object_id2tensor_offset);
    ofs.close();

    // Serialize forest index
    if (forest_index != nullptr)
        forest_index->serialize(index_path);
}


void TensorStore::deserialize() {
    // Deserialize mapping
    std::fstream ifs(mapping_path, std::ios::in | std::ios::binary);
    tensors_dim                       = Serialization::read_uint64(ifs);
    auto object_id2tensor_offset_size = Serialization::read_uint64(ifs);
    object_id2tensor_offset = Serialization::read_uint642uint64_unordered_map(ifs, object_id2tensor_offset_size);
    ifs.close();

    // Deserialize forest index
    if (Filesystem::is_regular_file(index_path))
        forest_index = std::make_unique<LSH::ForestIndex>(index_path, *this);
}


void TensorStore::set_tensor_buffer_manager(uint64_t tensor_buffer_page_size_in_bytes, bool preload) {
    const auto tensor_page_buffer_pool_size = tensor_buffer_page_size_in_bytes / TensorPage::SIZE;
    tensor_buffer_manager= std::make_unique<TensorBufferManager>(tensors_file_id, tensor_page_buffer_pool_size, preload);
}
