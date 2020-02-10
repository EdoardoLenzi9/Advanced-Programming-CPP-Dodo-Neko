/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef DATA_ANALYSIS_SERVICE_HPP
#define DATA_ANALYSIS_SERVICE_HPP


#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>

#include "Repository.hxx"
#include "UserService.hxx"
#include "DtoException.hxx"
#include "RoomDto.hxx"
#include "BookDto.hxx"
#include "Const.hxx"

class DataAnalysisService { 
    
    public:
        DataAnalysisService(){
            rr = new Repository<Room>();
            ru = new Repository<User>();
            rf = new Repository<RoomFeature>();
            rft = new Repository<FeatureType>();
            rur = new Repository<UserRoom>();
            us = new UserService();
        }

        int averageDays();    
        float averagePrice();
        vector<SimpleRoomDto> mostValuableRooms();
        vector<UserDto> mostValuableCustomers();
        vector<FeatureDto> mostValuableFeatures();

    private:
        UserService* us;
        Repository<Room>* rr;
        Repository<RoomFeature>* rf;
        Repository<User>* ru;
        Repository<UserRoom>* rur;
        Repository<FeatureType>* rft;
};


#endif