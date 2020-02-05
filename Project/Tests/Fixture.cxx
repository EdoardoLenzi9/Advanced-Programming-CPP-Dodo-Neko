#include "Fixture.hxx"

void Fixture::AssertEqual( User * u1, User * u2){
    CPPUNIT_ASSERT( u1->id() == u2->id() );
    CPPUNIT_ASSERT( u1->username() == u2->username() );
    CPPUNIT_ASSERT( u1->role() == u2->role() );
}