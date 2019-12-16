#ifndef ROOM_CONTROLLER_HXX
#define ROOM_CONTROLLER_HXX

#include "server_http.hpp"

#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace boost::property_tree;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class RoomController {
    public:
        RoomController() {};
        static void info(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request);
        static void authTest(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request);
        static void check(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request);
};

#endif