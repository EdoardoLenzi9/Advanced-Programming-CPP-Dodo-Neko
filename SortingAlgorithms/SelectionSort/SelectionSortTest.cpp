#include <vector>
#include <iostream>

#include "SelectionSort.hpp"
#include "SortingUtils.hpp"

int main(void)
{
    using namespace std;

    int size = 1000;
    vector<double> vec;

    vec.reserve(size);

    fill_vector(vec, 0, 1000);

    print_vector(vec);
    SelectionSort ssort;
    ssort.sort(vec);
    print_vector(vec);
    cout << "Normal Vector sorted: " << is_sorted(vec) << endl;
    
    return 0;
}
