/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>

#include "BubbleSort.hxx"
#include "DataAnalysisService.hxx"

int DataAnalysisService::averageDays(){
    vector<UserRoom> bookings = rur->readAll();
    int average = 0;

    for(UserRoom b: bookings){
        average += floor((b.departure() - b.arrival()) / 86400);
    }

    if(bookings.size() > 0){
        return average / bookings.size();
    } else {
        return 0;
    }
}


float DataAnalysisService::averagePrice(){
    vector<UserRoom> bookings = rur->readAll();
    int average = 0;

    for(UserRoom b: bookings){
        average += b.price();
    }

    if(bookings.size() > 0){
        return average / bookings.size();
    } else {
        return 0;
    }
}


vector<SimpleRoomDto> DataAnalysisService::mostValuableRooms(){
    vector<UserRoom> bookings = rur->readAll();
    vector<Room> rooms = rr->readAll();
    vector<SimpleRoomDto> result;

    vector<Tuple> weight;
    for(int i = 0; i < rooms.size(); i++){
        weight.push_back(Tuple( i, 0 ));
    }

    for(UserRoom b: bookings){
        weight[b.room_id()].value += b.price();
    }

    BubbleSort bubblesort;
    bubblesort.sort(weight);

    for(int i = 0; i < rooms.size(); i++){
        Room r = rooms[weight[i].index]; 
        result.push_back(SimpleRoomDto(r.id(), r.roomnumber()));
    }

    return result;
}


vector<UserDto> DataAnalysisService::mostValuableCustomers(){
    vector<UserRoom> bookings = rur->readAll();
    vector<User> customers = ru->readAll();
    vector<UserDto> result;
    
    vector<Tuple> weight;
    for(int i = 0; i < customers.size(); i++){
        weight.push_back(Tuple( i, 0 ));
    }

    for(UserRoom b: bookings){
        weight[b.user_id() - 1].value += b.price();
    }

    BubbleSort bubblesort;
    bubblesort.sort(weight);

    for(int i = 0; i < customers.size(); i++){
        User u = customers[weight[i].index];
        UserDto dto = UserDto(u.firstname(), u.lastname(), u.email(), 
                              u.birthdate(), u.address(), u.id(), u.role()); 
        result.push_back(dto);
    }

    return result;
}


vector<FeatureDto> DataAnalysisService::mostValuableFeatures(){

}