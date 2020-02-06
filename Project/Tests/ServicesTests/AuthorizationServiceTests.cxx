#include "AuthorizationServiceTests.hxx"
#include "DtoException.hxx"

CPPUNIT_TEST_SUITE_REGISTRATION( AuthorizationServiceTests );


void AuthorizationServiceTests::CreateSessionTest(void) {
    // Act
    as = new AuthorizationService();
    string session = as->createSession(1);

    // Assert

    CPPUNIT_ASSERT( session.size() == 64 );
}


void AuthorizationServiceTests::GetSessionTest(void) {
    // Arrange

    long userId = 1;
    as = new AuthorizationService();
    string session = as->createSession(userId);
    
    // Act

    long retrievedId = as->getSession(session);

    // Assert

    CPPUNIT_ASSERT( userId == retrievedId );
}


void AuthorizationServiceTests::UnauthorizedSessionTest(void) {
    // Act & Assert
    CPPUNIT_ASSERT_THROW(as->getSession("unauthorizedsession"), DtoException);
}