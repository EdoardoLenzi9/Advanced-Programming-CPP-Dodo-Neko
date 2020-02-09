#ifndef USER_CONTROLLER_HXX
#define USER_CONTROLLER_HXX

#include "server_http.hpp"
#include "BaseController.hxx"
#include "Const.hxx"
#include "UserService.hxx"
#include "AuthorizationService.hxx"
#include "DtoException.hxx"

#define BOOST_SPIRIT_THREADSAFE

#include <algorithm>
#include <boost/filesystem.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using namespace SimpleWeb;
using json = nlohmann::json;
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


class UserController : public BaseController {
    public:
        UserController() {};
        static void create(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void get(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void update(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void del(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void login(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void logout(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void list(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
};

#endif