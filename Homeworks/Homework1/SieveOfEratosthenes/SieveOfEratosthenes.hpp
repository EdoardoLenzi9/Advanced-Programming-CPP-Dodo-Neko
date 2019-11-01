/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#ifndef SIEVE_HPP
#define SIEVE_HPP

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


#endif // SIEVE_HPP