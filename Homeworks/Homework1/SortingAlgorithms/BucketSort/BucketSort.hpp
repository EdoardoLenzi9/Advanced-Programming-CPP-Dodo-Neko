/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 24/01/20 
    @license WTFPL v2  
**/


#ifndef BUCKETSORT_HPP
#define BUCKETSORT_HPP

#include <vector>


using namespace std;


class BucketSort {

    public:
    
        int get_max(const vector<int> &vec)
        {
            int max = 0;
            for (int i = 0; i < vec.size(); i++)
                if (vec[i] > max)
                    max = vec[i];

            return max;
        }

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
