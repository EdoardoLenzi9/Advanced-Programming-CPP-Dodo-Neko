/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include "RoomService.hxx"

/*
long RoomService::create(int beds, int tlx, int tly, int brx, int bry){
    Room* tmp = rr->create(new Room(beds, tlx, tly, brx, bry));
    cout << "Room created" << tmp->id() << endl;
    return tmp->id();
}*/


Room* RoomService::getRoom(long id) {
    return rr->read(id);

}


vector<RoomDto> RoomService::getAvailableRooms(long startdate, long enddate){
    vector<RoomDto> result;

    vector<Room> rooms = rr->read();
    vector<RoomFeature> features = rf->read();
    vector<FeatureType> types = rft->read();

    typedef odb::query<UserRoom> urq;
    vector<UserRoom> bookings = rur->read( ( urq::arrival >= startdate && 
                                             urq::arrival <= enddate ) ||
                                           ( urq::departure >= startdate && 
                                             urq::departure <= enddate ) );
    set<long> reservedRooms;
    if(bookings.size() > 0){
        for(UserRoom book: bookings){
            reservedRooms.insert(book.room_id());
        }
    }

    for(Room r: rooms){
        if(reservedRooms.find(r.id()) == reservedRooms.end()){

            vector<FeatureDto> roomFeatures;
            for(RoomFeature f: features){
                if(f.room_id() == r.id()){
                    roomFeatures.push_back(FeatureDto(f.feature_type_id(), types[f.feature_type_id() - 1].feature_name(), types[f.feature_type_id() - 1].price(), f.amount()));
                }
            }

            result.push_back(RoomDto(r.id(), r.roomnumber(), roomFeatures));
        }
    }

    return result;
}


/*
void RoomService::update(long id, int beds, int tlx, int tly, int brx, int bry){
    Room* room = new Room(id, beds, tlx, tly, brx, bry);
    rr->update(room);    
}*/