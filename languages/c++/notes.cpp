#include <iostream>
#include <string>
// remark .. C++ prefers camel case. i will be using snake case for many things though :p


// WELCOME TO MY C++ NOTES
// hello, welcome to my C++ notes
// in these notes, you will learn how to write C++ code
// we will start with the basics, and eventually move on to more advanced topics
// these notes assume you are ALREADY FAMILIAR WITH C and have a decent understanding of programming
// if you are not familiar with C, read my C notes first.
// if you are fairly new to programming, you will likely want to use this notes in addition with other resoruces to fill in any gaps.

// below, we have a bunch of function prototypes that each represent a topic
// you can jump to the function definition for each prototype to see a specific topic
// to run the code for a specific topic, just call it in the main() function by replacing the function under "// RUN"

// BASIC CONCEPTS
int what_is_cpp();
int compiling_cpp();
int cmake();
int stdin_stdout();

// STANDARD LIBRARY
int stl();
int string_handling();
int stream_io();
int containers_algorithms();
int iterators();

// OBJECT ORIENTED PROGRAMMING
int oop();
int constructors_destructors();
int inheritance_polymorphism();
int virtual_functions();
int templates();
int operator_overloading();

// LANGUAGE FEATURES
int namespaces();
int scope_resolution_operator();
int references();
int function_overloading();
int exception_handling();
int default_arguments();
int lambda_functions();
int range_based_for();

// MEMORY AND RESOURCES
int smart_pointers();
int raii();
int move_semantics();
int memory_model();

// MODERN C++ FEATURES
int auto_keyword();
int nullptr_keyword();
int uniform_initialization();
int constexprr();

// ADVANCED TOPICS
int multithreading();
int perfect_forwarding();
int variadic_templates();


int main() {
    // RUN
    what_is_cpp();
}

int what_is_cpp() {
    // C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language
    // but we ask, why? why do we need C++ when we already have C?

    // why C++ instead of C?
    // C++ is an extension of C, which means that C++ is a superset of C
    // all valid C programs are also valid C++ programs
    // C++ is a more modern language that includes features like oop, the C++ standard template library (STL), and namespaces (just to name a few).
    // these features add a layer of abstraction that makes C++ more convenient for high-level programming

    // okay nice, we understand that C++ offers more features than C.
    // lets take a look at some of the features that C++ offers.
    // each of these features will have its own topic, we will just be taking a look at an overview

    // C++ vs C
    
    // classes and objects
    // C++ supports object-oriented programming (OOP) through classes and objects. for example:
    class Position {

        private:
            int x, y;
            
        public:
            Position(int initial_x, int initial_y) : x(initial_x), y(initial_y) {} // constructor
            void move(int dx, int dy) {
                x += dx;
                y += dy;
            }
            void print_position() {
                std::cout << "Position: (" << x << ", " << y << ")" << std::endl; 
                // dont worry if this doesn't make sense to you right now.
                // its just print(f"Position: ({x}, {y})"). u will learn later.
            }
    };

    Position pos(0, 0);
    pos.print_position();
    pos.move(1, 2);
    pos.print_position();
    pos.move(2, -1);
    pos.print_position();


    // STL
    // STL stands for standard template library
    // there is actually some confusion surrounding what STL exactly means. it could mean one of two things
        // 1.) original meaning: consists of the containers, iterators, and algorithms from C++ standard library (excluding string)
        // 2.) entire C++ standard library

    // the exact meaning varies, but here is what is definitely part of the STL:
    // (remark, if we uncomment these include statements, we will get errors. we would want these written outside of the function)
    // #include <vector>
    // #include <list>
    // #include <map>
    // #include <set>
    // #include <deque>
    // #include <queue>
    // #include <stack>

    // #include <algorithm>
    // sort, find, count, etc.

    // #include <iterator>
    // begin(), end(), etc.

    // #include <functional>
    // less<>, greater<>, etc.

    // people often say the C++ standard library is a superset of STL, but i am not sure how accurate this is!
    // the main takeaway regarding the STL, is that it provides common datastructures and algorithms (much like the Java Collections Framework)
    // this is a big difference from C where we have to make everything ourselves.


    // namespaces
    // C++ also makes use of namespaces, which are encapsulations of blocks of code which protect against name collisions.
    // for example, suppose you have functions or variables defined somewhere (for example inside a library).
    // now a potential issue is that if somewhere else those some functions/variables are redefined again.
    // in order for the compiler to know which variable/function to refer to, we define the different functions/variables inside a namespace, and refer to it from there.
    // this is similiar to python packages, for example when we import np and reference np.array()

    // one of the most common namespaces is std. 
    // we use :: (known as the scope resolution operator)
    std::cout << "Hello World!" << std::endl;
    // here we used the :: operator to specify that we want to use cout from the std namespace. this is a very light introduction to namespaces.
    // for now, do not worry if u are confused! we will dive into all of this in more depth in the following sections.

    return 0;
}


int compiling_cpp() {


    return 0;
}

int cmake() {


    return 0;
}


int stdin_stdout() {


    return 0;
}

int stl() {

    // recall the C standard library.
    // even though we have a header called <stdlib.h>, the entire C standard library consists of much more headers.
    // here are some of the headers that make up the C standard library:
        // stdlib.h
        // stdio.h
        // string.h
        // math.h
        // time.h
        // ctype.h
        // limits.h
        // float.h
        // stdarg.h
        // assert.h
        // stddef.h
        // errno.h
        // signal.h
    // and so on.
    
    // <as a refresher, we will go over what <stdlib.h> in C contains.
        // you don't need to read this.

        // memory stuff:
        // malloc() - allocate a block of memory
        // calloc() - allocate and clear a block of memory
        // realloc() - resize an allocated memory block
        // free() - free an allocated block of memory
        
        // process control stuff:
        // exit() - terminates the calling process
        // abort() - causes asn abnormal program termination
        // system() - executes a shell command

        // conversion functions:
        // atoi() - convert string to int
        // atol - str to long
        // atof -- string to float
        // strtol() - str to long again. has more features
        // strtoll() - str to long long

        // more utilities
        // rand() - generates a pseudo-random number
        // srand() - seeds the pseudo-random number generator
        // qsort() - sorts an array
        // bsearch() - searches an array using binary search
        // abs(), labs(), llabs() - absolute value for int, long, long long
        // div(), ldiv(), lldiv() - quotient and remainder of int division for int, long, long long

    // note that we are only including the headers at the top of our code.
    // the actual implementation of these headers, of the C standard library, is provided by the compiler you use.
    // the compiler, like gcc, is responsible for providing an implementation of the C standard library.

    // gcc specifically provides the GNU C Library (glibc) implementation.

    // the concept is exactly the same in C++.
    // we include headers that are either .h or .hpp files like so:
    // #include <vector>
    // notice that we did not include a '.h'

    


    return 0;
}


int references() {



    return 0;
}