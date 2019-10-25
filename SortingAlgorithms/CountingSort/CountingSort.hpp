#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <vector>

#include "Utils.hpp"

using namespace std;

class CountingSort
{
public:
    void sort(vector<int> &vec)
    {
        vector<int> output(vec.size() + 1, 0);
        const int MAX = get_max(vec);
        vector<int> count(MAX + 1, 0); // create count vector (max + 1 elements)

        for (int i = 1; i <= vec.size(); i++)
            count[vec[i]]++;

        for (int i = 1; i <= MAX; i++)
            count[i] += count[i - 1]; // find cumulative frequency

        for (int i = vec.size(); i >= 1; i--)
        {
            output[count[vec[i]]] = vec[i]; // wtf
            count[vec[i]]--;                // decrease count for the same numbers
        }

        for (int i = 0; i < vec.size(); i++)
            vec[i] = output[i];
        }
};

#endif