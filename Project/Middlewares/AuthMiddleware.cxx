// TODO find a way to interpone authentication middleware before Router handlers (Controllers)
// the easyest way is to call the middleware in every endpoint but this will be redundant,
// the best way is to find a common point shared between each call before the handler evaluation 

#include "AuthMiddleware.hxx"

bool AuthMiddleware::handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>) {
    return false;
}