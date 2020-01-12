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

 /* vector<Room> RoomService::getList(){
    result<Room>* availableRooms = rr->read(odb::query<Room>::beds == 2);
    vector<Room> rooms;
    for (odb::result<Room>::iterator i (availableRooms->begin ()); i != availableRooms->end (); ++i)
        rooms.push_back(i->beds);
    return rooms;
}*/

/*vector<Room> RoomService::getList(){
    vector<Room> availableRooms = rr->read(odb::query<Room>::beds == 2);
    return availableRooms;
}*/
long RoomService::bookRoom(long userID, long roomID){
    UserRoom* userR = rur->create(new UserRoom(userID, roomID, 1));
    cout<<"Room is booked" <<userR->id() <<endl;
    return userR->id();
}

void RoomService::unbookRoom(long roomID){
    rur->del(roomID);
    cout<<"Room is deleted!"<<roomID<<endl;
}

Room* RoomService::get(long id) {
    return rr->read(id);

}