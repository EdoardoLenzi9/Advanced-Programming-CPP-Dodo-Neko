/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BOOK_DTO_HXX
#define BOOK_DTO_HXX

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "Room.hxx"
#include "RoomFeature.hxx"
#include "RoomDto.hxx"
#include "UserDto.hxx"

using namespace std;
using json = nlohmann::json;


class BookDto{
	public:
		BookDto (long b, RoomDto r, long a, long d, bool pa, float pr, UserDto u) 
			: bookid(b), room(r), arrival(a), departure(d), paid(pa), price(pr), user(u) {}                 

	long bookid;
	RoomDto room;
	long arrival;
	long departure;
	bool paid;
	float price;
	UserDto user;
};

#endif