/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include "RoomFeatureService.hxx"
long RoomFeatureService::createRoomFeature(long r_id, long ft_id, long r_num){
    RoomFeature* tmp = rf->create(new RoomFeature(r_id, ft_id, r_num));
    return tmp->id();
}
long RoomFeatureService::createFeatureType(string f, float p){
    FeatureType* tmp = ft->create(new FeatureType(f,p));
    return tmp->id();
}
