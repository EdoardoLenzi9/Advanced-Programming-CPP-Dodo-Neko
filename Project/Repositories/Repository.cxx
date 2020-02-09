/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/

#include <string>
#include <vector>
#include <iostream>

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
	  	e->archived(false);
    	dbm->db->persist ( *e );
    	t.commit ();
    }
    return e;
}


template<typename Entity>
vector<Entity> Repository<Entity>::readAll(odb::query<Entity> query) 
{
	vector<Entity> res;

	{
		transaction t (dbm->db->begin ());

		odb::result<Entity> r(dbm->db->query<Entity> (query));

		for(Entity& e: r){
			res.push_back(e);
		}

		t.commit ();
	}

	return res;
}


template<typename Entity>
Entity* Repository<Entity>::readAll(unsigned long id) 
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
vector<Entity> Repository<Entity>::readAll() 
{   
	vector<Entity> res;

	{
		transaction t (dbm->db->begin ());

		odb::result<Entity> r(dbm->db->query<Entity> (odb::query<Entity>::id > 0));

		for(Entity& e: r){
			res.push_back(e);
		}

		t.commit ();
	}

	return res;
}


template<typename Entity>
vector<Entity> Repository<Entity>::read(odb::query<Entity> query) 
{
	vector<Entity> res;

	{
		transaction t (dbm->db->begin ());

		odb::result<Entity> r(dbm->db->query<Entity> (query));

		for(Entity& e: r){
			if(!e.archived()){
				res.push_back(e);
			}
		}

		t.commit ();
	}

	return res;
}


template<typename Entity>
Entity* Repository<Entity>::read(unsigned long id) 
{   
	Entity* res;
    {
		transaction t (dbm->db->begin ());
		Entity* pivot(dbm->db->load<Entity> (id));
		res = pivot; 
		t.commit ();
  	}

	if(res->archived()){
		return NULL;
	}  

 	return res;
}


template<typename Entity>
vector<Entity> Repository<Entity>::read() 
{   
	vector<Entity> res;

	{
		transaction t (dbm->db->begin ());

		odb::result<Entity> r(dbm->db->query<Entity> (odb::query<Entity>::archived == false));

		for(Entity& e: r){
			res.push_back(e);
		}

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
long Repository<Entity>::archive(unsigned long id){
	{
		transaction t (dbm->db->begin ());

		Entity* pivot (dbm->db->load<Entity> (id)); 
		pivot->archived(true);
		dbm->db->update(*pivot);

		t.commit ();
	}
}


template<typename Entity>
bool Repository<Entity>::del(unsigned long id){
    {
      	transaction t (dbm->db->begin ());
      	dbm->db->erase<Entity> (id);
      	t.commit ();
    }

	return true;
}


template class Repository<Room>;
template class Repository<Role>;
template class Repository<User>;
template class Repository<UserRoom>;
template class Repository<Authorization>;
template class Repository<RoomFeature>;
template class Repository<FeatureType>;