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
    User (string n, string s) : name_(n), surname_(s) {}                // (3)

    friend class odb::access; // (4)

    const string& name () const;
    void name (const std::string&);
    const string& surname () const;
    void surname (const std::string&);

    #pragma db id auto        // (5)
    unsigned long id_;        // (5)

    private:
      string name_;
      string surname_;
};

#pragma db object(User)

inline std::ostream&
operator<< (std::ostream& os, const User& e)
{
  return os << e.name() << ' ' << e.surname();
}


#endif