#include "RoomController.hxx"


// TODO simple example of an handler, here u can define how many handlers u need 
// and pass them in driver.cxx to the Router in order to set-up the routes
// if u want to test this handler go to http://localhost:8080/info

void RoomController::handler(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        stringstream stream;
        stream << "<h1>Request from " << request->remote_endpoint_address() << ":" << request->remote_endpoint_port() << "</h1>";

        stream << request->method << " " << request->path << " HTTP/" << request->http_version;

        stream << "<h2>Query Fields</h2>";
        auto query_fields = request->parse_query_string();
        for(auto &field : query_fields)
        stream << field.first << ": " << field.second << "<br>";

        stream << "<h2>Header Fields</h2>";
        for(auto &field : request->header)
        stream << field.first << ": " << field.second << "<br>";

        response->write(stream);
}