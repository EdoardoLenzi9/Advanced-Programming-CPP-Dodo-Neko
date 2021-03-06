#ifndef USER_REPOSITORY_TEST_HXX
#define USER_REPOSITORY_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "DBManager.hxx"
#include "Repository.hxx"
#include "User.hxx"
#include "Fixture.hxx"

class UserRepositoryTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( UserRepositoryTest );
    
    CPPUNIT_TEST( CreateUserTest );
    CPPUNIT_TEST( CreateUsersTest );
    CPPUNIT_TEST( QueryUsersTest );

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

        void CreateUserTest(void);
        void CreateUsersTest(void);
        void QueryUsersTest(void); 
  
    private:
        Fixture * f;        
        Repository<User> * ur;
        DBManager * db;
};

#endif /* USER_REPOSITORY_TEST_HXX */