#include "BucketSort.hpp"

void BucketSort::sort(vector<int> &vec)
{
    const int MAX = get_max(vec);

    // fill the bucket with (max + 1) zeros
    vector<int> buckets(MAX + 1, 0);

    for (int i = 0; i < vec.size(); i++)
        buckets[vec[i]]++; // counts the occurence of a number

    for (int i = 0, j = 0; i <= MAX; i++)
        while (buckets[i])
        {
            vec[j++] = i; // add next sorted value
            buckets[i]--; // decrement the occurence of this value
        }
}

void BucketSort::sort(vector<int> *vec)
{
    const int MAX = get_max(vec);

    // fill the bucket with (max + 1) zeros
    vector<int> buckets(MAX + 1, 0);

    for (int i = 0; i < vec->size(); i++)
        buckets[vec->at(i)]++; // counts the occurence of a number

    for (int i = 0, j = 0; i <= MAX; i++)
        while (buckets[i])
        {
            vec->at(j++) = i; // add next sorted value
            buckets[i]--; // decrement the occurence of this value
        }
}