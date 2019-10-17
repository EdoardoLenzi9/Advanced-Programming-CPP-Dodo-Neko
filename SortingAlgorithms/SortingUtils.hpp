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

/**
 * Returns the max T value in a statically created vector.
 * 
 * @param vec a static vector, which is used to search the maximum value
 */
template <typename T>
T get_max(const vector<T> &vec)
{
    T max = 0;
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] > max)
            max = vec[i];

    return max;
}

/**
 * Returns the max T value in a dynamically created vector.
 * 
 * @param vec a dynamic vector, which is used to search the maximum value
 */
template <typename T>
T get_max(const vector<T> *vec)
{
    T max = 0;
    for (int i = 0; i < vec->size(); i++)
        if (vec->at(i) > max)
            max = vec->at(i);

    return max;
}
#endif