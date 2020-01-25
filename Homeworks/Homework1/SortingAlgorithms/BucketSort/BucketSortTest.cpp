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


int main(void)
{
    int size = 1000000;
    vector<int> vec;
    clock_t t; 

    vec.reserve(size);

    fill_vector(vec, 0, 10000);

    vector<int> vecp(vec);
    
    cout << endl;

    BucketSort bs;
    t = clock(); 
    bs.sort(vec);
    t = clock() - t; 
    cout << "Vector sorted: " << is_sorted(vec) << " took: " << t << endl
         << endl;

    BucketSortPar bsp;
    t = clock();
    bsp.sort(vecp);
    t = clock() - t; 
    cout << "Vector sorted: " << is_sorted(vecp) << " took: " << t << endl
         << endl;

    return 0;
}
