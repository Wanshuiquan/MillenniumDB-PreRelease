/*
There are four different tests, one for each type of search:
- Exact Search
- Prefix Search
- Error Exact Search
- Error Prefix Search

We start by inserting the words (words.txt) into the trie and then querying for each one of the searches.
Then, the results are sorted in alphabetical order and compared with the results files that
were calculated by brute force.

Queries Files:
- search_queries.txt (Normal searches)
- error_search_queries.txt (Error searches)

Results Files:
- exact_search_results.txt
- prefix_search_results.txt
- error_exact_search_results.txt
- error_prefix_search_results.txt

* All files are in "tests/trie/"
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

#include "storage/buffer_manager.h"
#include "storage/file_manager.h"
#include "storage/filesystem.h"
#include "storage/index/text_search/trie.h"

std::string normalizeString(const std::string& str) {
    std::string res(str.size(), ' ');
    std::transform(str.begin(), str.end(), res.begin(), ::tolower);
    return res;
}


std::ostream& operator<<(std::ostream& os, const std::vector<std::string> vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if (i != 0) os << ", ";
        os << '"' << vec[i] << '"';
    }
    os << "]";
    return os;
}


bool equal(std::string test, std::string query, std::vector<std::string> expected, std::vector<std::string>& received) {
    std::sort(std::begin(expected), std::end(expected));
    std::sort(std::begin(received), std::end(received));

    auto equal = true;

    if (expected.size() != received.size()) {
        equal = false;
    } else {
        for (size_t i = 0; i < expected.size(); i++) {
            if (strcmp(expected[i].c_str(), received[i].c_str())) {
                equal = false;
            }
        }
    }

    if (!equal) {
        std::cout << "FAILED " << test << "\n";
        std::cout << "Query: " << query << "\n";
        std::cout << "Expected" << expected << "\n";
        std::cout << "Received" << received << std::endl;
    }

    return equal;
}


int main() {
    std::string query;
    std::filesystem::path test_data_dir = "tests/trie";

    if (!std::filesystem::is_directory(test_data_dir)) {
        test_data_dir = "../../../tests/trie";
        if (!std::filesystem::is_directory(test_data_dir)) {
            std::cerr << "Could not find test directory\n";
            std::cerr << "Current directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }
    }

    std::filesystem::path db_folder = test_data_dir / "tmp-db";

    if (Filesystem::exists(db_folder)) {
        std::filesystem::remove_all(db_folder);
    }

    // Init of FileManager and BufferManager
    FileManager::init(db_folder);
    BufferManager::init(BufferManager::DEFAULT_SHARED_BUFFER_POOL_SIZE, 0, 0);

    {
        // Init Trie
        TextSearch::Trie trie("test_trie");

        std::unordered_map<uint64_t, std::vector<std::string>> words_map;

        // Input file (Insert words)
        std::ifstream input_file(test_data_dir / "words.txt");

        while (std::getline(input_file, query)) {
            auto normalized = normalizeString(query);
            auto node_id = trie.insert_string(normalized);
            words_map[node_id].push_back(query);
        }


        // ┌───────────────┐
        // │ Test 1: Match │
        // └───────────────┘
        std::ifstream queries_file(test_data_dir / "search_queries.txt");
        std::ifstream expected_file(test_data_dir / "Results/exact_search_results.txt");

        while (std::getline(queries_file, query)) {
            std::vector<std::string> received;

            auto iter = trie.get_iter_match(normalizeString(query));

            while (iter->next()) {
                auto received_strings = words_map[iter->get_node_id()];
                for (auto& str : received_strings) {
                    received.push_back(str);
                }
            }


            std::vector<std::string> expected;
            std::string line;
            std::getline(expected_file, line);
            std::stringstream stream(line);
            std::string item;
            while (stream >> item) expected.push_back(item);

            if (!equal("Match", query, expected, received)) {
                return EXIT_FAILURE;
            }
        }
        std::cout << "TEST 1 (Match) CORRECT" << std::endl;


        // ┌────────────────┐
        // │ Test 2: Prefix │
        // └────────────────┘
        queries_file = std::ifstream(test_data_dir / "search_queries.txt");
        expected_file = std::ifstream(test_data_dir / "Results/prefix_search_results.txt");

        if (queries_file.fail()) {
            std::cerr << "Could not open search_queries.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        if (expected_file.fail()) {
            std::cerr << "Could not open prefix_search_results.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        while (std::getline(queries_file, query)) {
            std::vector<std::string> received;

            auto iter = trie.get_iter_prefix(normalizeString(query));

            while (iter->next()) {
                auto received_strings = words_map[iter->get_node_id()];
                for (auto& str : received_strings) {
                    received.push_back(str);
                }
            }


            std::vector<std::string> expected;
            std::string line;
            std::getline(expected_file, line);
            std::stringstream stream(line);
            std::string item;
            while (stream >> item) expected.push_back(item);

            if (!equal("Prefix", query, expected, received)) {
                return EXIT_FAILURE;
            }
        }
        std::cout << "TEST 2 (Prefix) CORRECT" << std::endl;


        // ┌─────────────────────┐
        // │ Test 3: Match Error │
        // └─────────────────────┘
        queries_file = std::ifstream(test_data_dir / "error_search_queries.txt");
        expected_file = std::ifstream(test_data_dir / "Results/error_exact_search_results.txt");

        if (queries_file.fail()) {
            std::cerr << "Could not open error_search_queries.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        if (expected_file.fail()) {
            std::cerr << "Could not open error_exact_search_results.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        while (std::getline(queries_file, query)) {
            std::vector<std::string> received;
            std::vector<std::string> expected;

            std::string line;
            std::string item;
            std::getline(expected_file, line);
            std::stringstream stream(line);
            while (stream >> item) expected.push_back(item);

            auto iter = trie.get_iter_match_error(normalizeString(query), 3);

            while (iter->next()) {
                auto received_strings = words_map[iter->get_node_id()];
                for (auto& str : received_strings) {
                    received.push_back(str);
                }
            }

            if (!equal("Match Error", query, expected, received)) {
                return EXIT_FAILURE;
            }
        }
        std::cout << "TEST 3 (Match Error) CORRECT" << std::endl;


        // ┌──────────────────────┐
        // │ Test 4: Prefix Error │
        // └──────────────────────┘
        queries_file = std::ifstream(test_data_dir / "error_search_queries.txt");
        expected_file = std::ifstream(test_data_dir / "Results/error_prefix_search_results.txt");

        if (queries_file.fail()) {
            std::cerr << "Could not open error_search_queries.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        if (expected_file.fail()) {
            std::cerr << "Could not open error_exact_search_results.txt\n";
            std::cerr << "Current working directory: " << std::filesystem::current_path() << "\n";
            return EXIT_FAILURE;
        }

        while (std::getline(queries_file, query)) {
            std::vector<std::string> received;
            std::vector<std::string> expected;

            std::string line;
            std::string item;
            std::getline(expected_file, line);
            std::stringstream stream(line);
            while (stream >> item) expected.push_back(item);

            auto iter = trie.get_iter_prefix_error(normalizeString(query), 3);

            while (iter->next()) {
                auto received_strings = words_map[iter->get_node_id()];
                for (auto& str : received_strings) {
                    received.push_back(str);
                }
            }

            if (!equal("Prefix Error", query, expected, received)) {
                return EXIT_FAILURE;
            }
        }
        std::cout << "TEST 4 (Prefix Error) CORRECT" << std::endl;
    }

    // Destruction of BufferManager and FileManager
    buffer_manager.~BufferManager();
    file_manager.~FileManager();

    return 0;
}