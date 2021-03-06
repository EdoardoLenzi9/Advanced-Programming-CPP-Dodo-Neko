#ifndef ROOM_CONTROLLER_HXX
#define ROOM_CONTROLLER_HXX

#include "server_http.hpp"
#include "BaseController.hxx"
#include "RoomService.hxx"

#define BOOST_SPIRIT_THREADSAFE

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using namespace SimpleWeb;
using json = nlohmann::json;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class RoomController : public BaseController {
    public:
        RoomController() {};
        static void get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void list(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
};

#endif