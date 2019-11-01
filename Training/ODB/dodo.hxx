// event.hxx
//
#ifndef DODO_HXX
#define DODO_HXX

#include <string>
#include <iostream>
#include <odb/core.hxx>
  
class dodo
{
private:
  dodo () {}              // (3)

  friend class odb::access; // (4)

  #pragma db id auto        // (5)
  unsigned long id_;        // (5)

  std::string first_;
  std::string last_;
  unsigned short age_;
};

#pragma db object(dodo)

#endif