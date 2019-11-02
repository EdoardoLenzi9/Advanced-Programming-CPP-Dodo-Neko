/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include "Repository.hxx"


template<typename Entity>
Entity* Repository<Entity>::create(Entity* e) 
{
    {
      transaction t (dbm->db->begin ());
    	dbm->db->persist ( *e );
    	t.commit ();
    }
    return e;
}


//template<typename Entity>
//vector<Entity> Repository<Entity>::read(long id) 
//{
//  vector<Entity> res;
//
//  typedef odb::query<Entity> query;
//  typedef odb::result<Entity> result;
//
//  // Find all the transactions involving AMD.
//  //
//  {
//    transaction t (dbm->db->begin ());
//    // int a = dbm->db->query<User> (query::name == "Dodo");
//    result r (dbm->db->query<Entity> (query::name == "Dodo"));
//
//    for (result::iterator i (r.begin ()); i != r.end (); ++i)
//      cerr << *i << endl;
//
//    t.commit ();
//  }
//  return res;
//}


template<typename Entity>
Entity* Repository<Entity>::read(long id) 
{   Entity* res;
    {
    transaction t (dbm->db->begin ());
    Entity* pivot(dbm->db->load<Entity> (id));
    res = pivot; 
    t.commit ();
  }
  return res;
}


template<typename Entity>
void Repository<Entity>::update(Entity* e) 
{
  {
    transaction t (dbm->db->begin ());

    Entity* pivot (dbm->db->load<Entity> (e->id())); 
    pivot = e;
    dbm->db->update(*pivot);

    t.commit ();
  }
}


template<typename Entity>
long Repository<Entity>::del(long id){
    return 0;
}

template class Repository<Book>;
template class Repository<Role>;
template class Repository<User>;
template class Repository<UserBook>;