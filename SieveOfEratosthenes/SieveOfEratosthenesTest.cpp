#include "SieveOfEratosthenes.hpp"
#include <iostream>

const int MAX_PRIME = 100;

int main(int argc, char const *argv[])
{
    SieveOfEratosthenes sieve;
    vector<int> primes = sieve.sieve(MAX_PRIME);

    std::cout << "Primes from 0 to " << MAX_PRIME << ": " << std::endl;
    for (int p : primes)
        std::cout << p << ", ";
    std::cout << std::endl;

    return 0;
}
