#ifndef FIXTURE_HXX
#define FIXTURE_HXX

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "User.hxx"


class Fixture {
  
    public:
        void AssertEqual( User * u1, User * u2);
};

#endif /* FIXTURE_HXX */