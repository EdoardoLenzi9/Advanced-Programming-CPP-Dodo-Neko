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
		User (string n, string s) : name_(n), surname_(s) { }                

		// Getter and setters
		void name( string n ) { name_ = n; };
		string name() { return name_; };

		void surname( string s ) { surname_ = s; };
		string surname(){ return surname_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  
  

    private:
  
		string name_;
		string surname_;

		#pragma db id auto 
		unsigned long id_;         
};

#pragma db object(User)

#endif