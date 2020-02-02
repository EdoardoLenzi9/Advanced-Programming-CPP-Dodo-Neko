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
using namespace SimpleWeb;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class RoomController {
    public:
        RoomController() {};
        static void info(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content);
        static void authTest(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content);
        static void test(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content);
        static void hotel(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content);
        static void room(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, string content);
};

#endif