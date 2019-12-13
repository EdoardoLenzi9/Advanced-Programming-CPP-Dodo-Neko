// TODO find a way to interpone authentication middleware before Router handlers (Controllers)
// the easyest way is to call the middleware in every endpoint but this will be redundant,
// the best way is to find a common point shared between each call before the handler evaluation 

#include "AuthMiddleware.hxx"

void AuthMiddleware::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {

    ptree pt;
    read_json(request->content, pt);
    string sid = pt.get<string>("auth.sid");
    
    if(sid.empty())
        response->write(StatusCode::client_error_unauthorized, "{ \"status\" : { \"code\" : 401, \"description\" : \"Unauthorized\" } }");

    if(sid.compare("c91b1d6acd383c44c4ec20c9723e758c31182a1f4f0231d63d91259a2ea14b9d") != 0)
        response->write(StatusCode::client_error_unauthorized, "{ \"status\" : { \"code\" : 401, \"description\" : \"Unauthorized\" } }");

}