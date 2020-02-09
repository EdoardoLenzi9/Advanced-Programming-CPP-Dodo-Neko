#ifndef DATA_ANALYSIS_CONTROLLER_HXX
#define DATA_ANALYSIS_CONTROLLER_HXX

#include "server_http.hpp"
#include "BaseController.hxx"
#include "UserRoomService.hxx"
#include "DataAnalysisService.hxx"

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


class DataAnalysisController : public BaseController {
    public:
        DataAnalysisController() {};
        static void averageDays(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void averagePrice(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void mostValuableRooms(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void mostValuableCustomers(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
        static void mostValuableFeatures(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request, json content);
};

#endif