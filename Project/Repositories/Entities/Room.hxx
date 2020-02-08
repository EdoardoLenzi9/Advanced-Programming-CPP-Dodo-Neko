/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOM_HXX
#define ROOM_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  

using namespace std;


class Room : public BaseEntity
{

	public:

		Room () {}
		Room (int n): roomnumber_(n) {}

		int roomnumber() {return roomnumber_; };
		int roomnumber(int n) {roomnumber_ = n; };

		unsigned long id ( ) { return id_; } ;
		
		bool archived() {return archived_; };
		void archived(bool a) {archived_ = a; };

		friend class odb::access;  


	private:
		int roomnumber_;

		#pragma db id auto         
		unsigned long id_;  
		bool archived_;       
};

#pragma db object(Room)

#endif