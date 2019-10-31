#ifndef ROLE_REPOSITORY_HXX
#define ROLE_REPOSITORY_HXX

#include <iostream>
#include <string>
#include <odb/core.hxx>
  
class Role
{
  private:
    
    Role () {}                // (3)

    friend class odb::access; // (4)

    std::string description;

    #pragma db id auto        // (5)
    unsigned long id_;        // (5)
};

#pragma db object(Role)

#endif