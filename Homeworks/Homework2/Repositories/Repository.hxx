/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "DBManager.hxx"
#include "Entities/Book.hxx"
#include "Entities/Book-odb.hxx"
#include "Entities/Role.hxx"
#include "Entities/Role-odb.hxx"
#include "Entities/User.hxx"
#include "Entities/User-odb.hxx"
#include "Entities/UserBook.hxx"
#include "Entities/UserBook-odb.hxx"

template<typename Entity>
class Repository { 
    
    public:
    DBManager* dbm = NULL;
    
    Repository(){
        dbm = &DBManager::getInstance();
    }
    

    Entity* create(Entity* e);
    Entity* read(unsigned long id);
    odb::result<Entity>* read(odb::query<Entity> query);
    void update(Entity* e);
    long del(unsigned long id);

};

#endif