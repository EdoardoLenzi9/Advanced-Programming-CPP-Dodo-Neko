#include <iostream>

#include "SortingUtils.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_vector(vector<int> vec)
{
    using namespace std;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;
}

bool is_sorted(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] > vec[i + 1]) // we found an unsorted position
            return false;

    return true; // list is sorted
}