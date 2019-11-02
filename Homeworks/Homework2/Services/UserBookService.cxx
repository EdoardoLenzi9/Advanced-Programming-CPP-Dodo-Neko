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

#include "UserBookService.hxx"
#include "Repository.hxx"


long UserBookService::create(long user_id, int book_id){
    UserBook* tmp = ubr->create(new UserBook(user_id, book_id, 0));
    cout << "UserBook created" << tmp->id() << endl;
    return tmp->id();
}


void UserBookService::del(long id){
    ubr->del(id);
    cout << "UserBook deleted" << id << endl;
}