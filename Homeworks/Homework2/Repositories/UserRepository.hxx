#ifndef USER_REPOSITORY_HXX
#define USER_REPOSITORY_HXX

#include <iostream>
#include <string>
#include <odb/core.hxx>
  
using namespace std;

class User
{
  public:
    User () {}
    User (string n, string s) : name(n), surname(s) {}                // (3)

    friend class odb::access; // (4)

    string name;
    string surname;

    #pragma db id auto        // (5)
    unsigned long id_;        // (5)
};

#pragma db object(User)

inline std::ostream&
operator<< (std::ostream& os, const User& e)
{
  return os << e.name << ' ' << e.surname;
}


#endif