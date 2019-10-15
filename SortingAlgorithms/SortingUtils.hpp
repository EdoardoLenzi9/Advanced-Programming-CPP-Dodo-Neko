#ifndef SORTING_UTILS_HPP
#define SORTING_UTILS_HPP

#include <vector>
#include <iostream>
#include <random>

using namespace std;


/**
 * Prints the given vector on the console
 * 
 * Function for statically created vectors
 */
void print_vector(const vector<int> &vec);

/**
 * Prints the given vector on the console
 * 
 * Function for dynamically created vectors
 */
void print_vector(const vector<int> *vec);

/**
 * Checks if given vector is sorted
 * 
 * Function for statically created vectors
 * 
 * @return true, if sorted, else false
 */
bool is_sorted(const vector<int> &vec);

/**
 * Checks if given vector is sorted
 * 
 * Function for dynamically created vectors
 * 
 * @return true, if sorted, else false
 */
bool is_sorted(const vector<int> *vec);

/**
 * Fills a given statically created vector with randomized values (uniformly distributed)
 * 
 * @param vec   - vector to be filled
 * @param from  - start range of random values
 * @param to    - end range of random values
 */
void fill_vector(vector<int> &vec, int from, int to);

/**
 * Fills a given statically created vector with randomized values (uniformly distributed)
 * 
 * @param vec   - vector to be filled
 * @param from  - start range of random values
 * @param to    - end range of random values
 */
void fill_vector(vector<int> *vec, int from, int to);

#endif