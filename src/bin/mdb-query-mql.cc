/*
 * query is a executable that takes a file with the query, send it to the server via TCP socket
 * and print the result received.
 *
 * Program Flow is:
 * - read file to a string
 * - connect to server via TCP socket
 * - send query length
 * - send query
 * - listen to results and print them. Results may come in many packages of a fixed size: `CommunicationProtocol::BUFFER_SIZE`
 *     - first byte indicates the state (not finished, finished successfully or finished with errors.
 *     - next 2 bytes indicates the length of the message (needed because `CommunicationProtocol::BUFFER_SIZE`
 *       bytes must be sent even if the message is shorter).
 */
#include <fstream>
#include <iostream>
#include <iterator>

#include <boost/asio.hpp>

#include "network/old/mql/tcp_buffer.h"
#include "third_party/cli11/CLI11.hpp"

using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char **argv) {
    string   host = "127.0.0.1";
    unsigned port = CommunicationProtocol::DEFAULT_PORT;

    CLI::App app{"MillenniumDB query\nSends queries to the MillenniumDB server.\nQuery is received by standard input"};
    app.get_formatter()->column_width(35);
    app.option_defaults()->always_capture_default();

    app.add_option("-d,--destination", host)
        ->description("Server the query will be sent to")
        ->type_name("<host>");

    app.add_option("-p,--port", port)
        ->description("Server port")
        ->type_name("<port>")
        ->check(CLI::Range(1024, 65'535).description(""));

    CLI11_PARSE(app, argc, argv);


    try {
        stringstream str_stream;
        str_stream << std::cin.rdbuf();
        string query = str_stream.str();

        boost::asio::io_service io_service;

        tcp::socket s(io_service);
        tcp::resolver resolver(io_service);
        boost::asio::connect(s, resolver.resolve({host, std::to_string(port)}));

        // Send Query
        auto query_length = query.size();

        unsigned char query_size_b[CommunicationProtocol::BYTES_FOR_QUERY_LENGTH];
        for (int i = 0, offset = 0; i < CommunicationProtocol::BYTES_FOR_QUERY_LENGTH; i++, offset += 8) {
            unsigned char c = (query_length >> offset) & 0xFF;
            query_size_b[i] = c;
        }
        boost::asio::write(s, boost::asio::buffer(query_size_b, CommunicationProtocol::BYTES_FOR_QUERY_LENGTH));
        boost::asio::write(s, boost::asio::buffer(query.data(), query_length));

        // Read results
        unsigned char result_buffer[CommunicationProtocol::BUFFER_SIZE];
        do {
            boost::asio::read(s, boost::asio::buffer(result_buffer, CommunicationProtocol::BUFFER_SIZE));
            // We print skipping first 3 bytes, which are used to indicate the status and the length of the message
            auto reply_length = static_cast<unsigned int>(result_buffer[1]) +
                               (static_cast<unsigned int>(result_buffer[2]) << 8);

            cout.write(reinterpret_cast<char*>(result_buffer+3), reply_length-3);
        } while ( !CommunicationProtocol::last_message(result_buffer[0]) );

        return CommunicationProtocol::decode_status(result_buffer[0]);
    }
    catch (boost::system::system_error const& e) {
        cout << "Error connecting to server: " << e.what() << "\n";
        return static_cast<int>(CommunicationProtocol::StatusCodes::connection_error);
    }
    catch(const std::exception& e) {
        cerr << e.what() << "\n";
        return static_cast<int>(CommunicationProtocol::StatusCodes::unexpected_error);
    }
    catch(...) {
        cerr << "Exception of unexpected type!\n";
        return static_cast<int>(CommunicationProtocol::StatusCodes::unexpected_error);
    }
}
