#ifndef BASE_CONTROLLER_HXX
#define BASE_CONTROLLER_HXX


#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

#include "Const.hxx"
#include "RoomDto.hxx"
#include "UserDto.hxx"
#include "BookDto.hxx"
#include "RoomService.hxx"

class BaseController {

    public:

        static json serialize(vector<SimpleRoomDto> rooms){
            json j;

            j["data"]["rooms"] = {};

            for(SimpleRoomDto r: rooms){
                json feature = serialize(r);
                j["data"]["rooms"].push_back( feature["data"] );
            }

            return j;
        }

        static json serialize(vector<FeatureDto> features){
            json j;

            j["data"]["features"] = {};

            for(FeatureDto f: features){
                json feature = serialize(f);
                j["data"]["features"].push_back( feature["data"] );
            }

            return j;
        }


        static json serialize(vector<UserDto> users){
            json j;

            j["data"]["users"] = {};

            for(UserDto u: users){
                json user = serialize(u);
                j["data"]["users"].push_back( user["data"] );
            }

            return j;
        }


        static json serialize(vector<BookDto> bookings){
            json j;

            j["data"]["bookings"] = {};
            
            for(BookDto b: bookings){
                json book = serialize(b);
                j["data"]["bookings"].push_back(book["data"]); 
            }

            return j;
        }


        static json serialize(vector<RoomDto> rooms){
            json j;

            j["data"]["rooms"] = {};

            for(RoomDto r: rooms){
                json room = serialize(r);
                j["data"]["rooms"].push_back( room["data"] );
            }

            return j;
        }


        static json serialize(RoomDto room){
            json feature;
            json j;

            j["data"]["roomid"] = room.roomid;
            j["data"]["roomnumber"] = room.roomnumber;
            j["data"]["features"] = {};

            for(FeatureDto f: room.features){
                json feature = serialize(f);
                j["data"]["features"].push_back(feature["data"]);
            }

            return j;
        }


        static json serialize(SimpleRoomDto room){
            json feature;
            json j;

            j["data"]["roomid"] = room.roomid;
            j["data"]["roomnumber"] = room.roomnumber;

            return j;
        }


        static json serialize(FeatureDto feature){
            json j;

            j["data"]["id"] = feature.id;
            j["data"]["name"] = feature.name;
            j["data"]["price"] = feature.price;
            j["data"]["amount"] = feature.amount;

            return j;
        }

        
        static json serialize(UserDto user){
            json j;

            j["data"]["firstname"] = user.firstname;
            j["data"]["lastname"] = user.lastname;
            j["data"]["email"] = user.email;
            j["data"]["birthdate"] = user.birthdate;
            j["data"]["address"] = user.address;
            j["data"]["userid"] = user.userid;
            j["data"]["roleid"] = user.roleid;

            return j;
        }
        

        static json serialize(BookDto book){
            json j;
            json room = serialize(book.room);
            json user = serialize(book.user);

            j["data"]["room"] = room["data"];
            j["data"]["user"] = user["data"];
            j["data"]["bookid"] = book.bookid;
            j["data"]["arrival"] = book.arrival;
            j["data"]["departure"] = book.departure;
            j["data"]["paid"] = book.paid;
            j["data"]["price"] = book.price;

            return j;
        }

        
        static string serialize(json res){
            string statusCode = to_string(res["status"]["code"].get<int>());
            string statusCodeLabel = CodeLabels[statusCode];
            string dump = res.dump();

            return "HTTP/1.1 200 OK \r\nContent-Length: " + to_string(dump.length()) + "\r\nContent-Type: application/json\r\nAccess-Control-Allow-Methods: POST, GET\r\nAccess-Control-Allow-Headers: Content-Type\r\nAccess-Control-Allow-Origin: *\r\n\r\n" + dump;
        }
};

#endif