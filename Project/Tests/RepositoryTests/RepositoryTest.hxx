#ifndef REPOSITORY_TEST_HXX
#define REPOSITORY_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class RepositoryTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( RepositoryTest );
  CPPUNIT_TEST( DBMoqTest );
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp(void) {}    // I don't use setUp or tearDown yet, but let's 
  void tearDown(void) {} // leave them in so I remember their names

  void DBMoqTest(void); 
};

#endif /* REPOSITORY_TEST_HXX */