#ifndef USERBOOK_REPOSITORY_HXX
#define USERBOOK_REPOSITORY_HXX

#include <iostream>
#include <string>
#include <odb/core.hxx>
  
class UserBook
{
  private:
    
    UserBook () {}                // (3)

    friend class odb::access; // (4)

    long user_id;
    long book_id;
    long timestamp;

    #pragma db id auto        // (5)
    unsigned long id_;        // (5)
};

#pragma db object(UserBook)

#endif