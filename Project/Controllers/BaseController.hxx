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
                feature["feature"]["id"] = f.id;
                feature["feature"]["name"] = f.name;
                feature["feature"]["price"] = f.price;
                feature["feature"]["amount"] = f.amount; 

                j["data"]["features"].push_back(feature["feature"]);
            }

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

            j["data"]["room"].push_back( room["data"] );
            j["data"]["user"].push_back( user["data"] );
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

            return "HTTP/1.1 200 OK \r\nContent-Length: " + to_string(dump.length()) + "\r\nContent-Type: application/json\r\nAccess-Control-Allow-Origin: *\r\n\r\n" + dump;
        }
};

#endif