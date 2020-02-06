/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOMFEATURE_HXX
#define ROOMFEATURE_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  


class RoomFeature : public BaseEntity
{
	public:
    
	    RoomFeature () {}
	    RoomFeature (long r_id, long ft_id, long r_num) : room_id_(r_id), feature_type_id_(ft_id), room_number_(r_num) {}                 
		
		// Getter and setters
		void room_id( long r ) { room_id_ = r; };
		long room_id() { return room_id_; };

		void feature_type_id( long f ) { feature_type_id_ = f; };
		long feature_type_id() { return feature_type_id_; };

		void room_number( long r ) { room_number_ = r; };
		long room_number() { return room_number_; };
		
		unsigned long id ( ) { return id_; } ;
		
		bool archived() {return archived_; };
		void archived(bool a) {archived_ = a; };
		
		friend class odb::access;  

	
	private:

		long room_id_;
		long feature_type_id_;
		long room_number_;

		#pragma db id auto         
		unsigned long id_;      
		bool archived_;   
};

#pragma db object(RoomFeature)

#endif