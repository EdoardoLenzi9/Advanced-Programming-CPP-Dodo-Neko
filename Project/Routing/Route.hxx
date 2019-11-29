#ifndef ROUTE_HXX
#define ROUTE_HXX

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

        Route( string path, 
               string httpMethod, 
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>),
               vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>)>> middlewares)
               : path(path), httpMethod(httpMethod), handler(handler), middlewares(middlewares) {};

        string path;
        string httpMethod;

        void handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>);

    private:
        vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>)>> middlewares;
        void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>);
};

#endif