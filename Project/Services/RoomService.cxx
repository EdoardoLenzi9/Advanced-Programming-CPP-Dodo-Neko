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


long RoomService::create(int beds, int tlx, int tly, int brx, int bry){
    Room* tmp = rr->create(new Room(beds, tlx, tly, brx, bry));
    cout << "Room created" << tmp->id() << endl;
    return tmp->id();
}


void RoomService::list(){
    odb::result<Room>* availableRooms = rr->read(odb::query<Room>::beds == 2);

    for (odb::result<Room>::iterator i (availableRooms->begin ()); i != availableRooms->end (); ++i)
        cout << i->beds() << endl;
}