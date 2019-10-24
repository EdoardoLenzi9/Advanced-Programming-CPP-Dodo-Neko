#include "InsertionSort.hpp"
#include "SortingUtils.hpp"

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
}