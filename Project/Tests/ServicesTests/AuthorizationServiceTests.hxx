#ifndef AUTHORIZATION_SERVICE_TEST_HXX
#define AUTHORIZATION_SERVICE_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "DBManager.hxx"
#include "Repository.hxx"
#include "User.hxx"
#include "Fixture.hxx"
#include "AuthorizationService.hxx"

class AuthorizationServiceTests : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( AuthorizationServiceTests );
    
    CPPUNIT_TEST( CreateSessionTest );
    CPPUNIT_TEST( GetSessionTest );
    CPPUNIT_TEST( UnauthorizedSessionTest );

    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void) { 
            as = new AuthorizationService(); 
            db = &DBManager::getInstance();
            f = new Fixture();
        }     

        void tearDown(void) { 
            db->resetDB();
            delete as; 
        } 

        void CreateSessionTest(void);
        void GetSessionTest(void);
        void UnauthorizedSessionTest(void);

    private:
        Fixture * f;
        AuthorizationService * as;
        DBManager * db;
};

#endif /* AUTHORIZATION_SERVICE_TEST_HXX */