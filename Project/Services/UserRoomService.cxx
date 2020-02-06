/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>

#include "UserRoomService.hxx"


long UserRoomService::create(long user_id, int room_id){
    long currentTime = (long)clock();
    UserRoom* tmp = urr->create(new UserRoom(user_id, room_id, currentTime));
    cout << "UserRoom created" << tmp->id() << endl;
    return tmp->id();
}


void UserRoomService::del(long id){
    urr->archive(id);
    cout << "UserRoom deleted" << id << endl;
}