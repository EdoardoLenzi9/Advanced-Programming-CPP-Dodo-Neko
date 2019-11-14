/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USERROOM_HXX
#define USERROOM_HXX

#include <string>
#include <odb/core.hxx>
  
class UserRoom
{
	public:
    
	    UserRoom () {}
	    UserRoom (long u, long r, long t) : user_id_(u), room_id_(r), timestamp_(t) {}                 
		
		// Getter and setters
		void user_id( long u ) { user_id_ = u; };
		long user_id() { return user_id_; };
	    
		void room_id( long b ) { room_id_ = b; };
		long room_id() { return room_id_; };
		
		void timestamp( long t ) { timestamp_ = t; };
		long timestamp() { return timestamp_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  

	
	private:

	    long user_id_;
    	long room_id_;
    	long timestamp_;

		#pragma db id auto         
		unsigned long id_;         
};

#pragma db object(UserRoom)

#endif