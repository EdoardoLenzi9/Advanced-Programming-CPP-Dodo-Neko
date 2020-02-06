#include "Route.hxx"

void Route::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, Route obj) {

    try {
        json j = json::parse(request->content.string());

        for(function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json)> middleware : obj.middlewares) {
            if(!middleware(response, request, j))
                return;
        }

        obj.handler(response, request, j);
        
    } catch (exception) {
        json res;
        res["status"]["code"] = 406;
        res["status"]["description"] = "Could not parse json!";
        res["data"] = "";
        response->write(res.dump());
    }

}