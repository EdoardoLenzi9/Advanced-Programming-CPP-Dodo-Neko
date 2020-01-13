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
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string))
               : path(path), httpMethod(httpMethod), handler(handler) {};

        Route( string path, 
               string httpMethod, 
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string),
               vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string)>> middlewares)
               : path(path), httpMethod(httpMethod), handler(handler), middlewares(middlewares) {};

        string path;
        string httpMethod;

        static void handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, Route);

    private:
        vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string)>> middlewares;
        void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, string);
};

#endif