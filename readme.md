# Advanced CPP Programming - SEQUENTIAL ALGORITHMS IN C++

DEADLINE: OCTOBER 28

1. Implement in the C++ programming language the following algorithms:
    * Matrix multiplication;
    * Gaussian elimination algorithm for solving a linear system of equations assuming that 
    the pivot element cannot be zero: http://en.wikipedia.org/wiki/Gaussian_elimination;
    * Dijkstra's algorithm for computing the shortest path between nodes in a graph stored as 
    anmatrix:https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm;
    * Sieve of Eratosthenes for finding all prime numbers to a given limit: 
    https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes;
2. The following sorting algorithms:
    * Bubblesort:http://en.wikipedia.org/wiki/Bubble_sort;
    * Bucketsort:http://en.wikipedia.org/wiki/Bucket_sort;
    * Countingsort:http://en.wikipedia.org/wiki/Counting_sort;
    * Insertionsort:http://en.wikipedia.org/wiki/Insertion_sort;
    * Selectionsort:http://en.wikipedia.org/wiki/Selection_sort;
    * Quicksort:https://en.wikipedia.org/wiki/Quicksort.
3. Initialise the algorithms with uniformly distributed random numbers;
4. Choose for each algorithm one large problem size (i.e. array dimension) and execute it on your
system;
5. Use the GNU gprof profiler to measure the execution time of each algorithm;
6. Report and explain the results in a simple PDF file.


## Important Requirements:

1. Measure only the core execution time of each algorithm without random number generation,
array/matrix initialisation, and any I/Ooperations.
2. Declare the main array or matrix data structures as static global variables. Do not use
dynamic memory allocation using malloc.
3. Implement the algorithms as short (few lines) and as simple as possible, focused on the core
functionality (e.g. without safety checks, small optimisations, or redundant tests)


## The team

* Edoardo Lenzi, 11922660
* Neko, xxxxxxxx


## Further readings

* [C++ Tutorial](https://www.cprogramming.com/tutorial/c++-tutorial.html)
* [C++ Tutorial: Pointers](https://www.cprogramming.com/tutorial/lesson6.html)
* [Reference for the Vector Class](https://en.cppreference.com/w/cpp/container/vector)
* [CPP Vector Class Usage Examples](https://www.techiedelight.com/vector-of-vector-cpp/)


## Disclaimer

> The material contained in these project is restricted to students/professors of the "*Advanced C/C++ Programming*" 
course of the University of Klagenfurt.
>> It is prohibited any use other than that inherent to the course, and in particular is expressly prohibited its use 
for any commercial purposes and/or for profit.

License: [GPL-3](https://www.gnu.org/licenses/gpl-3.0.html)