#ifndef ROUTER_HXX
#define ROUTER_HXX

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


class Route { 
    
    public:
        Route( string path, 
               string httpMethod, 
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>))
               : path(path), httpMethod(httpMethod), handler(handler) {};

        string path;
        string httpMethod;
        void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>);
};


class Router { 
    
    public:
        Router( vector<Route> routes ) : routes(routes) {};
        void start();

    private:
        vector<Route> routes;
};


#endif