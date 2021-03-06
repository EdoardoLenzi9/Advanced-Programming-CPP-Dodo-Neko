/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "DBManager.hxx"

using namespace std;
using namespace odb::core;
 

DBManager::DBManager()
{

    if(db == NULL) 
    {
        db = new odb::sqlite::database( "mytest.db",
             SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE );
        // createSchema();
    }
}


