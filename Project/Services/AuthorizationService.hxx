/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef AUTHORIZATION_SERVICE_HPP
#define AUTHORIZATION_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"

class AuthorizationService { 
    
    public:
        AuthorizationService(){
            au = new Repository<Authorization>();

        }
        string createSession(long user_id_);
        long getSession(string session_id);
        
   
    private:
        Repository<Authorization>* au;
   
};

#endif