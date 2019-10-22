#include "QuickSort.hpp"
#include "../SortingUtils.hpp"

using namespace std;

int main(void)
{
    int size = 1000;
    vector<int> vec;

    vec.reserve(size);
    fill_vector(vec, 0, 100);

    cout << "Unsorted: ";
    print_vector(vec);
    cout << endl;

    QuickSort qs;
    qs.sort(vec);
    cout << "Sorted: ";
    print_vector(vec);
    cout << endl;
    
    return 0;
}