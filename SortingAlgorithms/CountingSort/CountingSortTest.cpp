#include <vector>
#include <iostream>

#include "CountingSort.hpp"
#include "Utils.hpp"

using namespace std;

int main(void)
{
    int size = 10000;
    vector<int> vec;

    vec.reserve(size);

    fill_vector(vec, 0, 10000);

    print_vector(vec);
    cout << endl;
    CountingSort cs;
    cs.sort(vec);
    print_vector(vec);
    cout << endl
         << "Vector sorted: " << is_sorted(vec) << endl;

    return 0;
}
