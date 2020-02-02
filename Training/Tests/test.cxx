#include <cppunit/extensions/HelperMacros.h>
#include "test.hxx"

CPPUNIT_TEST_SUITE_REGISTRATION( CritterTest );

void CritterTest::TestMemorySmoke(void) {
  CPPUNIT_ASSERT( true );
  CPPUNIT_ASSERT( false );
  CPPUNIT_ASSERT( true ); /* this should fail */
}