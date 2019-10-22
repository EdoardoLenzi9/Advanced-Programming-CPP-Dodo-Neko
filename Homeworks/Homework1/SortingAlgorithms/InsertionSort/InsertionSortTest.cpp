#include "InsertionSort.hpp"
#include "../SortingUtils.hpp"

int main(void)
{
    int size = 100;
    vector<int> vec;
    vec.reserve(size);
    fill_vector(vec, 0, 100);
    print_vector(vec);
    cout << endl;

    InsertionSort is;
    is.sort(vec);
    print_vector(vec);
    cout << "Vector sorted: " << is_sorted(vec) << endl
         << endl;

    vector<int> *dyn_vec = new vector<int>();
    dyn_vec->reserve(size);
    fill_vector(dyn_vec, 0, 100);
    print_vector(dyn_vec);
    is.sort(*dyn_vec);
    print_vector(dyn_vec);
    cout << "Vector sorted: " << is_sorted(dyn_vec) << endl
         << endl;
}