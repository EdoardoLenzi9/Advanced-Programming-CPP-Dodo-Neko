#ifndef SORTING_UTILS_HPP
#define SORTING_UTILS_HPP

#include <vector>

using namespace std;


/**
 * Swaps the values in the memory addresses of given arguments
 */
void swap(int *a, int *b);

/**
 * Prints the given array on the console
 */
void print_vector(vector<int> vec);

/**
 * Checks if given vector is sorted
 * 
 * @return true, if sorted, else false
 */
bool is_sorted(vector<int> vec);

#endif