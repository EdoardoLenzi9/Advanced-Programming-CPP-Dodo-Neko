#ifndef AUTH_MIDDLEWARE_HXX
#define AUTH_MIDDLEWARE_HXX

#include "server_http.hpp"
#include "status_code.hpp"

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

class AuthMiddleware {
    public:
        AuthMiddleware() {};
        static bool user(shared_ptr<HttpServer::Response>, shared_ptr<HttpServer::Request>, json);
};

#endif