#ifndef CRITTERTEST_H
#define CRITTERTEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class CritterTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( CritterTest );
  CPPUNIT_TEST( TestMemorySmoke );
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp(void) {}    // I don't use setUp or tearDown yet, but let's 
  void tearDown(void) {} // leave them in so I remember their names

  void TestMemorySmoke(void); 
};

#endif /* CRITTERTEST_H */