#ifndef ROOM_CONTROLLER_HXX
#define ROOM_CONTROLLER_HXX

#include "client_http.hpp"
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


void handler(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request);

#endif