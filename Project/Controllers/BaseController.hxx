#ifndef BASE_CONTROLLER_HXX
#define BASE_CONTROLLER_HXX


#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

#include "Const.hxx"


class BaseController{

    public:
        static string serialize(json res){
            string statusCode = res["status"]["code"].get<string>();
            string statusCodeLabel = CodeLabels[statusCode];

            return "HTTP/1.1 " + statusCode + " " + statusCodeLabel +"\r\n" + "Content-Length: " + to_string(res.dump().length()) + "\r\n" + "Content-Type: application/json\r\n\r\n" + res.dump();
        }
};

#endif