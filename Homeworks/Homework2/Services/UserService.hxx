/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_SERVICE_HPP
#define USER_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"


class UserService { 
    
    public:
        UserService(){
            ur = new Repository<User>();
        }

        long getRole(long id);
        long create(long auth, string name, string surname, long role);    

    private:
        Repository<User>* ur;
};

#endif