#include "rdf_model.h"

#include "graph_models/rdf_model/conversions.h"
#include "query/executor/binding_iter/binding_expr/sparql_binding_expr_printer.h"
#include "query/executor/binding_iter/paths/path_manager.h"
#include "storage/buffer_manager.h"
#include "storage/file_manager.h"
#include "storage/index/bplus_tree/bplus_tree.h"
#include "storage/string_manager.h"
#include "storage/tmp_manager.h"

using namespace std;

// memory for the object
static typename std::aligned_storage<sizeof(RdfModel), alignof(RdfModel)>::type rdf_model_buf;
// global object
RdfModel& rdf_model = reinterpret_cast<RdfModel&>(rdf_model_buf);


std::unique_ptr<ModelDestroyer> RdfModel::init(const std::string& db_folder,
                                               uint64_t           str_initial_populate_size,
                                               uint64_t           shared_buffer_size,
                                               uint64_t           private_buffer_size,
                                               uint64_t           str_hash_buffer_size,
                                               uint64_t           max_threads)
{
    new (&rdf_model) RdfModel(
        db_folder,
        str_initial_populate_size,
        shared_buffer_size,
        private_buffer_size,
        str_hash_buffer_size,
        max_threads);
    return std::make_unique<ModelDestroyer>([]() { rdf_model.~RdfModel(); });
}


std::unique_ptr<BindingExprPrinter> create_rdf_binding_expr_printer(std::ostream& os) {
    return std::make_unique<SPARQL::BindingExprPrinter>(os);
}


RdfModel::RdfModel(const std::string& db_folder,
                   uint64_t           str_initial_populate_size,
                   uint64_t           shared_buffer_size,
                   uint64_t           private_buffer_size,
                   uint64_t           str_hash_buffer_size,
                   uint64_t           workers)
{
    FileManager::init(db_folder);
    BufferManager::init(shared_buffer_size, private_buffer_size, str_hash_buffer_size, workers);
    PathManager::init(workers);
    StringManager::init(str_initial_populate_size);
    TmpManager::init(workers);

    QueryContext::_debug_print = SPARQL::Conversions::debug_print;
    QueryContext::create_binding_expr_printer = create_rdf_binding_expr_printer;

    new (&catalog()) RdfCatalog("catalog.dat"); // placement new

    spo = make_unique<BPlusTree<3>>("spo");
    pos = make_unique<BPlusTree<3>>("pos");
    osp = make_unique<BPlusTree<3>>("osp");

    if (catalog().permutations >= 4) {
        pso = make_unique<BPlusTree<3>>("pso");
    }

    if (catalog().permutations == 6) {
        sop = make_unique<BPlusTree<3>>("sop");
        ops = make_unique<BPlusTree<3>>("ops");
    }

    equal_spo = make_unique<BPlusTree<1>>("equal_spo");
    equal_sp  = make_unique<BPlusTree<2>>("equal_sp");
    equal_so  = make_unique<BPlusTree<2>>("equal_so");
    equal_po  = make_unique<BPlusTree<2>>("equal_po");

    equal_sp_inverted = make_unique<BPlusTree<2>>("equal_sp_inverted");
    equal_so_inverted = make_unique<BPlusTree<2>>("equal_so_inverted");
    equal_po_inverted = make_unique<BPlusTree<2>>("equal_po_inverted");
}


RdfModel::~RdfModel() {
    // Must destroy everything before buffer and file manager
    catalog().~RdfCatalog();

    spo.reset();
    pos.reset();
    osp.reset();
    pso.reset();
    sop.reset();
    ops.reset();

    equal_spo.reset();
    equal_sp.reset();
    equal_so.reset();
    equal_po.reset();
    equal_sp_inverted.reset();
    equal_so_inverted.reset();
    equal_po_inverted.reset();

    tmp_manager.~TmpManager();
    string_manager.~StringManager();
    path_manager.~PathManager();
    buffer_manager.~BufferManager();
    file_manager.~FileManager();
}
