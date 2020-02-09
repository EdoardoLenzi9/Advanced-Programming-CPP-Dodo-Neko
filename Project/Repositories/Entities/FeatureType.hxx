/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef FEATURETYPE_HXX
#define FEATURETYPE_HXX

#include <string>
#include <odb/core.hxx>
  
#include "BaseEntity.hxx"  

using namespace std;


class FeatureType : public BaseEntity
{
	public:
    
	    FeatureType () {}
	    FeatureType (string f, float p) : feature_name_(f), price_(p) {}                 
		
		// Getter and setters
		void feature_name( string f ) { feature_name_ = f; };
		string feature_name() { return feature_name_; };


		void price( float p ) { price_ = p; };
		float price() { return price_; };
		
		unsigned long id ( ) { return id_; } ;
		
		bool archived() {return archived_; };
		void archived(bool a) {archived_ = a; };
		
		friend class odb::access;  

	
	private:

		string feature_name_;
		float price_;

		#pragma db id auto         
		unsigned long id_;     
		bool archived_;    
};

#pragma db object(FeatureType)

#endif