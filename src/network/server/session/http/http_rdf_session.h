#pragma once

#include <mutex>

#include <boost/asio.hpp>
#include <boost/beast.hpp>

#include "network/server/protocol.h"
#include "network/sparql/response_type.h"
#include "query/executor/query_executor/query_executor.h"
#include "query/parser/op/op.h"


namespace MDBServer {

template<uint64_t ModelId>
class Server;

class HttpRdfSession : public std::enable_shared_from_this<HttpRdfSession> {
    using stream_type = boost::beast::tcp_stream;

public:
    static inline std::mutex update_mutex;

    using DurationMS = std::chrono::duration<float, std::milli>;

    DurationMS parser_duration;
    DurationMS optimizer_duration;
    DurationMS execution_duration;

    explicit HttpRdfSession(Server<Protocol::RDF_MODEL_ID>&                                server,
                            stream_type&&                                                  stream,
                            boost::beast::http::request<boost::beast::http::string_body>&& request,
                            std::chrono::seconds                                           query_timeout);

    virtual ~HttpRdfSession();

    void run();

private:
    boost::beast::error_code ec;

    Server<Protocol::RDF_MODEL_ID>& server;

    stream_type stream;

    boost::beast::http::request<boost::beast::http::string_body> request;

    std::chrono::seconds query_timeout;

    void handle_request();

    void execute_readonly_query(const std::string& query, std::ostream& os, SPARQL::ResponseType response_type);

    std::unique_ptr<Op> create_readonly_logical_plan(const std::string& query);

    std::unique_ptr<QueryExecutor> create_readonly_physical_plan(Op& logical_plan, SPARQL::ResponseType response_type);

    void execute_readonly_query_plan(QueryExecutor& physical_plan, std::ostream& os, SPARQL::ResponseType response_type);

    void execute_update_query(const std::string& query, std::ostream& os);

    std::unique_ptr<SPARQL::OpUpdate> create_update_logical_plan(const std::string& query);
};
} // namespace MDBServer
