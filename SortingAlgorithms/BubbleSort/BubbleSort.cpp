#include "BubbleSort.hpp"

void BubbleSort::sort(vector<int> &vec)
{
    for (int n = 0; n < vec.size() - 1; n++)
        for (int k = 0; k < vec.size() - n - 1; k++)
            if (vec.at(k) > vec.at(k + 1))
                std::swap(vec[k], vec[k + 1]);
    
}