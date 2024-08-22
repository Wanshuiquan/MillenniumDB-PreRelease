#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include "query/executor/query_executor/mql/return_executor.h"


namespace MQL {

class RequestHandler {
public:
    static std::pair<std::string, ReturnType>
      parse_request(boost::beast::http::request<boost::beast::http::string_body>& req)
    {
        ReturnType response_type = ReturnType::CSV;

        for (auto& header : req) {
            std::string accept_value = header.value();
            if (to_string(header.name()) == "Accept") {
                if (accept_value.find("text/tab-separated-values") != std::string::npos) {
                    response_type = ReturnType::TSV;
                }
            }
            // else CSV by default
        }


        // We assume that the post body contains the query, otherwise ignore contents
        if (req.method() != boost::beast::http::verb::post) {
            return std::make_pair("", response_type);
        }

        return std::make_pair(req.body(), response_type);
    }
};
} // namespace MQL
