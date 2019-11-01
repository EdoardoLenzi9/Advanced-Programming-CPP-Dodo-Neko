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
* Patrick Tschuchnig, xxxxxxxx


## Further readings

* [C++ Tutorial](https://www.cprogramming.com/tutorial/c++-tutorial.html)
* [C++ Tutorial: Pointers](https://www.cprogramming.com/tutorial/lesson6.html)
* [Reference for the Vector Class](https://en.cppreference.com/w/cpp/container/vector)
* [CPP Vector Class Usage Examples](https://www.techiedelight.com/vector-of-vector-cpp/)


## Best practices

* CamelCase for classes (`MyClass`) and files (`MyMatrix.cpp`)
* lowerCamelCase for functions and variables (`myFunction`, `myVariable`)
* CAPITAL for constants (`CONSTANT`)


* File extension is `cpp` and `hpp` in order to distinguish from C code
* Use `nullprt` instead of `null` for pointers

* Use always `{}` also for one line blocks
* Avoid hungarian notations cause it isn't a standard
* Avoid more than ~80 chars per row (in order to be able to split the screen 
and read two files at the same time)
* Use namespaces
* Prefer preincrement (`++i` better than `i++`)
* every `cpp` file must have an associated `hpp` file
    * every header file must have its `define` guard in order to prevent multiple inclusions (`<PROJECT>_<PATH>_<FILE>_H_`)
    ```
    #ifndef FOO_BAR_BAZ_H_
    #define FOO_BAR_BAZ_H_
    ...
    #endif  // FOO_BAR_BAZ_H_
    ```
    * avoid **forward declarations** where possible (declaration of a type without an associated definition)
    * *Include headers in the following order: Related header, C system headers, C++ standard library headers, other libraries' headers, your project's headers.*
    * with few exceptions, always place code into a namespace
        * don't use `using`
        * don't use inline namespace 
        * inside a namespace u can avoid references to the namespace itself, 
        outside u have to but this prevents global names conflicts

        ```c++
        namespace outer {
            inline namespace inner {
                void foo();
            }  // namespace inner
        }  // namespace outer
        ```

```c++
// In the .h file
namespace mynamespace {

// All declarations are within the namespace scope.
// Notice the lack of indentation.
class MyClass {
 public:
  ...
  void Foo();
};

}  // namespace mynamespace


// In the .cc file
namespace mynamespace {

// Definition of functions is within scope of the namespace.
void MyClass::Foo() {
  ...
}

}  // namespace mynamespace
```

* *When definitions in a .cc file do not need to be referenced outside that file, place them in an unnamed namespace or declare them static.*
*Do not use either of these constructs in .h files.* `namespace { ... }`

**Sources**:
* [C++ Coding Standards](https://gist.github.com/lefticus/10191322)
* [Google styleguide](https://google.github.io/styleguide/cppguide.html)
* [Split class declaration](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)


## Disclaimer

> The material contained in these project is restricted to students/professors of the "*Advanced C/C++ Programming*" 
course of the University of Klagenfurt.
>> It is prohibited any use other than that inherent to the course, and in particular is expressly prohibited its use 
for any commercial purposes and/or for profit.

License: [GPL-3](https://www.gnu.org/licenses/gpl-3.0.html)