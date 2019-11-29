// TODO find a way to interpone authentication middleware before Router handlers (Controllers)
// the easyest way is to call the middleware in every endpoint but this will be redundant,
// the best way is to find a common point shared between each call before the handler evaluation 

#include "AuthMiddleware.hxx"

void AuthMiddleware::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {

    CaseInsensitiveMultimap query_fields = request->parse_query_string();
    CaseInsensitiveMultimap::iterator it = query_fields.find("token");
    
    if(it == query_fields.end()) {
        stringstream stream;
        stream << "401 Unauthorized";
        response->write(StatusCode::client_error_unauthorized, stream);
    } else {
        if(it->second != "1234") {
            stringstream stream;
            stream << "401 Unauthorized";
            response->write(StatusCode::client_error_unauthorized, stream);
        }
    }

}