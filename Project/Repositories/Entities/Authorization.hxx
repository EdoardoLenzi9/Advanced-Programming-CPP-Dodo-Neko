/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef AUTHORIZATION_HXX
#define AUTHORIZATION_HXX

#include <string>
#include <odb/core.hxx>

#include "BaseEntity.hxx"  

using namespace std;


class Authorization : public BaseEntity
{
	public:
    
	    Authorization () {}
	    Authorization (long u, long s) : user_id_(u), session_id_(s) {}                 
		
		// Getter and setters
		void user_id( long u ) { user_id_ = u; };
		long user_id() { return user_id_; };

		void session_id( long s ) { session_id_ = s; };
		long session_id() { return session_id_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  

	
	private:

		long user_id_;
		long session_id_;

		#pragma db id auto         
		unsigned long id_;         
};

#pragma db object(Authorization)

#endif