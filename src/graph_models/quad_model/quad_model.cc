#include "quad_model.h"

#include "query/executor/binding_iter/binding_expr/mql_binding_expr_printer.h"
#include "query/executor/binding_iter/paths/path_manager.h"
#include "query/executor/query_executor/mql/return_executor.h"
#include "storage/buffer_manager.h"
#include "storage/file_manager.h"
#include "storage/index/bplus_tree/bplus_tree.h"
#include "storage/index/random_access_table/random_access_table.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"

using namespace std;

// memory for the object
static typename std::aligned_storage<sizeof(QuadModel), alignof(QuadModel)>::type quad_model_buf;
// global object
QuadModel& quad_model = reinterpret_cast<QuadModel&>(quad_model_buf);


std::unique_ptr<ModelDestroyer> QuadModel::init(const std::string& db_folder,
                                                uint64_t           str_initial_populate_size,
                                                uint64_t           shared_buffer_size,
                                                uint64_t           private_buffer_size,
                                                uint64_t           string_hash_buffer_size,
                                                uint64_t           workers)
{
    new (&quad_model) QuadModel(db_folder,
                                str_initial_populate_size,
                                shared_buffer_size,
                                private_buffer_size,
                                string_hash_buffer_size,
                                workers);
    return std::make_unique<ModelDestroyer>([]() { quad_model.~QuadModel(); });
}


std::unique_ptr<BindingExprPrinter> create_quad_binding_expr_printer(std::ostream& os) {
    return std::make_unique<MQL::BindingExprPrinter>(os);
}


std::ostream& debug_print(std::ostream& os, ObjectId oid) {
    MQL::ReturnExecutor<MQL::ReturnType::CSV>::print(os, oid);
    return os;
}

QuadModel::QuadModel(const std::string& db_folder,
                     uint64_t           str_initial_populate_size,
                     uint64_t           shared_buffer_size,
                     uint64_t           private_buffer_size,
                     uint64_t           string_hash_buffer_size,
                     uint64_t           workers)
{
    FileManager::init(db_folder);
    BufferManager::init(shared_buffer_size, private_buffer_size, string_hash_buffer_size, workers);
    PathManager::init(workers);
    StringManager::init(str_initial_populate_size);
    TmpManager::init(workers);

    QueryContext::_debug_print = debug_print;
    QueryContext::create_binding_expr_printer = create_quad_binding_expr_printer;

    new (&catalog()) QuadCatalog("catalog.dat"); // placement new

    nodes = make_unique<BPlusTree<1>>("nodes");
    edge_table = make_unique<RandomAccessTable<3>>("edges.table");

    // Create BPT
    label_node = make_unique<BPlusTree<2>>("label_node");
    node_label = make_unique<BPlusTree<2>>("node_label");

    object_key_value = make_unique<BPlusTree<3>>("object_key_value");
    key_value_object = make_unique<BPlusTree<3>>("key_value_object");

    from_to_type_edge = make_unique<BPlusTree<4>>("from_to_type_edge");
    to_type_from_edge = make_unique<BPlusTree<4>>("to_type_from_edge");
    type_from_to_edge = make_unique<BPlusTree<4>>("type_from_to_edge");
    type_to_from_edge = make_unique<BPlusTree<4>>("type_to_from_edge");

    equal_from_to      = make_unique<BPlusTree<3>>("equal_from_to");
    equal_from_type    = make_unique<BPlusTree<3>>("equal_from_type");
    equal_to_type      = make_unique<BPlusTree<3>>("equal_to_type");
    equal_from_to_type = make_unique<BPlusTree<2>>("equal_from_to_type");

    equal_from_to_inverted   = make_unique<BPlusTree<3>>("equal_from_to_inverted");
    equal_from_type_inverted = make_unique<BPlusTree<3>>("equal_from_type_inverted");
    equal_to_type_inverted   = make_unique<BPlusTree<3>>("equal_to_type_inverted");
}


QuadModel::~QuadModel() {
    catalog().~QuadCatalog();

    nodes.reset();
    edge_table.reset();

    label_node.reset();
    node_label.reset();

    object_key_value.reset();
    key_value_object.reset();

    from_to_type_edge.reset();
    to_type_from_edge.reset();
    type_from_to_edge.reset();
    type_to_from_edge.reset();

    equal_from_to.reset();
    equal_from_type.reset();
    equal_to_type.reset();
    equal_from_to_type.reset();

    equal_from_to_inverted.reset();
    equal_from_type_inverted.reset();
    equal_to_type_inverted.reset();

    tmp_manager.~TmpManager();
    string_manager.~StringManager();
    path_manager.~PathManager();
    buffer_manager.~BufferManager();
    file_manager.~FileManager();
}
