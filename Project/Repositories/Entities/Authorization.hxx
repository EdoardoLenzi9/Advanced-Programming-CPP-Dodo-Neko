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
	    Authorization (long u, string s, long e) : user_id_(u), session_id_(s), expiration_time_(e) {}                 
		
		// Getter and setters
		void user_id( long u ) { user_id_ = u; };
		long user_id() { return user_id_; };

		void session_id( long s ) { session_id_ = s; };
		string session_id() { return session_id_; };
		
		void expiration_time( long e ) { expiration_time_ = e; };
		long expiration_time() { return expiration_time_; };

		unsigned long id ( ) { return id_; } ;
		
		bool archived() {return archived_; };
		void archived(bool a) {archived_ = a; };

		friend class odb::access;  

	
	private:

		long user_id_;
		string session_id_;
		long expiration_time_;

		#pragma db id auto         
		unsigned long id_;   
		bool archived_;      
};

#pragma db object(Authorization)

#endif