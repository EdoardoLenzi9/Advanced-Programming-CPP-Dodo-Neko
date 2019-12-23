#ifndef USER_REPOSITORY_TEST_HXX
#define USER_REPOSITORY_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Repository.hxx"
#include "User.hxx"


class UserRepositoryTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( UserRepositoryTest );
    CPPUNIT_TEST( CreateUserTest );
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void) { ur = new Repository<User>(); }     
        void tearDown(void) { /* delete ur; */ } 

        void CreateUserTest(void); 
  
    private:
        Repository<User> * ur;
};

#endif /* USER_REPOSITORY_TEST_HXX */