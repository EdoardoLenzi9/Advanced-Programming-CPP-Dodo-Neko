/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_HXX
#define USER_HXX


#include <string>
#include <odb/core.hxx>

#include "BaseEntity.hxx"  


using namespace std;


class User : public BaseEntity
{

    public:

		User(){}
		User (string n, string s, long r) : name_(n), surname_(s), role_(r) { }                

		// Getter and setters
		void name( string n ) { name_ = n; };
		string name() { return name_; };

		void surname( string s ) { surname_ = s; };
		string surname(){ return surname_; };

		void role( long r ) { role_ = r; };
		long role(){ return role_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  
  

    private:
  
		string name_;
		string surname_;
		long role_;

		#pragma db id auto 
		unsigned long id_;         
};

#pragma db object(User)

#endif