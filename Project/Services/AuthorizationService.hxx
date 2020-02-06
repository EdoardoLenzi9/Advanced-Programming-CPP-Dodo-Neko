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
#include <time.h>

#include "Repository.hxx"
#include "sha256.hxx"
#include "DtoException.hxx"
#include "Const.hxx"
#include "Env.hxx"

class AuthorizationService { 
    
    public:
        AuthorizationService(){
            au = new Repository<Authorization>();
            env = new Env();
        }

        string createSession(long user_id_);
        long getSession(string session_id);
        void deleteSession(string session_id);
   
    private:
        Repository<Authorization>* au;
        Env* env;
   
};

#endif