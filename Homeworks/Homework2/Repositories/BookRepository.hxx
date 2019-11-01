#ifndef BOOK_REPOSITORY_HXX
#define BOOK_REPOSITORY_HXX

#include <iostream>
#include <string>
#include <odb/core.hxx>
  
class Book
{
  private:
    
    Book () {}                // (3)

    friend class odb::access; // (4)

    int copies;
    int rented;
    std::string title;
    std::string author;
    std::string publisher;

    #pragma db id auto        // (5)
    unsigned long id_;        // (5)
};

#pragma db object(Book)

#endif