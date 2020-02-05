#include "RegistrationTests.hxx"


CPPUNIT_TEST_SUITE_REGISTRATION( RegistrationTests );


void RegistrationTests::RegistrationTest(void) {
    // Arrange 

    User * u = new User("A", "B", 1);
    ur->create(u);

    // Act

    User * res = ur->read(u->id());

    // Assert

    f->AssertEqual( res, u);
}