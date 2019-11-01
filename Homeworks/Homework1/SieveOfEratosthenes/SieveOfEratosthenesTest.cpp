/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include "SieveOfEratosthenes.hpp"
#include <iostream>
#include <vector>


const int MAX_PRIME = 10000;


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
