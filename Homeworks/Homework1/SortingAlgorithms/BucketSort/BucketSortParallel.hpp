/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    
    @version 1.0 24/01/20 
    @license WTFPL v2  
**/


#ifndef BUCKETSORTPAR_HPP
#define BUCKETSORTPAR_HPP

#include <vector>
#include "Utils.hpp"
#include <omp.h>

using namespace std;


class BucketSortParallel {

    public:

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
        }


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

            // not parallelizable
            int j = 0;
            for (int i = 0; i <= MAX; i++){
                for(int k = 0; k < bucket[i]; k++){
                    vec[j++] = i;
                }
            }
        }
};

#endif
