/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOM_FEATURE_SERVICE_HPP
#define ROOM_FEATURE_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"
#include "RoomService.hxx"


class RoomFeatureService { 
    
    public:
        RoomFeatureService(){
            rr = new Repository<Room>();
            rur = new Repository<UserRoom>();
            ft = new Repository<FeatureType>();
            rf = new Repository<RoomFeature>();

        }

        long createRoomFeature(long r_id, long ft_id, long r_num);
        long createFeatureType(string f, float p);
        void del(long id);

   
    private:
        Repository<RoomFeature>* rf;
        Repository<FeatureType>* ft;
        Repository<Room>* rr;
        Repository<UserRoom>* rur;
};

#endif