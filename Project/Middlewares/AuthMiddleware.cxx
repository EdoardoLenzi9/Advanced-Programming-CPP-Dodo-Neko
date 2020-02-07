// TODO find a way to interpone authentication middleware before Router handlers (Controllers)
// the easyest way is to call the middleware in every endpoint but this will be redundant,
// the best way is to find a common point shared between each call before the handler evaluation 

#include "AuthMiddleware.hxx"
#include <AuthorizationService.hxx>
#include <UserService.hxx>
#include <Const.hxx>

bool AuthMiddleware::handle(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content, int authlevel) {

    if(content["auth"].count("sid") == 0) {
        
        json res;
        res["status"]["code"] = Code::Unauthorized;
        res["status"]["description"] = Unauthorized;
        res["data"] = "";
        *response << serialize(res);

        return false; 
    }

    AuthorizationService service;
    UserService userService;
    long userId = 0;

    userId = service.getSession(content["auth"]["sid"].get<string>());    

    if(userId == 0) {
        json res;
        res["status"]["code"] = Code::Unauthorized;
        res["status"]["description"] = Unauthorized;
        res["data"] = "";
        *response << serialize(res);

        return false;
    }

    if(userService.getRole(userId) < authlevel) {
        json res;
        res["status"]["code"] = Code::Unauthorized;
        res["status"]["description"] = Unauthorized;
        res["data"] = "";
        *response << serialize(res);

        return false;
    }

    return true;

}

bool AuthMiddleware::user(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content) {
    return AuthMiddleware::handle(response, request, content, AuthMiddleware::USER);
}

bool AuthMiddleware::staff(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content) {
    return AuthMiddleware::handle(response, request, content, AuthMiddleware::STAFF);
}

bool AuthMiddleware::admin(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content) {
    return AuthMiddleware::handle(response, request, content, AuthMiddleware::ADMIN);
}