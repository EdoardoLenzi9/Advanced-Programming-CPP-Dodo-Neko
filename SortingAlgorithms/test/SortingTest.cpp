#include <iostream>
#include <vector>
#include <algorithm> // std::sort()
#include <chrono>    // execution time measurement
#include <limits>    // used for double max value
#include <string>
#include <exception>

#include "Utils.hpp"
#include "TimingUtils.hpp"
#include "../BubbleSort/BubbleSort.hpp"
#include "../BucketSort/BucketSort.hpp"
#include "../InsertionSort/InsertionSort.hpp"
#include "../QuickSort/QuickSort.hpp"
#include "../SelectionSort/SelectionSort.hpp"

const int VECTOR_SIZE = 1000;
/**
 * @brief  minimum random number in vector
 * @note   
 * @retval None
 */
const int MIN_RAND = 0;
/**
 * @brief  maximum random number in vector
 * @note   
 * @retval None
 */
const int MAX_RAND = 5000;

/**
 * @brief  static vector, which is required for the assignment
 * @note   gets randomized and is used for sorting test
 * @retval None
 */
static vector<int> original;

struct SortingException : public exception
{
    const char *what() const throw()
    {
        return "Unsorted Vector Exception";
    }
};

/***************************************************************************************************************************************
 * Prototypes
 * 
 ***************************************************************************************************************************************/

/**
 * @brief  tests the bubble sort algorithm with given vector
 * @note   
 * @param  original: vector used to test bubble sort
 * @param  REPETITIONS: times of repetitions of the test (more is better for good average value)
 * @retval None
 */
void test_bubble_sort(const vector<int> original, const int REPETITIONS);

/**
 * @brief  tests the bucket sort algorithm with given vector
 * @note   
 * @param  original: vector used to test bucket sort
 * @param  REPETITIONS: times of repetitions of the test (more is better for good average value)
 * @retval None
 */
void test_bucket_sort(const vector<int> original, const int REPETITIONS);

/**
 * @brief  tests the insertion sort algorithm with given vector
 * @note   
 * @param  original: vector used to test insertion sort
 * @param  REPETITIONS: times of repetitions of the test (more is better for good average value)
 * @retval None
 */
void test_insertion_sort(const vector<int> original, const int REPETITIONS);

/**
 * @brief  tests the quick sort algorithm with given vector
 * @note   
 * @param  original: vector used to test quick sort
 * @param  REPETITIONS: times of repetitions of the test (more is better for good average value)
 * @retval None
 */
void test_quick_sort(const vector<int> original, const int REPETITIONS);

/**
 * @brief  tests the selection sort algorithm with given vector
 * @note   
 * @param  original: vector used to test selection sort
 * @param  REPETITIONS: times of repetitions of the test (more is better for good average value)
 * @retval None
 */
void test_selection_sort(const vector<int> original, const int REPETITIONS);

int main(void)
{
    // create original vector and fill it with random values
    original.reserve(VECTOR_SIZE);
    fill_vector(original, MIN_RAND, MAX_RAND);

    TimeVar start_t = time_now();

    test_bubble_sort(original, MEDIUM_BENCHMARK_SIZE);
    test_bucket_sort(original, MEDIUM_BENCHMARK_SIZE);
    test_insertion_sort(original, MEDIUM_BENCHMARK_SIZE);
    test_quick_sort(original, MEDIUM_BENCHMARK_SIZE);
    test_selection_sort(original, MEDIUM_BENCHMARK_SIZE);

    double duration_time = duration(time_now() - start_t);
    cout << "Overall time for completion: " << duration_time << " microseconds." << endl;

    return 0;
}

/***************************************************************************************************************************************
 * Source
 * 
 ***************************************************************************************************************************************/

void test_bubble_sort(const vector<int> original, const int REPETITIONS)
{
    cout << "Starting Bubblesort tests:" << endl;

    BubbleSort bubble_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    TimeUnits units;
    units.iterations = REPETITIONS;

    for (int i = 0; i < REPETITIONS; i++)
    {
        // TIME MEASUREMENT
        TimeVar start_t = time_now();
        bubble_sort.sort(algo_sorted);
        double duration_time = duration(time_now() - start_t);
        update_time_units(units, duration_time);

        if (!are_equal(algo_sorted, std_sorted))
            throw SortingException();

        algo_sorted = original;
    }
    print_units(units, "\tBubble Sort -");
    cout << endl;
}

void test_bucket_sort(const vector<int> original, const int REPETITIONS)
{
    cout << "Starting Bucketsort tests:" << endl;

    BucketSort bucket_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    TimeUnits units;
    units.iterations = REPETITIONS;

    for (int i = 0; i < REPETITIONS; i++)
    {
        // TIME MEASUREMENT
        TimeVar start_t = time_now();
        bucket_sort.sort(algo_sorted);
        double duration_time = duration(time_now() - start_t);
        update_time_units(units, duration_time);

        if (!are_equal(algo_sorted, std_sorted))
            throw SortingException();

        algo_sorted = original;
    }
    print_units(units, "\tBucket Sort -");
    cout << endl;
}

void test_insertion_sort(const vector<int> original, const int REPETITIONS)
{
    cout << "Starting Insertionsort tests:" << endl;

    InsertionSort insertion_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    TimeUnits units;
    units.iterations = REPETITIONS;

    for (int i = 0; i < REPETITIONS; i++)
    {
        // TIME MEASUREMENT
        TimeVar start_t = time_now();
        insertion_sort.sort(algo_sorted);
        double duration_time = duration(time_now() - start_t);
        update_time_units(units, duration_time);

        if (!are_equal(algo_sorted, std_sorted))
            throw SortingException();

        algo_sorted = original;
    }
    print_units(units, "\tInsertion Sort -");
    cout << endl;
}

void test_quick_sort(const vector<int> original, const int REPETITIONS)
{
    cout << "Starting Quicksort tests:" << endl;

    QuickSort quick_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    TimeUnits units;
    units.iterations = REPETITIONS;

    for (int i = 0; i < REPETITIONS; i++)
    {
        // TIME MEASUREMENT
        TimeVar t1 = time_now();
        quick_sort.sort(algo_sorted);
        double duration_time = duration(time_now() - t1);
        update_time_units(units, duration_time);

        if (!are_equal(algo_sorted, std_sorted))
        {
            throw SortingException();
            cout << "Deine mutta oida" << endl;
            break; // in this case, stop the test, not sure if reached
        }
        algo_sorted = original;
    }
    print_units(units, "\tQuick Sort -");
    cout << endl;
}

void test_selection_sort(const vector<int> original, const int REPETITIONS)
{
    cout << "Starting Selectionsort tests:" << endl;

    SelectionSort selection_sort;
    vector<int> algo_sorted(original), std_sorted(original);

    std::sort(std_sorted.begin(), std_sorted.end());

    TimeUnits units;
    units.iterations = REPETITIONS;

    for (int i = 0; i < REPETITIONS; i++)
    {
        // TIME MEASUREMENT
        TimeVar t1 = time_now();
        selection_sort.sort(algo_sorted);
        double duration_time = duration(time_now() - t1);
        update_time_units(units, duration_time);

        if (!are_equal(algo_sorted, std_sorted))
            throw SortingException();
        
        algo_sorted = original;
    }
    print_units(units, "\tSelection Sort -");
    cout << endl;
}