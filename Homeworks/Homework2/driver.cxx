#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "Repository.hxx"
#include "Book.hxx"
#include "Book-odb.hxx"
#include "Role.hxx"
#include "Role-odb.hxx"
#include "User.hxx"
#include "User-odb.hxx"
#include "UserBook.hxx"
#include "UserBook-odb.hxx"

#include "UserService.hxx"
#include "BookService.hxx"
#include "UserBookService.hxx"

#include "UI.hxx" 
#include <fstream>

using namespace odb::core;

void db_init(){

        // INIT DB

    Repository<Role>* rr = new Repository<Role>();
    rr->create( new Role("customer") );
    rr->create( new Role("staff") );

    Repository<User>* ur = new Repository<User>();
    ur->create( new User("Dodo", "Dodo", 1) );
    ur->create( new User("Neko", "Neko", 1) );
    ur->create( new User("Dodo", "Neko", 2) );

    
    Repository<Book>* br = new Repository<Book>();
    br->create( new Book(1, 0, "Book1", "Author1", "Publisher1") );
    br->create( new Book(5, 0, "Book2", "Author2", "Publisher2") );
    br->create( new Book(10, 9, "Book3", "Author3", "Publisher3") );

    Repository<UserBook>* ubr = new Repository<UserBook>();
    ubr->create( new UserBook( 1, 2, 100) );

    // $ ... -auth 1 -create user "Dodo" "Neko"
    UserService* us = new UserService();
    us->create(1, "Name", "Surname", 0);
    us->create(3, "Name", "Surname", 0);

    // $ ... -auth 1 -create book 5 0 "Book Title" "Dodo Neko" "Springer Publisher"
    BookService* bs = new BookService();
    bs->create(1, 5, 0, "Book Title", "Dodo Neko", "Springer Publisher");
    bs->create(3, 5, 0, "Book Title", "Dodo Neko", "Springer Publisher");

    // Print the list of available books
    // TODO fix queries, segmentation dump???
    // bs->list();

    // $ ... -create user_book 1 4
    UserBookService* ubs = new UserBookService();
    ubs->create(1, 1);

    // $ ... -delete user_book with id 2
    ubs->del(2);

}

inline bool fileExists (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}


int main(){

    if (! fileExists("mytest.db")){
        db_init();
    }

	CLI interface = CLI();

	interface.start();
}
