#include <iostream>

#include <thread>

#include "graph_models/exceptions.h"
#include "graph_models/quad_model/quad_model.h"
#include "misc/fatal_error.h"
#include "misc/logger.h"
#include "network/new-server/server.h"
#include "storage/buffer_manager.h"
#include "storage/file_manager.h"
#include "storage/filesystem.h"
#include "storage/index/tensor_store/lsh/forest_index.h"
#include "storage/string_manager.h"

#include "third_party/cli11/CLI11.hpp"


static uint64_t read_uint64(std::fstream& fs) {
    uint64_t res = 0;
    uint8_t  buf[8];

    fs.read((char*) buf, sizeof(buf));

    for (int i = 0; i < 8; i++) {
        res |= static_cast<uint64_t>(buf[i]) << (i * 8);
    }

    if (!fs.good()) {
        throw std::runtime_error("Error reading uint64");
    }

    return res;
}


void load_tensor_stores() {
    std::string tensor_stores_path = file_manager.get_file_path(TensorStore::TENSOR_STORES_DIR);
    if (Filesystem::is_directory(tensor_stores_path)) {
        robin_hood::unordered_set<std::string> tensor_store_names;
        // Get the stem of each file
        for (const auto& file : Filesystem::directory_iterator(tensor_stores_path)) {
            tensor_store_names.insert(file.path().filename().stem());
        }
        // Load the tensor stores
        for (const auto& tensor_store_name : tensor_store_names) {
            if (TensorStore::exists(tensor_store_name)) {
                std::cout << "Loading tensor store \"" << tensor_store_name << "\"...\n";
                auto tensor_store = std::make_unique<TensorStore>(tensor_store_name);
                std::cout << "Successfully loaded tensor store \"" << tensor_store_name << "\"\n";
                std::cout << "  size           : " << tensor_store->size() << std::endl;
                std::cout << "  tensors_dim    : " << tensor_store->tensors_dim << std::endl;
                if (tensor_store->forest_index != nullptr) {
                    std::cout << "  num_trees      : " << tensor_store->forest_index->num_trees << std::endl;
                    std::cout << "  max_bucket_size: " << tensor_store->forest_index->max_bucket_size << std::endl;
                    std::cout << "  max_depth      : " << tensor_store->forest_index->max_depth << std::endl;
                }
                quad_model.catalog().name2tensor_store.emplace(tensor_store_name, std::move(tensor_store));
            }
        }
    } else {
        std::cout << "No tensor stores found" << std::endl;
    }
}


