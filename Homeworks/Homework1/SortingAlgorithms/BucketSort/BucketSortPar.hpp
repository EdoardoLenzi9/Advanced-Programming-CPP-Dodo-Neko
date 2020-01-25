/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef BUCKETSORTPAR_HPP
#define BUCKETSORTPAR_HPP

#include <vector>
#include "Utils.hpp"
#include <omp.h>
#include "Utils.hpp"
#define THREADS 2

using namespace std;


class BucketSortPar {

    private:
    	void fillBucket(vector<int> &bucket, vector<int> &vec, int num){
			for (int i = 0; i < vec.size(); i++){
				if (i%THREADS == num){
					//cout << "thread " << num << " checking " << i << endl;
					bucket[vec[i]]++;
				}
			}
		}

    public:

        /**
        * Sorts the statically created vector with the bucket sort algorithm
        */
        void sort(vector<int> &vec)
        {
            const int MAX = get_max(vec);

            // fill the bucket with (max + 1) zeros
            vector<int> buckets(MAX + 1, 0);
			
			/*
            for (int i = 0; i < vec.size(); i++)
                buckets[vec[i]]++; // counts the occurence of a number
			*/

			#pragma omp parallel num_threads(THREADS)
			{
				cout << "launching thread " << omp_get_thread_num() << endl;
				fillBucket(buckets, vec, omp_get_thread_num());
			}

            //print_vector(buckets);

	    for (int i = 0, j = 0; i <= MAX; i++)
                while (buckets[i])
                {
                    vec[j++] = i; // add next sorted value
                    buckets[i]--; // decrement the occurence of this value
                }
        }
};

#endif
