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

		User () { }
		User (string e, string p, long r) : email_(e), password_(p), role_(r) { }                
		User (string f, string l, string e, string p, string a, long b, long r) 
			  : firstname_(f), lastname_(l), email_(e), password_(p), address_(a), birthdate_(b), role_(r) { }                
		User (long id, string f, string l, string e, string p, string a, long b, long r) 
			  : id_(id), firstname_(f), lastname_(l), email_(e), password_(p), address_(a), birthdate_(b), role_(r) { }     
		// Getter and setters
		void firstname( string f ) { firstname_ = f; };
		string firstname() { return firstname_; };

		void lastname( string l ) { lastname_ = l; };
		string lastname() { return lastname_; };

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
		
		bool archived() {return archived_; };
		void archived(bool a) {archived_ = a; };
		
		friend class odb::access;  
  

    private:
		string firstname_;
		string lastname_;
		string email_;
		string password_;
		string address_;
		long birthdate_;
		long role_;

		#pragma db id auto 
		unsigned long id_; 
		bool archived_;        
};

#pragma db object(User)

#endif