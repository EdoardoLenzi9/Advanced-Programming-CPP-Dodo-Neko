#ifndef SIEVE_HPP_INCLUDED
#define SIEVE_HPP_INCLUDED

#include <vector>
#include <cmath>

using namespace std;

class SieveOfEratosthenes
{
public:
    /**
     * Finds all prime number up to the given integer
     * @param primesTo: Maximum integer to check
     * @return: A vector containing all prime numbers from 0 to primesTo
     */
    vector<int> sieve(int primesTo);

private:
    /**
     * A vector containing all primes found
     */
    vector<int> primes;
};
#endif