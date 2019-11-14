/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOM_SERVICE_HPP
#define ROOM_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"
#include "UserService.hxx"

class RoomService { 
    
    public:
        RoomService(){
            rr = new Repository<Room>();
            us = new UserService();
        }

        long create(int beds, int tlx, int tly, int brx, int bry);    
        void list();
        
    private:
        UserService* us;
        Repository<Room>* rr;
};

#endif