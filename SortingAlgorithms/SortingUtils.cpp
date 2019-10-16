#include "SortingUtils.hpp"

std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

void print_vector(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";

    cout << endl;
}

void print_vector(const vector<int> *vec)
{
    for (int i = 0; i < vec->size(); i++)
        cout << vec->at(i) << " ";

    cout << endl;
}

bool is_sorted(const vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
        if (vec[i] > vec[i + 1]) // unsorted elements found
            return false;

    return true; // vector is sorted
}

bool is_sorted(const vector<int> *vec)
{
    for (int i = 0; i < vec->size() - 1; i++)
        if (vec->at(i) > vec->at(i + 1)) // unsorted elements found
            return false;

    return true; // vector is sorted
}

void fill_vector(vector<int> &vec, int from, int to)
{
    std::uniform_int_distribution<> dis(from, to);

    for (int i = 0; i < vec.capacity(); i++)
        vec.push_back(dis(gen));
}

void fill_vector(vector<int> *vec, int from, int to)
{
    std::uniform_int_distribution<> dis(from, to);

    for (int i = 0; i < vec->capacity(); i++)
        vec->push_back(dis(gen));
}