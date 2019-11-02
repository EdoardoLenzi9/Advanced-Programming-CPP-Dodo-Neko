#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "Repository.hxx"
#include "Entities/User.hxx"
#include "Entities/User-odb.hxx"

using namespace odb::core;

int main(){
    Repository<User>* r = new Repository<User>();
    User* u = new User("Dodo", "Neko");
    User* u2 = r->create(u);
    User* u3 = r->read(u2->id());
    u3->name("Dodo2");
    r->update(u3);
    User* u4 = r->read(u3->id());
    cout << u4->name();
}