#include <unistd.h> // sleep()
#include <iostream>
#include <string>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include <iostream>
#include "Repositories/Entities/User-odb.hxx"
#include "Repositories/Entities/User.hxx"
#include "Repositories/Entities/UserBook-odb.hxx"
#include "Repositories/Entities/UserBook.hxx"
#include "Repositories/Entities/Role-odb.hxx"
#include "Repositories/Entities/Role.hxx"
#include "Repositories/Entities/Book-odb.hxx"
#include "Repositories/Entities/Book.hxx"

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
