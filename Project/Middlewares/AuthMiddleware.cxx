// TODO find a way to interpone authentication middleware before Router handlers (Controllers)
// the easyest way is to call the middleware in every endpoint but this will be redundant,
// the best way is to find a common point shared between each call before the handler evaluation 

#include "AuthMiddleware.hxx"

bool AuthMiddleware::user(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content) {

    if(content.find("sid") == content.end()) {
        
        json res;
        res["status"]["code"] = 401;
        res["status"]["description"] = "Unauthorized";
        res["data"] = "";
        response->write(SimpleWeb::StatusCode::client_error_unauthorized, res.dump());

        return false;
    }

    if(false) { // check if sid valid
        json res;
        res["status"]["code"] = 401;
        res["status"]["description"] = "Unauthorized";
        res["data"] = "";
        response->write(SimpleWeb::StatusCode::client_error_unauthorized, res.dump());

        return false;
    }

    return true;

}