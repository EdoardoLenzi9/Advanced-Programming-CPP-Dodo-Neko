/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_ROOM_SERVICE_HPP
#define USER_ROOM_SERVICE_HPP


#include <iostream>
#include <string>
#include <vector>
#include <time.h>

#include "Repository.hxx"
#include "UserService.hxx"


class UserRoomService { 
    
    public:
        UserRoomService(){
            urr = new Repository<UserRoom>();
            us = new UserService();
        }

        long create(long user_id, int room_id);
        void del(long id);    
        
    private:
        UserService* us;
        Repository<UserRoom>* urr;
};


#endif