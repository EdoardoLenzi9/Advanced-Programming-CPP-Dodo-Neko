#include <vector>

#include "SortingUtils.hpp"
#include "BubbleSort.hpp"

int main(void)
{
    int size = 100;
    vector<int> vec;

    vec.reserve(size);

    fill_vector(vec, 0, 1000);

    print_vector(vec);
    BubbleSort bs;
    bs.sort(vec);
    print_vector(vec);
    cout << endl
         << "Vector is sorted: " << is_sorted(vec) << endl;

    return 0;
}