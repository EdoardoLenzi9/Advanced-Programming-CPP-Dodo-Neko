#ifndef SORTING_UTILS_HPP
#define SORTING_UTILS_HPP

#include <vector>
#include <iostream>
#include <random>

using namespace std;

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

/**
 * @brief  prints the given vector on the console
 * @note   pass by reference
 * @param  &vec: 
 * @retval None
 */
template <typename T>
void print_vector(const vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;
}

/**
 * @brief  checks if given vector is sorted
 * @note   pass by reference
 * @param  &vec: 
 * @retval true if sorted, else false
 */
template <typename T>
bool is_sorted(const vector<T> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1]) // unsorted elements found
            return false;

    return true; // vector is sorted
}

/**
 * @brief  Fills a given statically created vector with randomized values (uniformly distributed)
 * @note   uses real numbers as random values, which get pruned in case of integer values
 * @param  &vec: vector to be filled (pass by reference)
 * @param  from: start range of random values
 * @param  to: end range of random values
 * @retval None
 */
template <typename T>
void fill_vector(vector<T> &vec, int from, int to)
{
    std::uniform_real_distribution<> dis(from, to);

    for (int i = 0; i < vec.capacity(); i++)
        vec.push_back(dis(gen));
}

/**
 * @brief  returns the max T value in a (statically created) vector.
 * @note   pass by reference
 * @param  &vec: 
 * @retval the maximum value in vector
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

#endif // SORTING_UTILS_HPP