/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef ROOM_HXX
#define ROOM_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  

using namespace std;


class Room : public BaseEntity
{

	public:

		Room () {}
		Room (int b, int tlx, int tly, int brx, int bry) : beds_(b), tl_x_(tlx), tl_y_(tly), 
														   br_x_(brx), br_y_(bry) {}                 
		
		// Getter and setters

		void beds( int b ) { beds_ = b; };
		int beds() { return beds_; };

		void tlx( int tlx ) { tl_x_ = tlx; };
		int tlx() { return tl_x_; };

		void tly( int tly ) { tl_y_ = tly; };
		int tly() { return tl_y_; };

		void brx( int brx ) { br_x_ = brx; };
		int brx() { return br_x_; };

		void bry( int bry ) { br_y_ = bry; };
		int bry() { return br_y_; };

		unsigned long id ( ) { return id_; } ;

		friend class odb::access;  


	private:
    
		int beds_;

		// top-left coords
		int tl_x_;
		int tl_y_;
		
		// bottom-right coords
		int br_x_;
		int br_y_;

		#pragma db id auto         
		unsigned long id_;         
};

#pragma db object(Room)

#endif