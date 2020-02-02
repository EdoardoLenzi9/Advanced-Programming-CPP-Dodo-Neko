#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>
#include <odb/sqlite/database.hxx>

#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include "UserRepositoryTest.hxx"


CPPUNIT_TEST_SUITE_REGISTRATION( UserRepositoryTest );


void UserRepositoryTest::CreateUserTest(void) {
    // Arrange 

    User * u = new User("A", "B", 1);
    ur->create(u);

    // Act

    User * res = ur->read(u->id());

    // Assert

    AssertEqual( res, u);
}


void UserRepositoryTest::CreateUsersTest(void) {
    // Arrange 

    User * u1 = new User("A1", "B1", 1);
    User * u2 = new User("A2", "B2", 2);

    ur->create(u1);
    ur->create(u2);

    // Act

    User * res1 = ur->read(u1->id());
    User * res2 = ur->read(u2->id());

    // Assert

    AssertEqual( res1, u1);
    AssertEqual( res2, u2);
}


void UserRepositoryTest::QueryUsersTest(void) {
    // Arrange 

    User * u1 = new User("A1", "B1", 1);
    User * u2 = new User("A2", "B2", 2);

    ur->create(u1);
    ur->create(u2);

    // Act

    User * res1 = ur->read(u1->id());
    vector<User> res2 = ur->read(odb::query<User>::name == "A1");

    // Assert

    AssertEqual( res1, u1);
}


void UserRepositoryTest::AssertEqual( User * u1, User * u2){
    CPPUNIT_ASSERT( u1->id() == u2->id() );
    CPPUNIT_ASSERT( u1->name() == u2->name() );
    CPPUNIT_ASSERT( u1->surname() == u2->surname() );
    CPPUNIT_ASSERT( u1->role() == u2->role() );
}