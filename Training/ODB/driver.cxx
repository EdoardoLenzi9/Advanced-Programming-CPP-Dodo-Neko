#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include <iostream>
#include "dodo-odb.hxx"
#include "dodo.hxx"

using namespace std;
using namespace odb::core;
 
int main ()
{
  odb::sqlite::database db (
    "mytest.db",
    SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);
 
  // Create the database schema.
  //
  {
    transaction t (db.begin ());
    schema_catalog::create_schema (db);
    t.commit ();
  }
 
}