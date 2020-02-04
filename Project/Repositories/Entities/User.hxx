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
		User (string u, string p, long r) : username_(u), password_(p), role_(r) { }                

		// Getter and setters
		void username( string u ) { username_ = u; };
		string username() { return username_; };\

		void email( string e ) { email_ = e; };
		string email() { return email_; };

		void password( string p ) { password_ = p; };
		string password(){ return password_; };

		void address( string a ) { address_ = a; };
		string address(){ return address_; };

		void birthdate( long b ) { birthdate_ = b; };
		long birthdate(){ return birthdate_; };

		void role( long r ) { role_ = r; };
		long role(){ return role_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  
  

    private:
  
		string username_; //username = firstName.lastName 
		string email_;
		string password_;
		string address_;
		long birthdate_;
		long role_;

		#pragma db id auto 
		unsigned long id_;         
};

#pragma db object(User)

#endif