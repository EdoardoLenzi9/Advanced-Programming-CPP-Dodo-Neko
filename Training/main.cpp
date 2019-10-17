#include <iostream> 
#include <vector>
#include "Generics.hpp"
using namespace std; 
  
  
int main() 
{ 
    int arr[5] = { 1, 2, 3, 4, 5 }; 
    Vector<int> a(5); 
    a.print(); 
    return 0; 
} 