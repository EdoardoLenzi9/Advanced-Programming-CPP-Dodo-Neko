/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include "RoomService.hxx"


long RoomService::create(int beds, int tlx, int tly, int brx, int bry){
    Room* tmp = rr->create(new Room(beds, tlx, tly, brx, bry));
    cout << "Room created" << tmp->id() << endl;
    return tmp->id();
}


void RoomService::printList(){
    vector<Room> availableRooms = rr->read(odb::query<Room>::beds == 2);
}


long RoomService::bookRoom(long userID, long roomID){
    UserRoom* userR = rur->create(new UserRoom(userID, roomID, 1));
    cout<<"Room is booked" <<userR->id() <<endl;
    return userR->id();
}


void RoomService::unbookRoom(long roomID){
    rur->archive(roomID);
    cout<<"Room is deleted!"<<roomID<<endl;
}


Room* RoomService::getRoom(long id) {
    return rr->read(id);

}


vector<Room> RoomService::getList(long id){
    vector<Room> rooms = rr->read();
    if(rooms.size() > 0){
        return rooms;
    }
    throw DtoException(Code::InternalServerError, EMPTY_LIST);
}


void RoomService::update(long id, int beds, int tlx, int tly, int brx, int bry){
    Room* room = new Room(id, beds, tlx, tly, brx, bry);
    rr->update(room);    
}