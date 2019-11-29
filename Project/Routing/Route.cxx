#include "Route.hxx"

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {

    for(function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>)> middleware : middlewares) {
        if(middleware(response, request))
            return;
    }

    handler(response, request);

}