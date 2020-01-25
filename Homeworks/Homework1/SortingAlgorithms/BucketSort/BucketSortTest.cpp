/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 24/01/20 
    @license WTFPL v2  
**/


#include <vector>
#include <iostream>
#include <time.h>
#include "BucketSort.hpp"
#include "Utils.hpp"


using namespace std;

void testSort(int size) {
    clock_t t; 
    vector<int> vec;
    
    vec.reserve(size);
    fill_vector(vec, 0, size/10);

    vector<int> vecp(vec);

    BucketSort bs;

    t = clock(); 
    bs.sort(vec);
    t = clock() - t; 

    cout << "Vector sorted: " << is_sorted(vec) << " took: " << t << endl << endl;
}



void testMax(int size){
    clock_t t; 
    vector<int> vec;
    
    vec.reserve(size);
    fill_vector(vec, 0, size/10);

    vector<int> vecp(vec);

    BucketSort bs;

    t = clock();
    int max = bs.get_max(vec);
    t = clock() - t; 

    cout << "Max" << max << " took: " << t << endl << endl;
}

int main(void)
{
    int dim = 100000;
    testSort(dim);
    return 0;
}
