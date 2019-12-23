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

#include "RoomService.hxx"
#include "Repository.hxx"


// TODO: those services are incomplete but gives u an idea about how a service must look like
// a service performs some check, the business logic is here, a service can call one or more repositories
// no one other than a service can call the repositories (this will be useful alse in case we need to 
// split the process into two subprocesses )


long RoomService::create(int beds, int tlx, int tly, int brx, int bry){
    Room* tmp = rr->create(new Room(beds, tlx, tly, brx, bry));
    cout << "Room created" << tmp->id() << endl;
    return tmp->id();
}


void RoomService::list(){
    vector<Room> availableRooms = rr->read(odb::query<Room>::beds == 2);
}


long RoomService::bookRoom(long userID, long roomID){
    UserRoom* userR = rur->create(new UserRoom(userID, roomID, 1));
    cout<<"Room is booked" <<userR->id() <<endl;
    return userR->id();
}