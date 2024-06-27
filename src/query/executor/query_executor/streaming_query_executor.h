#pragma once

#include "network/new-server/response/response_writer.h"


class StreamingQueryExecutor {
public:
    virtual ~StreamingQueryExecutor() = default;

    // Returns the projection variables
    virtual const std::vector<VarId>& get_projection_vars() const = 0;

    // Write at most num_records of the query to the given ResponseWriter
    virtual bool pull(NewServer::ResponseWriter& response_writer, uint64_t num_records) = 0;

    // Returns how many results were obtained so far
    virtual uint64_t get_result_count() const = 0;

    // Analyze the query executor
    virtual void analyze(std::ostream&, bool print_stats, int indent = 0) const = 0;
};