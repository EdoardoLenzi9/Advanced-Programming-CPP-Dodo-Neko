/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>

#include "DataAnalysisService.hxx"


int DataAnalysisService::averageDays(){
    vector<UserRoom> bookings = rur->readAll();
    int average = 0;

    for(UserRoom b: bookings){
        average += floor((b.departure() - b.arrival()) / 86400);
    }
}


float DataAnalysisService::averagePrice(){

}


vector<RoomDto> DataAnalysisService::mostValuableRooms(){


}


vector<UserDto> DataAnalysisService::mostValuableCustomers(){


}


vector<FeatureDto> DataAnalysisService::mostValuableFeatures(){


}