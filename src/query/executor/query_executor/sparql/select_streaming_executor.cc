#include "select_streaming_executor.h"

#include "query/executor/binding_iter_printer.h"

using namespace SPARQL;

SelectStreamingExecutor::SelectStreamingExecutor(std::unique_ptr<BindingIter> iter_,
                                                 std::vector<VarId>&&         projection_vars_) :
    iter { std::move(iter_) },
    projection_vars { std::move(projection_vars_) },
    result_count { 0 },
    binding { get_query_ctx().get_var_size() } {
    iter->begin(binding);
    has_next = iter->next();
}


const std::vector<VarId>& SelectStreamingExecutor::get_projection_vars() const {
    return projection_vars;
}


bool SelectStreamingExecutor::pull(MDBServer::StreamingResponseWriter& response_writer, uint64_t num_records) {
    if (num_records == 0) {
        num_records = UINT64_MAX;
    }

    while (has_next && num_records > 0) {
        response_writer.write_record(projection_vars, binding);
        ++result_count;
        --num_records;
        has_next = iter->next();
    }

    return has_next;
}


uint64_t SelectStreamingExecutor::get_result_count() const {
    return result_count;
}


void SelectStreamingExecutor::analyze(std::ostream& os, bool print_stats, int indent) const {
    os << std::string(indent, ' ') << "SelectStreamingExecutor()";
    BindingIterPrinter printer(os, print_stats, indent + 2);
    iter->accept_visitor(printer);
}