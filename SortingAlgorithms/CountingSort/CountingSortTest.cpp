#include <vector>
#include <iostream>

#include "CountingSort.hpp"
#include "Utils.hpp"

using namespace std;

int main(void)
{
    vector<int> vec;
    vec.reserve(1000);
    fill_vector(vec, 0, 1000);
    CountingSort cs;
    cs.sort(vec);
    print_vector(vec);
    cout << "Vector sorted: " << is_sorted(vec) << endl;
}