#include <vector>
#include <iostream>

#include "InsertionSort.hpp"
#include "Utils.hpp"

int main(void)
{
    int size = 10000;
    vector<int> vec;

    vec.reserve(size);
    
    fill_vector(vec, 0, 10000);

    print_vector(vec);
    cout << endl;
    InsertionSort is;
    is.sort(vec);
    print_vector(vec);
    cout << "Vector sorted: " << is_sorted(vec) << endl
         << endl;

    return 0;
}
