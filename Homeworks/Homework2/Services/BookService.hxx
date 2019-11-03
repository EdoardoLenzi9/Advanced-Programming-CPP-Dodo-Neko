/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BOOK_SERVICE_HPP
#define BOOK_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"
#include "UserService.hxx"

class BookService { 
    
    public:
        BookService(){
            br = new Repository<Book>();
            us = new UserService();
        }

        long create(long auth, int copies, int rented, string title, string author, string publisher);    
        void list();
        
    private:
        UserService* us;
        Repository<Book>* br;
};

#endif