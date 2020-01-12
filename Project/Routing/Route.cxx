#include "Route.hxx"

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, Route obj) {

    for(function<void(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>)> middleware : obj.middlewares) {
        middleware(response, request);
    }

    obj.handler(response, request);

}