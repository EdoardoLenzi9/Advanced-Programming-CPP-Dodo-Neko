/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BUCKETSORT_HPP
#define BUCKETSORT_HPP

#include <vector>
#include "Utils.hpp"


using namespace std;


class BucketSort {

    public:
    
        /**
        * Sorts the statically created vector with the bucket sort algorithm
        */
        void sort(vector<int> &vec)
        {
            const int MAX = get_max(vec);

            // fill the bucket with (max + 1) zeros
            vector<int> buckets(MAX + 1, 0);

            for (int i = 0; i < vec.size(); i++)
                buckets[vec[i]]++; // counts the occurence of a number

            for (int i = 0, j = 0; i <= MAX; i++)
                while (buckets[i])
                {
                    vec[j++] = i; // add next sorted value
                    buckets[i]--; // decrement the occurence of this value
                }
        }
};

#endif