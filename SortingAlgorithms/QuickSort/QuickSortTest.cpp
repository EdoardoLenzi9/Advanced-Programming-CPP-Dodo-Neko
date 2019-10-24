#include <vector>
#include <iostream>

#include "QuickSort.hpp"
#include "SortingUtils.hpp"

using namespace std;

int main(void)
{
    int size = 1000;
    vector<double> vec;

    vec.reserve(size);
    fill_vector(vec, 0, 100);

    cout << "Unsorted: ";
    print_vector(vec);
    cout << endl;

    QuickSort qs;
    qs.sort(vec);
    cout << "Sorted: ";
    print_vector(vec);
    cout << "Vector is sorted: " << is_sorted(vec) << endl;

    return 0;
}