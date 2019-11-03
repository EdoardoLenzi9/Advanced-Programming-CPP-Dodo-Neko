#include <vector>
#include <iostream>

#include "SelectionSort.hpp"
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
    SelectionSort ssort;
    ssort.sort(vec);
    print_vector(vec);
    cout << endl
         << "Normal Vector sorted: " << is_sorted(vec) << endl;
    
    return 0;
}
