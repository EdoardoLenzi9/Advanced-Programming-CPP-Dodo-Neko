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
        /*
        int get_max(const vector<int> &vec)
        {
            int max = 0;

            #pragma omp parallel
            {
                #pragma omp for schedule(static, vec.size() / omp_get_num_threads() - 1)
                for (int i = 0; i < vec.size(); i++){
                    if (vec[i] > max)
                        max = vec[i];
                }

            }
            return max;
        }*/

        int get_max(const vector<int> &vec)
        {
            int max = 0;
            for (int i = 0; i < vec.size(); i++)
                if (vec[i] > max)
                    max = vec[i];

            return max;
        }

        /**
        * Sorts the statically created vector with the bucket sort algorithm
        */
        void sort(vector<int> &vec)
        {
            const int MAX = get_max(vec);
            vector<int> bucket(MAX + 1, 0);
            
			#pragma omp parallel
			{
                #pragma omp for
                for (int i = 0; i < vec.size(); i++){

                    #pragma omp atomic
					bucket[vec[i]]++;
				}

                #pragma omp barrier
            }


            int j = 0;
            for (int i = 0; i <= MAX; i++){
                for(int k = 0; k < bucket[i]; k++){
                    vec[j++] = i;
                }
            }
        }
};

#endif
