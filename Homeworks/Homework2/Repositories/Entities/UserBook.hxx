/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USERBOOK_HXX
#define USERBOOK_HXX

#include <string>
#include <odb/core.hxx>
  
class UserBook
{
	public:
    
	    UserBook () {}
	    UserBook (long u, long b, long t) : user_id_(u), book_id_(b), timestamp_(t) {}                 
		
		// Getter and setters
		void user_id( long u ) { user_id_ = u; };
		long user_id() { return user_id_; };
	    
		void book_id( long b ) { book_id_ = b; };
		long book_id() { return book_id_; };
		
		void timestamp( long t ) { timestamp_ = t; };
		long timestamp() { return timestamp_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  

	
	private:

	    long user_id_;
    	long book_id_;
    	long timestamp_;

		#pragma db id auto         
		unsigned long id_;         
};

#pragma db object(UserBook)

#endif