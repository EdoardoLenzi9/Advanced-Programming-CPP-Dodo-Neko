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

#include "BookService.hxx"
#include "Repository.hxx"

long BookService::create(long auth, int copies, int rented, string title, string author, string publisher){
    if( us->getRole(auth) == 2 ){
        Book* tmp = br->create(new Book(copies, rented, title, author, publisher));
        cout << "Book created" << tmp->id() << endl;
        return tmp->id();
    } 
    cerr << "Auth level exception" << endl;
    return 0;
}


void BookService::list(){
    odb::result<Book>* availableBooks = br->read(odb::query<Book>::title == "Book Title");

    for (odb::result<Book>::iterator i (availableBooks->begin ()); i != availableBooks->end (); ++i)
        cout << i->title() << endl;
}