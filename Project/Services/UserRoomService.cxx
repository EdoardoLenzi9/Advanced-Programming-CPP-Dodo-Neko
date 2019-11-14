/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "UserRoomService.hxx"
#include "Repository.hxx"


long UserRoomService::create(long user_id, int room_id){
    UserRoom* tmp = urr->create(new UserRoom(user_id, room_id, 0));
    cout << "UserRoom created" << tmp->id() << endl;
    return tmp->id();
}


void UserRoomService::del(long id){
    urr->del(id);
    cout << "UserRoom deleted" << id << endl;
}