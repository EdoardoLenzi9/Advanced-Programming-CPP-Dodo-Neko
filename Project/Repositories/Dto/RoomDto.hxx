/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOM_DTO_HXX
#define ROOM_DTO_HXX

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "Room.hxx"
#include "RoomFeature.hxx"

using namespace std;
using json = nlohmann::json;


class FeatureDto{
	public:
		FeatureDto (long id, string name, float price, int amount) 
			: id(id), name(name), price(price), amount(amount) {}                 

		long id;
		string name;
		float price;
		int amount;
};


class RoomDto
{
	public:
    
	    RoomDto (long rid, int rnum, vector<FeatureDto> f) : roomid(rid), roomnumber(rnum), features(f) {}                 
		
		int roomnumber;
		long roomid;
		vector<FeatureDto> features;
};


class SimpleRoomDto
{
	public:
    
	    SimpleRoomDto (long rid, int rnum) : roomid(rid), roomnumber(rnum) {}                 
		
		int roomnumber;
		long roomid;
};

#endif