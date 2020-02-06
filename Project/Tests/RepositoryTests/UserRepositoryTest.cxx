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

    f->AssertEqual( res, u);
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

    f->AssertEqual( res1, u1);
    f->AssertEqual( res2, u2);
}


void UserRepositoryTest::QueryUsersTest(void) {
    // Arrange 

    User * u1 = new User("A1", "B1", 1);
    User * u2 = new User("A2", "B2", 2);

    ur->create(u1);
    ur->create(u2);

    // Act

    User * res1 = ur->read(u1->id());
    vector<User> res2 = ur->read(odb::query<User>::email == "A1");

    // Assert

    f->AssertEqual( res1, u1);
}