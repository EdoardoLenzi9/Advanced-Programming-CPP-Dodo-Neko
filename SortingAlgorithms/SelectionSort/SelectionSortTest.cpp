#include "SelectionSort.hpp"
#include "../SortingUtils.hpp"

int main(void)
{
    int size = 100;
    vector<int> vec;

    vec.reserve(size);

    for (int i = size; i > 0; i--)
        vec.push_back(i);

    print_vector(vec);
    SelectionSort ssort;
    ssort.sort(vec);
    print_vector(vec);
    cout << "Normal Vector sorted: " << is_sorted(vec) << endl;


    vector<int> *dyn_vec = new vector<int>();
    dyn_vec->reserve(size);
    fill_vector(dyn_vec, 0, 100);
    cout << "random vector:" << endl;
    print_vector(dyn_vec);
    // this is most likely dereferencing the pointer dyn_vec to a vector<int>, and passes that to sort().
    // this causes sort(vector<T> vec) to be called, not sort(vector<T> *vec). 
    // passing the actual pointer instead by calling ssort.sort(dyn_vec) causes a lot of different problems though.
    ssort.sort(*dyn_vec);
    cout << "sorted vector:" << endl;
    print_vector(dyn_vec);
    cout << "Dynamic Vector sorted: " << is_sorted(dyn_vec) << endl;
    
    return 0;
}
