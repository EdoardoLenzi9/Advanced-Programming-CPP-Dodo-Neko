#ifndef AUTH_MIDDLEWARE_HXX
#define AUTH_MIDDLEWARE_HXX

#include "server_http.hpp"
#include "status_code.hpp"
#include "BaseMiddleware.hxx"

#define BOOST_SPIRIT_THREADSAFE
#include <nlohmann/json.hpp>

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>


using namespace std;
using namespace SimpleWeb;
using json = nlohmann::json;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

class AuthMiddleware: public BaseMiddleware {
    public:
        static const int USER = 1;
        static const int STAFF = 2;
        static const int ADMIN = 3;
        AuthMiddleware() {};
        static bool user(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json);
        static bool staff(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json);
        static bool admin(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json);
    
    private:
        static bool handle(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json, int);
};

#endif