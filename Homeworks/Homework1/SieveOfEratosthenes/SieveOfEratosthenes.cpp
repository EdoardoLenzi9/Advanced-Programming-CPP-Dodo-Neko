/**
    @author Edoardo Lenzi
    @author Patrick Tschuchnig
    @author Christian Bauer
    @author Walter Jensch
    
    @version 1.0 01/11/19 
    @license WTFPL v2  
**/


#include "SieveOfEratosthenes.hpp"


vector<int> SieveOfEratosthenes::sieve(int primesTo)
{
    vector<bool> values(primesTo, true); // store whether the current number (index) is actually a prime

    for (int i = 2; i <= sqrt(primesTo); i++)
        if(values[i])
            for (int k = pow(i, 2); k <= primesTo; k+=i)
                values[k] = false; // number k is not a prime

    // any remaining index that is true is actually a prime
    for (int i = 2; i < values.size(); i++)
        if (values[i])
            primes.push_back(i);

    return primes;
}