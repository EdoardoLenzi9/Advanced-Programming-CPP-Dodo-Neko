#ifndef HOTEL_CONTROLLER_HXX
#define HOTEL_CONTROLLER_HXX

#include "server_http.hpp"
#include "BaseController.hxx"

#define BOOST_SPIRIT_THREADSAFE

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <Const.hxx>


using namespace std;
using namespace SimpleWeb;
using json = nlohmann::json;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class HotelController : public BaseController {
    public:
        HotelController() {};
        static void get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void apiVersion(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
};

#endif