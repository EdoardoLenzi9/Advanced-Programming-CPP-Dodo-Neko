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
#include "DtoException.hxx"
#include "Const.hxx"


class RoomService { 
    
    public:
        RoomService(){
            rr = new Repository<Room>();
            ru = new Repository<User>();
            rur = new Repository<UserRoom>();
            us = new UserService();

        }

        long create(int beds, int tlx, int tly, int brx, int bry);    
        void printList();
        long bookRoom(long userID, long roomID);
        void unbookRoom(long roomID);
        Room* getRoom(long id);
        vector<Room> getList(long id);
        void update(long id, int beds, int tlx, int tly, int brx, int bry);
        
    private:
        UserService* us;
        Repository<Room>* rr;
        Repository<User>* ru;
        Repository<UserRoom>* rur;
};

#endif