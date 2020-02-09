/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <iostream>

#include "UserRoomService.hxx"


void UserRoomService::update(long userid, long role, long bookid, long arrival, long departure){

    UserRoom* booking = rur->read(bookid);

    if(role == RoleCode::Customer && booking->user_id() != userid){
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }

    if(!booking->paid()){
        booking->arrival(arrival);
        booking->departure(departure);

        set<long> reservedRooms = UserRoomService::reservedRooms(arrival, departure, booking->id());

        if(reservedRooms.find(booking->room_id()) == reservedRooms.end()){
            rur->update(booking);
        } else {
            throw DtoException(Code::Unauthorized, UNAVAILABLE);
        }
    } else {
        throw DtoException(Code::Unauthorized, PAID);
    }
}


set<long> UserRoomService::reservedRooms(long startdate, long enddate, long bookid){
    typedef odb::query<UserRoom> urq;
    vector<UserRoom> bookings = rur->read( ( urq::arrival >= startdate && 
                                             urq::arrival <= enddate ) ||
                                           ( urq::departure >= startdate && 
                                             urq::departure <= enddate ) );
    set<long> reservedRooms;
    if(bookings.size() > 0){
        for(UserRoom book: bookings){
            if(book.id() != bookid) {
                reservedRooms.insert(book.room_id());
            }
        }
    }

    return reservedRooms;
}


void UserRoomService::del(long userId, long role, long id){
    if(role > RoleCode::Customer){
        rur->archive(id);
    } else {
        if(rur->read(id)->user_id() == userId){
            rur->archive(id);
        } else {
            throw DtoException(Code::Unauthorized, UNAUTHORIZED);
        }
    }
}


vector<BookDto> UserRoomService::bookingList(long userid, long role){
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


void UserRoomService::confirmPayment(long role, long bookid) {
    if(role > 1){
        UserRoom* booking = rur->read(bookid);
        booking->paid(true);
        rur->update(booking);
    } else {
        throw DtoException(Code::Unauthorized, UNAUTHORIZED);
    }
}


long UserRoomService::bookRoom(long userID, long roomID, long arrival, long departure){

    set<long> reservedRooms = UserRoomService::reservedRooms(arrival, departure, 0);

    if(reservedRooms.find(roomID) != reservedRooms.end()){
        throw DtoException(Code::Unauthorized, UNAVAILABLE);
    }

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


void UserRoomService::unbookRoom(long roomID){
    rur->archive(roomID);
}


/*
tuple<int,int,int> UserRoomService::castDate(long date) {
    time_t tm = date;
    auto lt = std::localtime(&tm);
    lt->tm_hour = 0;
    lt->tm_min = 0;
    lt->tm_sec = 0;   

    return { lt->tm_mday, lt->tm_mon + 1, lt->tm_year + 1900 };
}*/
