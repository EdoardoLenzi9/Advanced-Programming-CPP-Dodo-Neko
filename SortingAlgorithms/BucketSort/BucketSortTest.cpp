#include <vector>
#include <iostream>

#include "BucketSort.hpp"
#include "Utils.hpp"

int main(void)
{

    using namespace std;

    vector<int> vec;
    vec.reserve(100);
    fill_vector(vec, 0, 100);
    print_vector(vec);
    cout << endl;
    BucketSort bs;
    bs.sort(vec);
    print_vector(vec);
    cout << "Vector sorted: " << is_sorted(vec) << endl
         << endl;

    return 0;
}