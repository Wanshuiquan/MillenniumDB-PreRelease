#include "return_streaming_executor.h"

#include "query/executor/binding_iter_printer.h"

using namespace MQL;


ReturnStreamingExecutor::ReturnStreamingExecutor(
    std::unique_ptr<BindingIter> iter_,
    std::map<VarId, ObjectId>&&  set_vars_,
    std::vector<VarId>&&         projection_vars_,
    uint64_t                     limit_
) :
    iter { std::move(iter_) },
    set_vars { std::move(set_vars_) },
    projection_vars { std::move(projection_vars_) },
    limit { limit_ },
    result_count { 0 },
    binding { get_query_ctx().get_var_size() }
{
    for (auto&& [var, value] : set_vars) {
        binding.add(var, value);
    }
    iter->begin(binding);
    has_next = limit > 0 && iter->next();
}


const std::vector<VarId>& ReturnStreamingExecutor::get_projection_vars() const {
    return projection_vars;
}


bool ReturnStreamingExecutor::pull(MDBServer::StreamingResponseWriter& response_writer, uint64_t num_records) {
    if (num_records == 0) {
        num_records = UINT64_MAX;
    }

    while (has_next && num_records > 0) {
        response_writer.write_record(projection_vars, binding);
        ++result_count;
        --num_records;
        has_next = limit > result_count && iter->next();
    }

    return has_next;
}


uint64_t ReturnStreamingExecutor::get_result_count() const {
    return result_count;
}


void ReturnStreamingExecutor::analyze(std::ostream& os, bool print_stats, int indent) const {
    os << std::string(indent, ' ') << "ReturnStreamingExecutor()";
    BindingIterPrinter printer(os, print_stats, indent + 2);
    iter->accept_visitor(printer);
}
