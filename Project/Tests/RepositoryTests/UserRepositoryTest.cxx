#include <cppunit/extensions/HelperMacros.h>
#include "UserRepositoryTest.hxx"

CPPUNIT_TEST_SUITE_REGISTRATION( UserRepositoryTest );

void UserRepositoryTest::CreateUserTest(void) {
    User * u = new User();
    ur -> create(u);
    CPPUNIT_ASSERT( true );
}