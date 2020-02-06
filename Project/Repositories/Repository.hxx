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
#include "Entities/Room.hxx"
#include "Entities/Room-odb.hxx"
#include "Entities/Role.hxx"
#include "Entities/Role-odb.hxx"
#include "Entities/User.hxx"
#include "Entities/User-odb.hxx"
#include "Entities/UserRoom.hxx"
#include "Entities/UserRoom-odb.hxx"
#include "Entities/Authorization.hxx"
#include "Entities/Authorization-odb.hxx"
#include "Entities/RoomFeature.hxx"
#include "Entities/RoomFeature-odb.hxx"
#include "Entities/FeatureType.hxx"
#include "Entities/FeatureType-odb.hxx"


template<typename Entity>
class Repository { 
    
    public:
    DBManager* dbm = NULL;
    
    Repository(){
        dbm = &DBManager::getInstance();
    }

    Repository(DBManager* dbm) : dbm(dbm) { }

    Entity* create(Entity* e);
    Entity* read(unsigned long id);
    vector<Entity> read(odb::query<Entity> query);
    Entity* readAll(unsigned long id);
    vector<Entity> readAll(odb::query<Entity> query);
    void update(Entity* e);
    long archive(unsigned long id);
    bool del(unsigned long id);

};

#endif