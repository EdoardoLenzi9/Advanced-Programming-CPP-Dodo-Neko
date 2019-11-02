/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef USER_BOOK_SERVICE_HPP
#define USER_BOOK_SERVICE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Repository.hxx"
#include "UserService.hxx"

class UserBookService { 
    
    public:
        UserBookService(){
            ubr = new Repository<UserBook>();
            us = new UserService();
        }

        long create(long user_id, int book_id);
        void del(long id);    
        
    private:
        UserService* us;
        Repository<UserBook>* ubr;
};

#endif