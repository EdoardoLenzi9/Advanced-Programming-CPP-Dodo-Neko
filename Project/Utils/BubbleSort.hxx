/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 24/01/20 
    @license WTFPL v2  
**/


#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <vector>
#include <omp.h>

using namespace std;


class Tuple{
    public:
        long index;
        float value;

        Tuple(long i, float v): index(i), value(v) {}
};


class BubbleSort {

    public:

        void sort(vector<Tuple> &vec)
        {
            for (int n = 0; n < vec.size() - 1; n++)
                for (int k = 0; k < vec.size() - n - 1; k++)
                    if (vec.at(k).value > vec.at(k + 1).value)
                        swap(vec[k], vec[k + 1]);
        };
};

#endif
