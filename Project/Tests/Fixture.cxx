#include "Fixture.hxx"

void Fixture::AssertEqual( User * u1, User * u2){
    CPPUNIT_ASSERT( u1->id() == u2->id() );
    CPPUNIT_ASSERT( u1->firstname() == u2->firstname() );
    CPPUNIT_ASSERT( u1->lastname() == u2->lastname() );
    CPPUNIT_ASSERT( u1->role() == u2->role() );
}