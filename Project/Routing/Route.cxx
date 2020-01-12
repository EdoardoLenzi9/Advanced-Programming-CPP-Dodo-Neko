#include "Route.hxx"

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, Route obj) {

    string content = request->content.string();

    for(function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string)> middleware : obj.middlewares) {
        if(!middleware(response, request, content))
            return;
    }

    obj.handler(response, request, content);

}