#include <iostream> 
#include <vector>
using namespace std; 
  
template <typename T> 
class Vector { 
private: 
    vector< T > data;
    int size; 
  
public: 
    Vector(int s); 
    void print(); 
}; 
  