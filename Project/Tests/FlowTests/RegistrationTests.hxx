#ifndef REGISTRATION_TEST_HXX
#define REGISTRATION_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "DBManager.hxx"
#include "Repository.hxx"
#include "User.hxx"
#include "Fixture.hxx"


class RegistrationTests : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( RegistrationTests );
    
    CPPUNIT_TEST( RegistrationTest );

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void) { 
            ur = new Repository<User>(); 
            db = &DBManager::getInstance();
            f = new Fixture();
        }     

        void tearDown(void) { 
            db->resetDB();
            delete ur; 
        } 

        void RegistrationTest(void);
  
    private:
        Fixture * f;
        Repository<User> * ur;
        DBManager * db;
};

#endif /* REGISTRATION_TEST_HXX */