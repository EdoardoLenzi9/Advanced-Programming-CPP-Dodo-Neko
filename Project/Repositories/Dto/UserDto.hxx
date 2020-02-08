/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_DTO_HXX
#define USER_DTO_HXX

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class UserDto
{
	public:
    
	    UserDto (string f, string l, string e, long b, string a, long uid, long rid) 
			: firstname(f), lastname(l), email(e), birthdate(b), address(a), userid(uid), roleid(rid) {}                 
		
		string firstname;
		string lastname;
		string email;
		long birthdate;
		string address;
		long userid;
		long roleid;
};

#endif