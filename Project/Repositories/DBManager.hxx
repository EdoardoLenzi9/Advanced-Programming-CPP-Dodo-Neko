/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include <string>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>


using namespace std;
using namespace odb::core;


// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

class DBManager // Singleton
{

    public:

        odb::sqlite::database* db = NULL;
        
        static DBManager& getInstance(){
            static DBManager instance; 
            return instance;
        }
        

        void resetDB(){
            createSchema();
        }


    private:
        
        void createSchema() 
        {
            {
                transaction t (db->begin ());
                schema_catalog::create_schema (*db);
                t.commit ();
            }
        }

        DBManager();

};

#endif