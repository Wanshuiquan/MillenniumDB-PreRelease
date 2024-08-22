#pragma once

#include "query/executor/binding_iter.h"
#include "query/executor/query_executor/streaming_query_executor.h"

namespace MQL {
/**
 * Executor for DESCRIBE queries which writes a single "hand-made" record with the
 * projection variables: labels, properties, outgoing and incoming
 */
class DescribeStreamingExecutor : public StreamingQueryExecutor {
public:
    DescribeStreamingExecutor(std::unique_ptr<BindingIter> node_label_iter,
                              std::unique_ptr<BindingIter> key_value_iter,
                              std::unique_ptr<BindingIter> from_to_type_edge_iter,
                              std::unique_ptr<BindingIter> to_type_from_edge_iter,
                              uint64_t                     labels_limit,
                              uint64_t                     properties_limit,
                              uint64_t                     outgoing_limit,
                              uint64_t                     incoming_limit,
                              std::vector<VarId>&&         virtual_vars,
                              ObjectId                     object_id);

    const std::vector<VarId>& get_projection_vars() const override;

    bool pull(MDBServer::StreamingResponseWriter& response_writer, uint64_t num_records) override;

    uint64_t get_result_count() const override;

    void analyze(std::ostream&, bool print_stats = false, int indent = 0) const override;

private:
    std::unique_ptr<BindingIter> node_label_iter;
    std::unique_ptr<BindingIter> key_value_iter;
    std::unique_ptr<BindingIter> from_to_type_edge_iter;
    std::unique_ptr<BindingIter> to_type_from_edge_iter;

    uint64_t labels_limit;
    uint64_t properties_limit;
    uint64_t outgoing_limit;
    uint64_t incoming_limit;

    // Internal variables used in the operator
    std::vector<VarId> virtual_vars;

    // The ObjectId of the describe query
    ObjectId object_id;

    std::vector<VarId> projection_vars;

    Binding binding;

    bool finished;
};
} // namespace MQL
