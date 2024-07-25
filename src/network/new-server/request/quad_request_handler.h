#include "request_handler.h"

#include <antlr4-runtime.h>

#include "network/new-server/response/quad_response_writer.h"
#include "query/optimizer/quad_model/streaming_executor_constructor.h"
#include "query/parser/grammar/error_listener.h"
#include "query/parser/mql_query_parser.h"

namespace NewServer {

class QuadRequestHandler : public RequestHandler {
public:
    QuadRequestHandler(StreamingSession& session) :
        RequestHandler(session, std::make_unique<QuadResponseWriter>(session)) { }

    ~QuadRequestHandler() = default;

    std::unique_ptr<Op> create_logical_plan(const std::string& query) override {
        antlr4::MyErrorListener error_listener;

        auto logical_plan = MQL::QueryParser::get_query_plan(query, &error_listener);
        return logical_plan;
    }

    std::unique_ptr<StreamingQueryExecutor> create_readonly_physical_plan(Op& logical_plan) override {
        MQL::StreamingExecutorConstructor query_optimizer;
        logical_plan.accept_visitor(query_optimizer);
        return std::move(query_optimizer.executor);
    }
};
} // namespace NewServer
