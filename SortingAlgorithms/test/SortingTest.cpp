#include <iostream>
#include <vector>
#include <algorithm> // std::sort()
#include <chrono>    // execution time measurement

#include "Utils.hpp"
#include "../BubbleSort/BubbleSort.hpp"

const int TEST_ITERATION = 10;
const int SIZE = 1000;

vector<int> original;

// Prototypes
void test_bubble_sort(const vector<int> original);

int main(void)
{

    original.reserve(SIZE);
    fill_vector(original, 0, 1000);
    test_bubble_sort(original);

    return 0;
}

void test_bubble_sort(const vector<int> original)
{
    BubbleSort bubble_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    for (int i = 0; i < TEST_ITERATION; i++)
    {
        TimeVar t1 = time_now();
        bubble_sort.sort(algo_sorted);
        double current_time = duration(time_now() - t1);

        if (!are_equal(algo_sorted, std_sorted))
        {
            throw "Sorting Algorithm did not sort vector!";
            break; // in this case, stop the test
        }
        algo_sorted = original;
    }
}