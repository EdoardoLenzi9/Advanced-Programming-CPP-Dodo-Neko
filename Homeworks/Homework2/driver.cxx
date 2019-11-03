#include <unistd.h> // sleep()
#include <iostream>
#include <string>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include <iostream>
#include "Repositories/UserRepository-odb.hxx"
#include "Repositories/UserRepository.hxx"
#include "Repositories/UserBookRepository-odb.hxx"
#include "Repositories/UserBookRepository.hxx"
#include "Repositories/RoleRepository-odb.hxx"
#include "Repositories/RoleRepository.hxx"
#include "Repositories/BookRepository-odb.hxx"
#include "Repositories/BookRepository.hxx"

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

  {
    transaction t (db.begin ());
    User u ("Dodo", "Neko");
    db.persist ( u );
    t.commit ();
  }

  //
  //
  typedef odb::query<User> query;
  typedef odb::result<User> result;

  // Find all the transactions involving AMD.
  //
  {
    transaction t (db.begin ());

    result r (db.query<User> (query::name == "Dodo"));

    for (result::iterator i (r.begin ()); i != r.end (); ++i)
      cerr << *i << endl;

    t.commit ();
  }

  {
    transaction t (db.begin ());

    auto_ptr<User> dodo (db.load<User> (1)); //user id
    dodo->name = "Updated name";
    db.update(*dodo);

    t.commit ();
    }
}
