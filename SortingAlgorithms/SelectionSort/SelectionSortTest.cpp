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
    ssort.sort(dyn_vec);
    cout << "sorted vector:" << endl;
    print_vector(dyn_vec);
    cout << "Dynamic Vector sorted: " << is_sorted(dyn_vec) << endl;
    
    return 0;
}
