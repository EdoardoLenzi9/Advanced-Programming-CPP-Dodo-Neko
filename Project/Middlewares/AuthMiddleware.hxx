#ifndef AUTH_MIDDLEWARE_HXX
#define AUTH_MIDDLEWARE_HXX

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

class AuthMiddleware {
    public:
        AuthMiddleware() {};
        static bool handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>);
};

#endif