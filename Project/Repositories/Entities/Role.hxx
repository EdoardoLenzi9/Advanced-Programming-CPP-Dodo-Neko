/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROLE_HXX
#define ROLE_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  


using namespace std;


class Role : public BaseEntity
{
  	public:
    
		Role () {}                 
		Role (string d) : description_(d) {}           

		// Getter and setters
		void description( string d ) { description_ = d; };
		string description() { return description_; };
		
		unsigned long id ( ) { return id_; } ;
		
		friend class odb::access;  


    private:
      	string description_;

      	#pragma db id auto         
      	unsigned long id_;         
};

#pragma db object(Role)

#endif