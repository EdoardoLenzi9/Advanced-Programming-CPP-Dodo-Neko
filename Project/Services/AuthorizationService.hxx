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
        long createSession(long user_id_, long session_id_);
        long getToken(long id);
        long getUserID(long id);
        long getSession(long session_id);
        
   
    private:
        Repository<Authorization>* au;
   
};

#endif