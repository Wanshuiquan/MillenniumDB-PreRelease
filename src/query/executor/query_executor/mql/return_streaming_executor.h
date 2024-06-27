#pragma once

#include <map>

#include "query/executor/binding_iter.h"
#include "query/executor/query_executor/streaming_query_executor.h"

namespace MQL {
/**
 * Executor for MATCH queries which writes records to the Response Writer
 */
class ReturnStreamingExecutor : public StreamingQueryExecutor {
public:
    ReturnStreamingExecutor(std::unique_ptr<BindingIter> iter,
                            std::map<VarId, ObjectId>&&  set_vars,
                            std::vector<VarId>&&         projection_vars,
                            uint64_t                     limit);

    const std::vector<VarId>& get_projection_vars() const override;

    bool pull(NewServer::ResponseWriter& response_writer, uint64_t num_records) override;

    uint64_t get_result_count() const override;

    void analyze(std::ostream&, bool print_stats = false, int indent = 0) const override;

private:
    std::unique_ptr<BindingIter> iter;

    std::map<VarId, ObjectId> set_vars;

    std::vector<VarId> projection_vars;

    uint64_t limit;

    uint64_t result_count;

    // Set to true when there is a binding available that has not been written yet
    bool has_next;

    Binding binding;
};
} // namespace MQL