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

tuple<int,int,int> RoomService::castDate(long date) {
    time_t tm = date;
    auto lt = std::localtime(&tm);
    lt->tm_hour = 0;
    lt->tm_min = 0;
    lt->tm_sec = 0;   

    return { lt->tm_mday, lt->tm_mon + 1, lt->tm_year + 1900 };
}


void RoomService::confirmPayment(long role, long bookid) {
    if(role > 1){
        UserRoom* booking = rur->read(bookid);
        booking->paid(true);
        rur->update(booking);
    } else {
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }
}


long RoomService::bookRoom(long userID, long roomID, long arrival, long departure){
    // todo invalid date
    int nights = (departure - arrival) % 86400;
    float price = 0;

    vector<FeatureType> types = rft->read();
    vector<RoomFeature> features = rf->read();

    for(RoomFeature f: features){
        if(f.room_id() == roomID){
            price += types[f.feature_type_id() - 1].price() * f.amount();
        }
    }

    UserRoom* userR = rur->create(new UserRoom(userID, roomID, arrival, departure, price, false));
    return userR->id();
}


void RoomService::unbookRoom(long roomID){
    rur->archive(roomID);
}


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


vector<BookDto> RoomService::bookingList(long userid, long role){
    vector<BookDto> result;

    vector<User> users = ru->read();
    vector<Room> rooms = rr->read();
    vector<RoomFeature> features = rf->read();
    vector<FeatureType> types = rft->read();

    vector<UserRoom> bookings;
    
    if(role > 1){ 
        bookings = rur->read();
    } else {
        bookings = rur->read(odb::query<UserRoom>::user_id == userid);
    }

    for(UserRoom b: bookings) {
        Room r = rooms[b.room_id() - 1];
        User u = users[b.user_id() - 1];    
        vector<FeatureDto> roomFeatures;
        
        for(RoomFeature f: features){
            if(f.room_id() == b.room_id()){
                roomFeatures.push_back(FeatureDto(f.feature_type_id(), types[f.feature_type_id() - 1].feature_name(), types[f.feature_type_id() - 1].price(), f.amount()));
            }
        }
        RoomDto rdto = RoomDto(r.id(), r.roomnumber(), roomFeatures);
        UserDto udto = UserDto(u.firstname(), u.lastname(), u.email(), 
                   u.birthdate(), u.address(), u.id(), u.role());
        result.push_back(BookDto(b.id(), rdto, b.arrival(), b.departure(), b.paid(), b.price(), udto));
    }

    return result;
}


/*
void RoomService::update(long id, int beds, int tlx, int tly, int brx, int bry){
    Room* room = new Room(id, beds, tlx, tly, brx, bry);
    rr->update(room);    
}*/