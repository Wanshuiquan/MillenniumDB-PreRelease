#include "request_handler.h"

#include <antlr4-runtime.h>

#include "network/new-server/response/rdf_response_writer.h"
#include "query/optimizer/rdf_model/streaming_executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/sparql_query_parser.h"

namespace NewServer {

class RdfRequestHandler : public RequestHandler {
public:
    RdfRequestHandler(StreamingSession& session) :
        RequestHandler(session, std::make_unique<RdfResponseWriter>(session)) { }

    ~RdfRequestHandler() = default;

    std::unique_ptr<Op> create_logical_plan(const std::string& query) override {
        antlr4::MyErrorListener error_listener;

        auto logical_plan = SPARQL::QueryParser::get_query_plan(query, &error_listener);
        return logical_plan;
    }

    std::unique_ptr<StreamingQueryExecutor> create_readonly_physical_plan(Op& logical_plan) override {
        SPARQL::StreamingExecutorConstructor query_optimizer;
        logical_plan.accept_visitor(query_optimizer);
        return std::move(query_optimizer.executor);
    }
};
} // namespace NewServer
