#ifndef BASE_CONTROLLER_HXX
#define BASE_CONTROLLER_HXX

using namespace std;
using json = nlohmann::json;

#include <string>
#include <nlohmann/json.hpp>

#include "Const.hxx"

class BaseController{

    public:
        string serialize(json res){
            string statusCode = to_string(res["status"]["code"]);
            string statusCodeLabel = statusCodeLabel[to_string(res["status"]["code"])];

            return "HTTP/1.1 " + statusCode + " " + statusCodeLabel +"\r\n" + "Content-Length: " + to_string(res.dump().length()) + "\r\n" + "Content-Type: application/json\r\n\r\n" + res.dump();
        }
};

#endif