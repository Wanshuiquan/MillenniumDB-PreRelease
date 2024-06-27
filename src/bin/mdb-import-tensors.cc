// #include <cstdio>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

#include "graph_models/quad_model/quad_model.h"
#include "graph_models/quad_model/quad_object_id.h"
#include "storage/buffer_manager.h"
#include "storage/index/tensor_store/tensor_store.h"
#include "storage/string_manager.h"
#include "third_party/cli11/CLI11.hpp"

using namespace LSH;

void build_tensor_store(const std::string& tensors_file_path,
                        const std::string& tensor_store_name,
                        uint64_t           tensors_dim) {
    // Initialize a new tensor store
    TensorStore tensor_store(tensor_store_name, tensors_dim);

    std::fstream tensors_fs(tensors_file_path, std::ios::in | std::ios::binary);
    std::string  line;
    std::string  cell;
    // Process tensors file line by line
    ObjectId           object_id;
    std::vector<float> tensor;
    tensor.resize(tensors_dim);

    std::cout << "Inserting tensors...\n";
    auto start = std::chrono::system_clock::now();
    while (std::getline(tensors_fs, line, '\n')) {
        std::stringstream ss(line);

        // ObjectId
        std::getline(ss, cell, ',');
        object_id = QuadObjectId::get_named_node(cell);

        // Tensor entries
        for (uint64_t i = 0; i < tensors_dim; i++) {
            std::getline(ss, cell, ',');
            tensor[i] = std::stof(cell);
        }
        tensor_store.insert(object_id.id, tensor);
    }
    auto end_insert      = std::chrono::system_clock::now();
    auto duration_insert = std::chrono::duration_cast<std::chrono::seconds>(end_insert - start);
    std::cout << "Insertion took: " << duration_insert.count() << " seconds for " << tensor_store.size() << " tensors\n";

    std::cout << "Serializing...\n";
    tensor_store.serialize();
    auto end_serialize = std::chrono::system_clock::now();
    auto duration_serialize = std::chrono::duration_cast<std::chrono::seconds>(end_serialize - end_insert);
    std::cout << "Serialization took: " << duration_serialize.count() << " seconds\n";
}


int main(int argc, char* argv[]) {
    std::string db_directory;
    std::string tensors_file;
    std::string tensor_store_name;
    uint64_t    tensors_dim = 1;

    CLI::App app("MillenniumDB Import Tensors");
    app.get_formatter()->column_width(35);
    app.option_defaults()->always_capture_default();

    app.add_option("db-directory", db_directory)
      ->description("path to an existing database directory")
      ->type_name("<path>")
      ->check(CLI::ExistingDirectory.description(""))
      ->required();

    app.add_option("tensors-file", tensors_file)
      ->description("file containing tensors to be imported")
      ->type_name("<path>")
      ->check(CLI::ExistingFile.description(""))
      ->required();

    app.add_option("tensor-store-name", tensor_store_name)
      ->description("name of the tensor store")
      ->type_name("<name>")
      ->required();

    app.add_option("tensors-dim", tensors_dim)
      ->description("dimension of the tensors")
      ->type_name("<num>")
      ->check(CLI::Range(1, 8162))
      ->required();

    CLI11_PARSE(app, argc, argv);

    if (tensor_store_name.empty()) {
        std::cerr << "Tensor store name cannot be empty\n";
        return EXIT_FAILURE;
    }

    std::cout << "Importing tensors to a QuadModel database\n";
    std::cout << "  db directory      : " << db_directory << "\n";
    std::cout << "  tensors file      : " << tensors_file << "\n";
    std::cout << "  tensor store name : " << tensor_store_name << "\n";
    std::cout << "  tensors dim       : " << tensors_dim << "\n";

    std::cout << "Initializing a QuadModel...\n";
    auto model_destroyer = QuadModel::init(db_directory,
                                           StringManager::DEFAULT_LOAD_STR,
                                           BufferManager::DEFAULT_VERSIONED_PAGES_BUFFER_SIZE,
                                           BufferManager::DEFAULT_PRIVATE_PAGES_BUFFER_SIZE,
                                           BufferManager::DEFAULT_UNVERSIONED_PAGES_BUFFER_SIZE,
                                           std::thread::hardware_concurrency());
    std::cout << "QuadModel initialized\n";

    if (TensorStore::exists(tensor_store_name)) {
        std::cerr << "A tensor store with the name \"" << tensor_store_name << "\" already exists\n";
        return EXIT_FAILURE;
    }

    build_tensor_store(tensors_file, tensor_store_name, tensors_dim);

    return EXIT_SUCCESS;
}