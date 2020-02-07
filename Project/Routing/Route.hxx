#ifndef ROUTE_HXX
#define ROUTE_HXX

#include "server_http.hpp"
#include "Env.hxx"
#include "BaseController.hxx"
#include "Const.hxx"

#define BOOST_SPIRIT_THREADSAFE
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>


using namespace std;
using namespace boost::property_tree;
using json = nlohmann::json;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class Route { 
    
    public:
        Route( string path, 
               string httpMethod, 
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json))
               : path(path), httpMethod(httpMethod), handler(handler) { };

        Route( string path, 
               string httpMethod, 
               void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json),
               vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json)>> middlewares)
               : path(path), httpMethod(httpMethod), handler(handler), middlewares(middlewares) { };

        string path;
        string httpMethod;

        static void handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, Route);

    private:
        vector<function<bool(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json)>> middlewares;
        void (*handler)(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json);
};

#endif