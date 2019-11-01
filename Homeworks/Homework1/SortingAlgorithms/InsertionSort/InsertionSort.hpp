/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP


#include <vector>


using namespace std;


class InsertionSort {
    public:
    
        /**
        * insertion sort algorithm for statically created vectors
        */
        template <typename T>
        void sort(vector<T> &vec) {
            T x; // used for swapping elements
            int i = 1;
            int k; // used to iterate 'backwards' to find position

            while (i < vec.size()) {
                x = vec[i];
                k = i - 1;

                while (k >= 0 && vec[k] > x) {
                    vec[k + 1] = vec[k]; // just swapping around
                    --k;
                }

                vec[k + 1] = x;
                ++i;
            }
        }
};

#endif