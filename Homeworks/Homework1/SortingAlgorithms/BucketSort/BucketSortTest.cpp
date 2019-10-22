#include "BucketSort.hpp"
#include "../SortingUtils.hpp"

int main(void) {
    vector<int> vec;
    vec.reserve(100);
    fill_vector(vec, 0, 100);
    print_vector(vec);
    cout << endl;
    BucketSort bs;
    bs.sort(vec);
    print_vector(vec);
    cout << "Vector sorted: " << is_sorted(vec) << endl << endl;


    vector<int> * dyn_vec = new vector<int>();
    dyn_vec->reserve(100);
    fill_vector(dyn_vec, 0, 100);
    print_vector(dyn_vec);
    cout << endl;
    bs.sort(dyn_vec);
    print_vector(dyn_vec);
    cout << is_sorted(dyn_vec) << endl;
    return 0;
}