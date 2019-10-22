#include "BubbleSort.hpp"
#include "../SortingUtils.hpp"

int main(void)
{
    int size = 100;
    vector<int> vec;

    vec.reserve(size);

    for (int i = size; i > 0; i--)
        vec.push_back(i);

    print_vector(vec);
    BubbleSort bs;
    bs.sort(vec);
    print_vector(vec);

    vector<int> *dyn_vec = new vector<int>();
    dyn_vec->reserve(size);
    fill_vector(dyn_vec, 0, 100);
    print_vector(dyn_vec);
    bs.sort(*dyn_vec);
    print_vector(dyn_vec);
    cout << "Vector sorted: " << is_sorted(dyn_vec) << endl;
    
    return 0;
}