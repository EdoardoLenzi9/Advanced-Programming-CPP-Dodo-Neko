#include <vector>
#include <iostream>

#include "QuickSort.hpp"
#include "Utils.hpp"

using namespace std;

int main(void)
{
    int size = 10000;
    vector<double> vec;

    vec.reserve(size);

    fill_vector(vec, 0, 10000);

    print_vector(vec);
    cout << endl;
    QuickSort qs;
    qs.sort(vec);
    print_vector(vec);
    cout << endl
         << "Vector is sorted: " << is_sorted(vec) << endl;

    return 0;
}
