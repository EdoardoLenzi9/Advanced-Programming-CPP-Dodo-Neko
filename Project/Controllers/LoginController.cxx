#include "LoginController.hxx"


// TODO simple example of an handler, here u can define how many handlers u need 
// and pass them in driver.cxx to the Router in order to set-up the routes
// if u want to test this handler go to http://localhost:8080/info

void login(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        stringstream stream;
        stream << "{\"a\":\"a\"}";

        response->write(stream);
}