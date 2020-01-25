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
#define THREADS 4

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

        int get_max(const vector<int> &vec)
        {
            int max = 0;
            int * localMax = new int[omp_get_num_threads()]; 

            #pragma omp parallel
            {
                #pragma omp for schedule(static, vec.size() / omp_get_num_threads() - 1)
                for (int i = 0; i < vec.size(); i++){
                    if (vec[i] > localMax[omp_get_thread_num()])
                        localMax[omp_get_thread_num()] = vec[i];
                }

                #pragma omp critical
                {
                    if(localMax[omp_get_thread_num()] > max){
                        max = localMax[omp_get_thread_num()];
                    }
                }
            }
            return max;
        }

        /**
        * Sorts the statically created vector with the bucket sort algorithm
        */
        void sort(vector<int> &vec)
        {
            const int MAX = get_max(vec);

            vector<vector<int>> buckets;
            vector<int> bucket(MAX + 1, 0);
            
			#pragma omp parallel
			{
                #pragma omp single
                {
                    for(int i = 0; i < omp_get_num_threads(); i++){
                        vector<int> b(MAX + 1, 0);
                        buckets.push_back(b);
                    }
                }

                #pragma omp for
                for (int i = 0; i < vec.size(); i++){
					buckets[omp_get_thread_num()][vec[i]]++;
				}

                #pragma omp critical
                {
                    for (int i = 0; i < buckets[omp_get_thread_num()].size(); i++){
					    bucket[i] += buckets[omp_get_thread_num()][i];
				    }
                }

                #pragma omp barrier

                #pragma omp single
                {
                    for (int i = 0, j = 0; i <= MAX; i++)
                        while (bucket[i])
                        {
                            vec[j++] = i; // add next sorted value
                            bucket[i]--;  // decrement the occurence of this value
                        }
                }
			}
        }
};

#endif
