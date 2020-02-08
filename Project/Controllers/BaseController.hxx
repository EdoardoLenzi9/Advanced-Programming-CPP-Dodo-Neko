#ifndef BASE_CONTROLLER_HXX
#define BASE_CONTROLLER_HXX


#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

#include "Const.hxx"
#include "RoomDto.hxx"

class BaseController {

    public:
        static json serialize(vector<RoomDto> rooms){
            json j;
            json feature;
            json room;

            for(RoomDto r: rooms){
                room["room"]["roomid"] = r.roomid;
                room["room"]["roomnumber"] = r.roomnumber;
                room["room"]["features"] = {};

                for(FeatureDto f: r.features){
                    feature["feature"]["id"] = f.id;
                    feature["feature"]["name"] = f.name;
                    feature["feature"]["price"] = f.price;
                    feature["feature"]["amount"] = f.amount; 

                    room["room"]["features"].push_back(feature["feature"]);
                }

                j["data"]["rooms"].push_back( room["room"] );
            }

            return j;
        }
        
        
        static string serialize(json res){
            string statusCode = to_string(res["status"]["code"].get<int>());
            string statusCodeLabel = CodeLabels[statusCode];
            string dump = res.dump();

            return "HTTP/1.1 " + statusCode + " " + statusCodeLabel +"\r\nContent-Length: " + to_string(dump.length()) + "\r\nContent-Type: application/json\r\nAccess-Control-Allow-Origin: *\r\n\r\n" + dump;
        }
};

#endif