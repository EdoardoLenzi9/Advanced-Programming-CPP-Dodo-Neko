# Advanced CPP Programming - Homeworks and Milestones

In this repo we will expose our homeworks and our projects for the course "Advanced C/C++ Programming"


## The team

* Edoardo Lenzi, 11922660
* Neko, xxxxxxxx
* Walter Jensch, xxxxxxxx
* Christian Bauer, xxxxxxxx


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