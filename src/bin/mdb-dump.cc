#include <cctype>
#include <fstream>
#include <string>

#include "graph_models/inliner.h"
#include "graph_models/rdf_model/conversions.h" // TODO: review dates of sparql
#include "graph_models/quad_model/conversions.h"
#include "graph_models/quad_model/quad_model.h"
#include "query/executor/binding_iter/index_scan.h"
#include "query/executor/binding_iter/nested_loop_anti_join.h"
#include "query/executor/binding_iter/scan_ranges/assigned_var.h"
#include "query/executor/binding_iter/scan_ranges/scan_range.h"
#include "query/executor/binding_iter/scan_ranges/unassigned_var.h"
#include "query/executor/query_executor/json_ostream_escape.h"
#include "storage/buffer_manager.h"
#include "storage/index/bplus_tree/bplus_tree.h"
#include "third_party/cli11/CLI11.hpp"


static std::string oid2str(uint64_t oid) {
    return MQL::Conversions::to_lexical_str(ObjectId(oid));
}

// TODO: should not be here
static std::string oid2json_str(uint64_t oid, bool quoted) {
    std::stringstream ss;
    JsonOstreamEscape escaped_os_(ss);
    std::ostream      escaped_os(&escaped_os_);

    const auto mask        = oid & ObjectId::TYPE_MASK;
    const auto unmasked_id = oid & ObjectId::VALUE_MASK;

    switch (mask) {
    case ObjectId::MASK_NULL: {
        return "null";
    }
    case ObjectId::MASK_ANON_INLINED: {
        if (quoted) {
            ss << "\"_a" << unmasked_id << "\"";
        } else {
            ss << "_a" << unmasked_id;
        }
        return ss.str();
    }
    case ObjectId::MASK_NAMED_NODE_INLINED: {
        if (quoted) {
            ss << "\"";
            Inliner::print_string_inlined<7>(ss, unmasked_id);
            ss << "\"";
        } else {
            Inliner::print_string_inlined<7>(ss, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_NAMED_NODE_EXTERN: {
        if (quoted) {
            ss << "\"";
            string_manager.print(ss, unmasked_id);
            ss << "\"";
        } else {
            string_manager.print(ss, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_NAMED_NODE_TMP: {
        if (quoted) {
            ss << "\"";
            tmp_manager.print_str(ss, unmasked_id);
            ss << "\"";
        } else {
            tmp_manager.print_str(ss, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_STRING_SIMPLE_INLINED: {
        if (quoted) {
            ss << "\"";
            Inliner::print_string_inlined<7>(escaped_os, unmasked_id);
            ss << "\"";
        } else {
            Inliner::print_string_inlined<7>(escaped_os, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_STRING_SIMPLE_EXTERN: {
        if (quoted) {
            ss << "\"";
            string_manager.print(escaped_os, unmasked_id);
            ss << "\"";
        } else {
            string_manager.print(escaped_os, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_STRING_SIMPLE_TMP: {
        if (quoted) {
            ss << "\"";
            tmp_manager.print_str(escaped_os, unmasked_id);
            ss << "\"";
        } else {
            tmp_manager.print_str(escaped_os, unmasked_id);
        }
        return ss.str();
    }
    case ObjectId::MASK_NEGATIVE_INT: {
        int64_t i = (~oid) & 0x00FF'FFFF'FFFF'FFFFUL;
        ss << (i * -1);
        return ss.str();
    }
    case ObjectId::MASK_POSITIVE_INT: {
        int64_t i = unmasked_id;
        ss << i;
        return ss.str();
    }
    case ObjectId::MASK_FLOAT: {
        float    f;
        uint8_t* dest = reinterpret_cast<uint8_t*>(&f);
        dest[0]       = oid & 0xFF;
        dest[1]       = (oid >> 8) & 0xFF;
        dest[2]       = (oid >> 16) & 0xFF;
        dest[3]       = (oid >> 24) & 0xFF;

        ss << std::setprecision(std::numeric_limits<float>::digits10 + 1) << f;
        return ss.str();
    }
    case ObjectId::MASK_BOOL: {
        ss << (unmasked_id == 0 ? "false" : "true");
        return ss.str();
    }
    case ObjectId::MASK_EDGE: {
        if (quoted) {
            ss << "\"_e" << unmasked_id << "\"";
        } else {
            ss << "_e" << unmasked_id;
        }
        return ss.str();
    }
    case ObjectId::MASK_DT_TIME: {
        DateTime datetime = SPARQL::Conversions::unpack_date(ObjectId(oid));
        if (quoted) {
            ss << "\"";
            escaped_os << "time(\"";
            escaped_os << datetime.get_value_string();
            escaped_os << "\")";
            ss << "\"";
        } else {
            ss << "time(\"" << datetime.get_value_string() << "\")";
        }
        return ss.str();
    }
    case ObjectId::MASK_DT_DATE: {
        DateTime datetime = SPARQL::Conversions::unpack_date(ObjectId(oid));
        if (quoted) {
            ss << "\"";
            escaped_os << "date(\"";
            escaped_os << datetime.get_value_string();
            escaped_os << "\")";
            ss << "\"";
        } else {
            ss << "date(\"" << datetime.get_value_string() << "\")";
        }
        return ss.str();
    }
    case ObjectId::MASK_DT_DATETIME: {
        DateTime datetime = SPARQL::Conversions::unpack_date(ObjectId(oid));
        if (quoted) {
            ss << "\"";
            escaped_os << "dateTime(\"";
            escaped_os << datetime.get_value_string();
            escaped_os << "\")";
            ss << "\"";
        } else {
            ss << "dateTime(\"" << datetime.get_value_string() << "\")";
        }
        return ss.str();
    }
    case ObjectId::MASK_DT_DATETIMESTAMP: {
        DateTime datetime = SPARQL::Conversions::unpack_date(ObjectId(oid));
        if (quoted) {
            ss << "\"";
            escaped_os << "dateTimeStamp(\"";
            escaped_os << datetime.get_value_string();
            escaped_os << "\")";
            ss << "\"";
        } else {
            ss << "dateTimeStamp(\"" << datetime.get_value_string() << "\")";
        }
        return ss.str();
    }
    default:
        throw std::logic_error("Unmanaged mask in oid2json_str: " + std::to_string(mask));
    }
}



// Dump all the nodes with their properties grouped by label in JSON
void dump_nodes_json(const std::string& path) {
    bool interruption_requested = false;

    std::fstream fs(path, std::ios::out | std::ios::trunc);
    fs << "{";

    auto write_properties = [&](uint64_t object_id) -> void {
        auto object_key_value_it = quad_model.object_key_value->get_range(&interruption_requested,
                                                                          { object_id, 0, 0 },
                                                                          { object_id, UINT64_MAX, UINT64_MAX });
        auto object_key_value    = object_key_value_it.next();
        auto sep_property        = "";
        while (object_key_value != nullptr) {
            fs << sep_property << oid2json_str((*object_key_value)[1], true) << ":" << oid2json_str((*object_key_value)[2], true);
            sep_property     = ",";
            object_key_value = object_key_value_it.next();
        }
    };

    // Loop over all nodes sorted by label
    auto label_node_it =
      quad_model.label_node->get_range(&interruption_requested, { 0, 0 }, { UINT64_MAX, UINT64_MAX });
    auto     label_node = label_node_it.next();
    auto     sep_label  = "";
    uint64_t prev_label = ObjectId::NULL_ID;
    while (label_node != nullptr) {
        if ((*label_node)[0] != prev_label) {
            // Handle first occurrence of label
            fs << sep_label << oid2json_str((*label_node)[0], true) << ":{\n  ";
            fs << oid2json_str((*label_node)[1], true) << ":{";

            sep_label  = "\n},\n";
            prev_label = (*label_node)[0];
        } else {
            // Handle subsequent occurrence of label
            fs << ",\n  " << oid2json_str((*label_node)[1], true) << ":{";
        }
        // Write out properties
        write_properties((*label_node)[1]);
        fs << "}";
        label_node = label_node_it.next();
    }
    if (prev_label != ObjectId::NULL_ID) {
        // There were labelled nodes
        fs << "\n}";
    }

    // Loop over all nodes with no label
    if (prev_label == ObjectId::NULL_ID) {
        // No labelled nodes, no anti-join needed/possible
        auto node_it = quad_model.nodes->get_range(&interruption_requested, { 0 }, { UINT64_MAX });
        auto node    = node_it.next();
        bool output { false };
        if (node != nullptr) {
            // Handle first node
            fs << "\n\"\":{\n  " << oid2json_str((*node)[0], true) << ":{";
            write_properties((*node)[0]);
            fs << "}";
            output = true;
            node   = node_it.next();
        }
        while (node != nullptr) {
            fs << ",\n  " << oid2json_str((*node)[0], true) << ":{";
            write_properties((*node)[0]);
            fs << "}";
            node = node_it.next();
        }
        if (output) {
            // There were unlabelled nodes
            fs << "\n}";
        }
    } else {
        // There were labelled nodes, anti-join needed
        VarId   node_var { 0 };
        VarId   label_var { 1 };
        Binding binding { 2 };

        std::array<std::unique_ptr<ScanRange>, 1> lhs_ranges = { std::make_unique<UnassignedVar>(node_var) };
        std::array<std::unique_ptr<ScanRange>, 2> rhs_ranges = { std::make_unique<AssignedVar>(node_var),
                                                                 std::make_unique<UnassignedVar>(label_var) };

        auto lhs                = std::make_unique<IndexScan<1>>(*quad_model.nodes, std::move(lhs_ranges));
        auto rhs                = std::make_unique<IndexScan<2>>(*quad_model.node_label, std::move(rhs_ranges));
        auto unlabelled_node_it = std::make_unique<NestedLoopAntiJoin<false>>(std::move(lhs),
                                                                              std::move(rhs),
                                                                              std::vector<VarId> { node_var },
                                                                              std::vector<VarId> {},
                                                                              std::vector<VarId> {},
                                                                              std::vector<VarId> {},
                                                                              std::vector<VarId> { label_var });

        unlabelled_node_it->begin(binding);
        uint64_t node_id { 0 };
        if (unlabelled_node_it->next()) {
            // Handle first unlabelled node
            fs << ",\n\"\":{\n  ";
            node_id = binding[node_var].id;
            fs << oid2json_str(node_id, true) << ":{";
            write_properties(node_id);
            fs << "}";
        }
        while (unlabelled_node_it->next()) {
            // Handle subsequent unlabelled nodes
            node_id = binding[node_var].id;
            fs << ",\n  " << oid2json_str(node_id, true) << ":{";
            write_properties(node_id);
            fs << "}";
        }

        if (node_id != 0) {
            // There were unlabelled nodes
            fs << "\n}";
        }
    }

    fs << "\n}\n";
}


// Dump all the edges with their properties grouped by type in JSON
void dump_edges_json(const std::string& path) {
    bool interruption_requested = false;

    std::fstream fs(path, std::ios::out | std::ios::trunc);
    fs << "{";
    // Loop over all edges sorted by type
    auto     type_from_to_edge_it = quad_model.type_from_to_edge->get_range(&interruption_requested,
                                                                            { 0, 0, 0 },
                                                                            { UINT64_MAX, UINT64_MAX, UINT64_MAX });
    auto     type_from_to_edge    = type_from_to_edge_it.next();
    auto     sep_type             = "";
    uint64_t prev_type            = ObjectId::NULL_ID;
    while (type_from_to_edge != nullptr) {
        if ((*type_from_to_edge)[0] != prev_type) {
            // Handle first occurrence of type
            fs << sep_type << oid2json_str((*type_from_to_edge)[0], true) << ":[\n  {\"from\":";
            fs << oid2json_str((*type_from_to_edge)[1], true) << ",\"to\":";
            fs << oid2json_str((*type_from_to_edge)[2], true);
            sep_type  = "\n],\n";
            prev_type = (*type_from_to_edge)[0];
        } else {
            // Handle subsequent occurrence of type
            fs << ",\n  {\"from\":" << oid2json_str((*type_from_to_edge)[1], true);
            fs << ",\"to\":" << oid2json_str((*type_from_to_edge)[2], true);
        }
        // Write out properties if any
        auto object_key_value_it =
          quad_model.object_key_value->get_range(&interruption_requested,
                                                 { (*type_from_to_edge)[3], 0, 0 },
                                                 { (*type_from_to_edge)[3], UINT64_MAX, UINT64_MAX });
        auto object_key_value = object_key_value_it.next();
        if (object_key_value != nullptr) {
            fs << ",\"properties\":{";
            auto sep_property = "";
            while (object_key_value != nullptr) {
                fs << sep_property << oid2json_str((*object_key_value)[1], true) << ":"
                   << oid2json_str((*object_key_value)[2], true);
                sep_property     = ",";
                object_key_value = object_key_value_it.next();
            }
            fs << "}";
        }
        fs << "}";

        type_from_to_edge = type_from_to_edge_it.next();
    }

    if (prev_type != ObjectId::NULL_ID) {
        // Only when there were edges
        fs << "\n]";
    }

    fs << "\n}\n";
}


void dump_graph_quad_model(const std::string& path) {
    bool interruption_requested = false;

    std::fstream fs(path, std::ios::out | std::ios::trunc);

    // NODES
    auto node_it = quad_model.nodes->get_range(&interruption_requested, { 0 }, { UINT64_MAX });
    auto node    = node_it.next();
    while (node != nullptr) {
        fs << oid2str((*node)[0]);
        // Handle labels
        auto node_label_it =
          quad_model.node_label->get_range(&interruption_requested, { (*node)[0], 0 }, { (*node)[0], UINT64_MAX });
        auto node_label = node_label_it.next();
        while (node_label != nullptr) {
            auto label_name = oid2str((*node_label)[1]);
            label_name = label_name.substr(1, label_name.length() - 2);
            fs << " :" << label_name;
            node_label = node_label_it.next();
        }
        // Handle properties
        auto object_key_value_it = quad_model.object_key_value->get_range(&interruption_requested,
                                                                          { (*node)[0], 0, 0 },
                                                                          { (*node)[0], UINT64_MAX, UINT64_MAX });
        auto object_key_value = object_key_value_it.next();
        while (object_key_value != nullptr) {
            auto key_name = oid2str((*object_key_value)[1]);
            key_name = key_name.substr(1, key_name.length()-2);
            fs << " " << key_name << ":" << oid2str((*object_key_value)[2]);
            object_key_value = object_key_value_it.next();
        }
        fs << '\n';
        node = node_it.next();
    }

    // EDGES
    auto from_to_type_edge_it =
      quad_model.from_to_type_edge->get_range(&interruption_requested,
                                              { 0, 0, 0, 0 },
                                              { UINT64_MAX, UINT64_MAX, UINT64_MAX, UINT64_MAX });
    auto from_to_type_edge = from_to_type_edge_it.next();
    while (from_to_type_edge != nullptr) {
        // Handle edge and type
        fs << oid2str((*from_to_type_edge)[0]) << "->" << oid2str((*from_to_type_edge)[1]) << " :"
           << oid2str((*from_to_type_edge)[2]);
        // Handle properties
        auto object_key_value_it =
          quad_model.object_key_value->get_range(&interruption_requested,
                                                 { (*from_to_type_edge)[3], 0, 0 },
                                                 { (*from_to_type_edge)[3], UINT64_MAX, UINT64_MAX });
        auto object_key_value = object_key_value_it.next();
        while (object_key_value != nullptr) {
            auto key_name = oid2str((*object_key_value)[1]);
            key_name = key_name.substr(1, key_name.length()-2);
            fs << " " << key_name << ":" << oid2str((*object_key_value)[2]);
            object_key_value = object_key_value_it.next();
        }
        fs << '\n';
        from_to_type_edge = from_to_type_edge_it.next();
    }
}


enum class DumpFormat {
    QUAD,
    JSON
};


int main(int argc, char* argv[]) {
    std::string db_directory;
    std::string output_prefix_path;
    DumpFormat  output_format  = DumpFormat::QUAD;

    std::map<std::string, DumpFormat> str2format = {
        { "quad", DumpFormat::QUAD },
        { "json", DumpFormat::JSON }
    };

    CLI::App app { "MillenniumDB Import" };
    app.get_formatter()->column_width(35);
    app.option_defaults()->always_capture_default();

    app.add_option("database", db_directory)
      ->description("Database directory")
      ->type_name("<path>")
      ->check(CLI::ExistingDirectory.description(""))
      ->required();

    app.add_option("output-prefix-path", output_prefix_path)
      ->description("Output prefix path without extension")
      ->type_name("<path>")
      ->required();

    app.add_option("output-format", output_format)
      ->description("Output format")
      ->type_name("<format>")
      ->transform(CLI::CheckedTransformer(str2format, CLI::ignore_case))
      ->required();

    CLI11_PARSE(app, argc, argv);

    auto model_destroyer = QuadModel::init(
        db_directory,
        StringManager::DEFAULT_LOAD_STR,
        BufferManager::DEFAULT_VERSIONED_PAGES_BUFFER_SIZE,
        BufferManager::DEFAULT_PRIVATE_PAGES_BUFFER_SIZE,
        BufferManager::DEFAULT_UNVERSIONED_PAGES_BUFFER_SIZE,
        1
    );

    QueryContext qc;
    QueryContext::set_query_ctx(&qc);

    switch (output_format) {
    case DumpFormat::QUAD:
        std::cout << "Writing a QuadModel dump..." << std::endl;
        dump_graph_quad_model(output_prefix_path + ".qm");
        break;
    default: // DumpFormat::JSON:
        std::cout << "Writing a JSON dump..." << std::endl;
        dump_nodes_json(output_prefix_path + ".nodes.json");
        dump_edges_json(output_prefix_path + ".edges.json");
        break;
    }
    std::cout << "Dump done" << std::endl;

    return 0;
}