int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    bool no_browser = false;

    auto timeout_seconds = NewServer::Server::DEFAULT_TIMEOUT_SECONDS;
    auto port            = NewServer::Server::DEFAULT_PORT;
    auto browser_port    = NewServer::Server::DEFAULT_BROWSER_PORT;
    auto max_threads     = std::thread::hardware_concurrency();

    uint64_t limit          = 0;
    uint64_t load_strings   = StringManager::DEFAULT_LOAD_STR;
    uint64_t versioned_pages_buffer   = BufferManager::DEFAULT_VERSIONED_PAGES_BUFFER_SIZE;
    uint64_t private_pages_buffer     = BufferManager::DEFAULT_PRIVATE_PAGES_BUFFER_SIZE;
    uint64_t unversioned_pages_buffer = BufferManager::DEFAULT_UNVERSIONED_PAGES_BUFFER_SIZE;

    std::string db_directory;
    std::string config_path;
    std::string path_mode;

    CLI::App app { "MillenniumDB Server" };
    app.get_formatter()->column_width(35);
    app.option_defaults()->always_capture_default();

    app.add_option("db-directory", db_directory)
      ->description("Database directory")
      ->type_name("<path>")
      ->check(CLI::ExistingDirectory.description(""))
      ->required();

    app.add_option("-p,--port", port)
      ->description("Server port")
      ->type_name("<port>")
      ->check(CLI::Range(1024, 65'535).description(""));

    app.add_option("--browser-port", browser_port)
      ->description("Browser interface port")
      ->type_name("<port>")
      ->check(CLI::Range(1024, 65'535).description(""));

    app.add_option("-t,--timeout", timeout_seconds)
      ->description("Timeout for query executions in seconds")
      ->type_name("<seconds>")
      ->check(CLI::Range(1, 36'000).description(""));

    app.add_option("-l,limit", limit)
      ->description("Maximum number of results to return\nPass 0 to set no limit")
      ->type_name("<num_records>")
      ->check(CLI::Range(static_cast<uint64_t>(0ULL), static_cast<uint64_t>(UINT64_MAX)).description(""));

    app.add_option("-j,--threads", max_threads)
      ->description("Number of worker threads")
      ->type_name("<number>")
      ->check(CLI::Range(1, 128).description(""));

    app.add_option("--load-strings", load_strings)
      ->description("Total amount of strings to pre-load\nAllows units such as MB and GB")
      ->option_text("<bytes> [2GB]")
      ->transform(CLI::AsSizeValue(false))
      ->check(CLI::Range(1024ULL * 1024, 1024ULL * 1024 * 1024 * 1024));

    app.add_option("--versioned-buffer", versioned_pages_buffer)
        ->description("Size of buffer for versioned pages shared between threads\nAllows units such as MB and GB")
        ->option_text("<bytes> [1GB]")
        ->transform(CLI::AsSizeValue(false))
        ->check(CLI::Range(1024ULL * 1024, 1024ULL * 1024 * 1024 * 1024));

    app.add_option("--private-buffer", private_pages_buffer)
        ->description("Size of private per-thread buffers,\nAllows units such as MB and GB")
        ->option_text("<bytes> [64MB]")
        ->transform(CLI::AsSizeValue(false))
        ->check(CLI::Range(1024ULL * 1024, 1024ULL * 1024 * 1024 * 1024));

    app.add_option("--unversioned-buffer", unversioned_pages_buffer)
        ->description("Size of buffer for unversioned pages shared between threads,\nAllows units such as MB and GB")
        ->option_text("<bytes> [128MB]")
        ->transform(CLI::AsSizeValue(false))
        ->check(CLI::Range(1024ULL * 1024, 1024ULL * 1024 * 1024 * 1024));

    app.add_option("--path-mode", path_mode)
      ->description("Path mode")
      ->type_name("<mode>")
      ->option_text("BFS|DFS")
      ->transform(CLI::Validator(
        [](std::string& input) -> std::string {
            input = CLI::detail::to_lower(input);
            if (input == "bfs" || input == "dfs")
                return "";
            else
                return std::string("Expecting BFS|DFS");
        },
        "Validates the path mode",
        "path_mode_validator"));

    app.add_flag("--no-browser", no_browser)
      ->description("Disable browser interface");

    CLI11_PARSE(app, argc, argv);

    if (!config_path.empty()) {
        if (!Filesystem::exists(config_path)) {
            std::cerr << "Configuration file does not exist: " << config_path << "\n";
            return EXIT_FAILURE;
        } else if (!Filesystem::is_regular_file(config_path)) {
            std::cerr << "Configuration file is not a file: " << config_path << "\n";
            return EXIT_FAILURE;
        }
        if (logger.read_config(config_path)) {
            return EXIT_FAILURE;
        }
    }

    const auto catalog_path = db_directory + "/catalog.dat";
    auto       catalog_fs   = std::fstream(catalog_path, std::ios::in | std::ios::binary);
    if (!catalog_fs.is_open()) {
        std::cerr << "Could not open catalog: " << catalog_path << "\n";
        return 1;
    }
    auto model_identifier = read_uint64(catalog_fs);

    try {
        switch (model_identifier) {
        case QuadCatalog::MODEL_ID: {
            std::cout << "Initializing Quad Model...\n";

            auto model_destroyer = QuadModel::init(
                db_directory,
                load_strings,
                versioned_pages_buffer,
                private_pages_buffer,
                unversioned_pages_buffer,
                max_threads
            );

            if (limit != 0) {
                quad_model.MAX_LIMIT = limit;
            }

            if (!path_mode.empty()) {
                quad_model.path_mode = path_mode == "bfs" ? PathMode::BFS : PathMode::DFS;
            }

            quad_model.catalog().print(std::cout);

            load_tensor_stores();

            NewServer::Server server;
            server.run(port, browser_port, !no_browser, max_threads, std::chrono::seconds(timeout_seconds));
            return EXIT_SUCCESS;
        }
        default:
            throw WrongModelException("Unknown model identifier: " + std::to_string(model_identifier));
        }
    }
    catch (const WrongModelException& e) {
        std::string error = std::string(e.what()) + ". Catalog may be corrupted";
        FATAL_ERROR(error);
    }
    catch (WrongCatalogVersionException& e) {
        std::string error = std::string(e.what()) + ". The database must be created again to work with this version";
        FATAL_ERROR(error);
    }

    return EXIT_SUCCESS;
}
