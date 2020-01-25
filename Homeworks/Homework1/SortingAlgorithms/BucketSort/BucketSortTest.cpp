/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include <vector>
#include <iostream>
#include <time.h>
#include "BucketSort.hpp"
#include "BucketSortPar.hpp"
#include "Utils.hpp"


using namespace std;

void testSort(int size){
    clock_t t; 
    vector<int> vec;
    
    vec.reserve(size);
    fill_vector(vec, 0, size/10);

    vector<int> vecp(vec);

    BucketSort bs;
    BucketSortPar bsp;

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
    BucketSortPar bsp;

    t = clock();
    int max = bs.get_max(vec);
    t = clock() - t; 

    cout << "Max" << max << " took: " << t << endl << endl;
}

int main(void)
{
    int dim = 10000000;
    testSort(dim);
    return 0;
}
