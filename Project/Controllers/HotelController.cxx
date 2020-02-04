#include "HotelController.hxx"

void HotelController::get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content) {
    json res;
    res["status"]["code"] = 200;
    res["status"]["description"] = "OK";
    res["data"]["name"] = "Test Hotel";
    res["data"]["contact"] = "John Doe";
    res["data"]["address"] = "9020 Klagenfurt, Universitätstraße 65";
    res["data"]["description"] = "Nice Hotel...";
    response->write(res.dump());
}