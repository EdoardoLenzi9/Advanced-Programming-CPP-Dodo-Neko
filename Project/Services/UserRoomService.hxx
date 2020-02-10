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

#include "UserRoom.hxx"
#include "Repository.hxx"
#include "UserService.hxx"
#include "DtoException.hxx"
#include "RoomDto.hxx"
#include "BookDto.hxx"
#include "Const.hxx"
#include <math.h>

class UserRoomService { 
    
    public:
        UserRoomService(){
            rr = new Repository<Room>();
            ru = new Repository<User>();
            rf = new Repository<RoomFeature>();
            rft = new Repository<FeatureType>();
            rur = new Repository<UserRoom>();
            us = new UserService();
        }

        void del(long userId, long role, long id);    
        void unbookRoom(long roomID);
        long bookRoom(long userID, long roomID, long arrival, long departure);
        void confirmPayment(long role, long bookid);
        vector<BookDto> bookingList(long userid, long role);
        void update(long userid, long role, long bookid, long arrival, long departure);
        set<long> reservedRooms(long startdate, long enddate, long bookid);
        float computePrice(long roomID, long arrival, long departure);

    private:
        UserService* us;
        Repository<Room>* rr;
        Repository<RoomFeature>* rf;
        Repository<User>* ru;
        Repository<UserRoom>* rur;
        Repository<FeatureType>* rft;
};


#endif