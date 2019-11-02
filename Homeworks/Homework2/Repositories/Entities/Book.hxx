/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BOOK_HXX
#define BOOK_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  


using namespace std;


class Book : public BaseEntity
{

	public:

		Book () {}
		Book (int c, int r, string t, string a, string p) : copies_(c), rented_(r), title_(t),
															author_(a), publisher_(p) {}                 
		
		// Getter and setters
		void copies( int c ) { copies_ = c; };
		int copies() { return copies_; };

		void rented( int r ) { rented_ = r; };
		int rented() { return rented_; };

		void title( string t ) { title_ = t; };
		string title() { return title_; };

		void author( string a ) { author_ = a; };
		string author() { return author_; };

		void publisher( string p ) { publisher_ = p; };
		string publisher() { return publisher_; };

		unsigned long id ( ) { return id_; } ;

		friend class odb::access;  


	private:
    
		int copies_;
		int rented_;
		std::string title_;
		std::string author_;
		std::string publisher_;

		#pragma db id auto         
		unsigned long id_;         
};

#pragma db object(Book)

#endif