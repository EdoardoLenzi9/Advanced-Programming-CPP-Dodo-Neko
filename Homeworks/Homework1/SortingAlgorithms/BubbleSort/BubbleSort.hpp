#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <vector>
#include "../SortingInterface.hpp"
#include "../SortingUtils.hpp"

using namespace std;

class BubbleSort : public SortingInterface {
public:
    template <typename T>
    void sort(vector<T> &vec)
    {
        for (int n = 0; n < vec.size() - 1; n++)
            for (int k = 0; k < vec.size() - n - 1; k++)
                if (vec.at(k) > vec.at(k + 1))
                    std::swap(vec[k], vec[k + 1]);
    };

    template <typename T>
    void sort(vector<T> *vec)
    {
        for (int n = 0; n < vec->size(); n++)
            for (int k = 0; k < vec->size(); k++)
                if (vec->at(k) > vec->at(k + 1))
                    std::swap(&vec->at(k), &vec->at(k + 1));
    };
};

#endif