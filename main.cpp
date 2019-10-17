#include "Matrix.hpp"
#include "Vector.hpp"
#include<vector>
#include<iostream>

bool lt (int a, int b){
    return a < b;
}

int main( void ) {
    int mydata[] = {1,3,2,4,5};
    vector<int> data(mydata, mydata + (sizeof(mydata) / sizeof(mydata[0])));
    Vector<int> a ( data ); 
    a.print();
    cout << a.isSorted(lt);
    a.bubblesort(lt);
    a.print();
    cout << a.isSorted(lt);
    return 0;
}