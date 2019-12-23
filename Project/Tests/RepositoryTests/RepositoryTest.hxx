#ifndef REPOSITORY_TEST_HXX
#define REPOSITORY_TEST_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class RepositoryTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE( RepositoryTest );
  CPPUNIT_TEST( DBMoqTest );
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp(void) {}     
  void tearDown(void) {} 

  void DBMoqTest(void); 
};

#endif /* REPOSITORY_TEST_HXX */