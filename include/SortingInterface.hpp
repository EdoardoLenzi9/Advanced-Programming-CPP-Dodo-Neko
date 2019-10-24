#ifndef SORTING_INTERFACE_HPP
#define SORTING_INTERFACE_HPP

#include <vector>

using namespace std;

class SortingInterface {
public:
  template <typename T>
  void sort(vector<T> &vec);
};

#endif