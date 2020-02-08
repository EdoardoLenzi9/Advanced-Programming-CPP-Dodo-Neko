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
#include "RoomDto.hxx"
#include "Const.hxx"


class RoomService { 
    
    public:
        RoomService(){
            rr = new Repository<Room>();
            ru = new Repository<User>();
            rf = new Repository<RoomFeature>();
            rft = new Repository<FeatureType>();
            rur = new Repository<UserRoom>();
            us = new UserService();

        }

        long create(int beds, int tlx, int tly, int brx, int bry);    
        long bookRoom(long userID, long roomID, long arrival, long departure);
        tuple<int,int,int> castDate(long date);
        void unbookRoom(long roomID);
        Room* getRoom(long id);
        vector<RoomDto> getAvailableRooms(long startdate, long enddate);
        void update(long id, int beds, int tlx, int tly, int brx, int bry);
        
    private:
        UserService* us;
        Repository<Room>* rr;
        Repository<RoomFeature>* rf;
        Repository<User>* ru;
        Repository<UserRoom>* rur;
        Repository<FeatureType>* rft;
};

#endif