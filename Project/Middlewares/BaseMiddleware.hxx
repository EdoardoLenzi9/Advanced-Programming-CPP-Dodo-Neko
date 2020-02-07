#ifndef BASE_MIDDLEWARE_HXX
#define BASE_MIDDLEWARE_HXX


#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

#include "Const.hxx"


class BaseMiddleware {

    public:
        static string serialize(json res){
            string statusCode = to_string(res["status"]["code"].get<int>());
            string statusCodeLabel = CodeLabels[statusCode];
            string dump = res.dump();

            return "HTTP/1.1 " + statusCode + " " + statusCodeLabel +"\r\nContent-Length: " + to_string(dump.length()) + "\r\nContent-Type: application/json\r\nAccess-Control-Allow-Origin: *\r\n\r\n" + dump;
        }
};

#endif