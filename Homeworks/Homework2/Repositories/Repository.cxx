/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <vector>

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


template<typename Entity>
odb::result<Entity>* Repository<Entity>::read(odb::query<Entity> query) 
{
	odb::result<Entity>* res;

	{
		transaction t (dbm->db->begin ());
		// int a = dbm->db->query<User> (query::name == "Dodo");
		res = new odb::result<Entity>(dbm->db->query<Entity> (query));
		t.commit ();
	}
	return res;
}


template<typename Entity>
Entity* Repository<Entity>::read(long id) 
{   
	Entity* res;
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
    {
      	transaction t (dbm->db->begin ());
      	dbm->db->erase<Entity> (id);
      	t.commit ();
    }

	return id; //FIX: this was missing, dodo, i put it in to avoid the compiler warning. maybe this should return a boolean instead.
}

template class Repository<Book>;
template class Repository<Role>;
template class Repository<User>;
template class Repository<UserBook>;
