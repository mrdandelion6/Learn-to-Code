#include <iostream>
#include <unistd.h> 
#include <cstring>
#include <string>
#include <limits>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <cmath>
// remark .. C++ prefers camel case. i will be using snake case for many things though :p

// WELCOME TO MY C++ NOTES
// hello, welcome to my C++ notes
// in these notes, you will learn how to write C++ code
// we will start with the basics, and eventually move on to more advanced topics
// these notes assume you are ALREADY FAMILIAR WITH C and have a decent understanding of programming
// if you are not familiar with C, read my C notes first.
// if you are fairly new to programming, you will likely want to use this notes in addition with other resources to fill in any gaps.

// below, we have a bunch of function prototypes that each represent a topic
// you can jump to the function definition for each prototype to see a specific topic
// note that these topics are not always in exact order, e.g) things from oop section may precede topics in memory and resources
// to run the code for a specific topic, just call it in the main() function by replacing the function under "// RUN"

// INTRO
int what_is_cpp();
int data_types();
int objects();

// COMPILING
int compiling_cpp();
int compilation_flags();
int cmake();

// BASIC PRINTING
int stdin_stdout();
int no_flush();

// STANDARD LIBRARY
int stl();
int string_handling();
int stl_containers();
int vectors();
int maps();
int sets();
int iterators();

// LANGUAGE FEATURES
int references();
int aggregates();
int range_based_for();
int namespaces();
int scope_resolution_operator();
int function_overloading();
int exception_handling();
int default_arguments();
int lambda_functions();

// MEMORY AND RESOURCES
int free_and_malloc_review();
int new_delete_operators();
int smart_pointers();
int raii();
int move_semantics();
int memory_model();

// OBJECT ORIENTED PROGRAMMING
int oop();
int classes();
int structs();
int initializer_list();
int constructors_destructors();
int inheritance_polymorphism();
int virtual_functions();
int templates();
int operator_overloading();

// MODERN C++ FEATURES
int auto_keyword();
int nullptr_keyword();
int uniform_initialization();
int const_expr();

// STREAM I/O
int stream_io();
int stream_classes();
int stream_objects();
int file_streams();
int string_streams();

// ADVANCED TOPICS
int multithreading();
int perfect_forwarding();
int variadic_templates();


int main() {
    // RUN
    references();
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
    // note that we align the private, public, and protected keywords with the class keyword.

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
    // the main takeaway regarding the STL, is that it provides common data structures and algorithms (much like the Java Collections Framework)
    // this is a big difference from C where we have to make everything ourselves.

    // namespaces
    // C++ also makes use of namespaces, which are encapsulations of blocks of code which protect against name collisions.
    // for example, suppose you have functions or variables defined somewhere (for example inside a library).
    // now a potential issue is that if somewhere else those some functions/variables are redefined again.
    // in order for the compiler to know which variable/function to refer to, we define the different functions/variables inside a namespace, and refer to it from there.
    // this is similar to python packages, for example when we import np and reference np.array()

    // one of the most common namespaces is std. 
    // we use :: (known as the scope resolution operator)
    std::cout << "Hello World!" << std::endl;
    // here we used the :: operator to specify that we want to use cout from the std namespace. this is a very light introduction to namespaces.
    // for now, do not worry if u are confused! we will dive into all of this in more depth in the following sections.

    return 0;
}

int data_types() {
    // there are two kinds of data types in C: primitive and non-primitive

    // PRIMITIVE DATA TYPES
    // these are also known as fundamental datatypes
    // primitive types are built into the language
    // primitive types hold single values

    // integer type
    int a;                // usually 4 bytes
    short b;              // usually 2 bytes
    long c;               // usually 4 or 8 bytes
    long long d;          // usually 8 bytes

    // float types
    float e;              // usually 4 bytes
    double f;             // usually 8 bytes
    long double g;        // usually 8 or 16 bytes

    // character types
    char h;               // 1 byte

    // boolean
    bool i;               // 1 byte

    // void
    // void j;               // no bytes. note we cannot even declare this

    // NON PRIMITIVE DATA TYPES
    // non-primitive types can can hold multiple values and/or have methods associated
    // non-primitive types are often based on primitive types

    // arrays
    int arr[5];
    // same as in C

    // pointers
    int* xp;
    // 4 bytes on 32-bit systems
    // 8 bytes on 64-bit systems

    // strings
    std::string s1 = "hello world";

    // structures (same as C)
    struct Student {
        int roll;
        char grade;
        float marks;
    };

    // classes
    // similar to structures but with data hiding
    class Person {
    public:
        static void shout() {std::cout << "AHHH" << std::endl;}
    };

    return 0;
}

int objects() {
    // what are objects?
    // in C++, objects can typically refer to two things
        // 1.) objects
        // 2.) class objects

    // oftentimes when we refer to objects, we may be thinking of some instantiation of a class.
    // however in C++, every data type isn't a class!
    // primitive data types like ints, floats, chars are not a class.
    // non-primitive data types like strings, pointers, and structs are also not classes.
    // however these are also referred to as objects.

    // if we are thinking of objects in the context of object-oriented-programming and classes, then it would be wrong to say that int x; is an object.

    // CLASS OBJECTS
    class Person {
    private:
        char* name;
    public:
        Person(const char* person_name) {
            name = new char[strlen(person_name) + 1];
            strcpy(name, person_name);
        }
        static void shout() {std::cout << "AHHH" << std::endl;}
    };

    Person* person = new Person("jeff");
    // we say person is an object of the class Person

    // GENERAL OBJECTS
    // a more general definition of an object is as follows.
    // an object is a region of space in memory that has:
        // 1.) a type
        // 2.) a size
        // 3.) a lifetime 

    // so anything from structs, to ints, to classes, they are all considered objects.
    int x = 4;
    std::string str1 = "Hello"; // string class
    int arr[30];
    std::vector<int> vec = {1, 2, 3}; // vector class

    // VARIABLE vs OBJECT
    // to be even more clear, the variable 'person' itself is a variable.
    // a variable is an "identifier" that refers to an object.
    // the object itself is the actual data--the actual memory taken.
    // for example, consider an array of Person*
    Person* arr2[] = {new Person("jill"), new Person("jack")};

    // in this case, arr contains two objects.
    // however there exists no variables that identify these objects.

    return 0;
}

int compiling_cpp() {
    // compiling C++ is very similar to compiling C. 
    // C++ has its own compiler, just like C.
    // recall that C uses the GNU C compiler (gcc).
    // similarly, C++ uses g++

    // the compilation process for C++ is much more complex than for C.
    // C is just a procedural programming language, so its compilation at the file level mostly consists 
    // of simply turning C source code into machine code. 
    // whereas C++ is a multi-paradigm language that supports many high level things like oops, templates
    // and exceptions. 
    // this leads to a much more complex compilation process for C++.

    // the compilation process for C++ itself is also very similar to C.
    // recall in C:
    // 1. preprocessing
        // the C preprocessor cleans up the source code (#include and #define statements)
    // 2. compilation
        // the C compiler turns the source code for each .c file into assembly code (.s)
    // 3. assembly
        // the C assembler turns the assembly code into object code. assembly code is human-readable (like x86 or ARM), whereas the object code is direct binary (machine code)
    // 4. linking
        // the C linker takes all the object code (.o files) and links them together into a single binary executable

    // for C++ the process is very similar:
    // 1. preprocessing
        // the C++ preprocessor cleans up source code (#include and #define) 
        // also cleans up macros that can handle templates (more on templates later)
        // the output source file typically has an (.i) extension
    // 2. compilation
        // the C++ compiler also compiles source code into assembly code (.s)
        // however, this process is much more complex for C++ as mentioned before.
        // there is much more complexity (OOP, templates, etc.)
    // 3. assembly
        // the C assembler takes the assembly code for each file and turns it into object code (.o or .obj)
    // 4. linking
        // and finally, just like C, the object code is linked together at the end to form one executable.
        // the final executable doesn't need to have a specific extension but it may have .out (unix) or .exe (windows), or it may have none

    // one final question for this section: why do we have assembly code and object code?
    // you may be wondering what the point is of having assembly code and object code. why not just directly make the executable?

    // why assembly code?
    // the reason we want assembly code is because it creates architecture specific code. 
    // for example, many computers use x86 or ARM architecture, but the actual binary for each computer may be different.
    // having assembly code allows for a portable low level code that can quickly be translated to the proper binary (object) code for each computer.

    // why object code?
    // the reason we would want object code rather than just directly going to an executable is because of many reasons.
    // 1. modular compilation (individual recompilation):
        // we can have a binary object file for each separate source file, which allows us to recompile and reassemble only one binary object at a time.
        // this means if we have one just one c++ source file out of a hundred that are all linked together, we do not need to recompile binaries for the whole program.
        // we only would need to recompile the object code for the single source file and relink all the object files together.
    // 2. linking external and standard libraries:
        // external binaries such as those for the C++ standard library can be linked together if we have an object code stage.
        // the C++ standard library headers do not have source files, but rather object files for their implementation.
        // (makes sense, why would u want source code, you would have to recompile it each time and libraries can be big).
        // hence it becomes seamless to join libraries together with your code if you have a stage where you link together all the object files
    // 3. improved compiler optimizations
        // having an object file for each separate source file allows the compiler to make smarter optimizations as the binaries are separate.
        // further optimizations are made upon linking.

    return 0;
}

int compilation_flags() {
    // now lets finally take a look at how compilation commands look like in C++
    // compilation in C++ looks identical to C for the most part.

    // recall in C we have:
        // gcc -o notes notes.c 
    // where -o is a flag for the output executable name (notes)

    // in C++ we have
        // g++ -o notes notes.c 

    // the only difference is that c++ has some specific flags:
        // -fno-exceptions: disable exception handling
        // -fno-rtti: disable runtime type info
        // -fvisibility: control symbol visibility

    // even debugging with gdb is the same. just add a -g

    return 0;
}

int cmake() {
    // recall for C we have Makefiles for generating our builds.
    // CMake takes things further one level.

    // CMake stands for cross platform make. it's a tool that generates build files for us.
    // you write a file called CMakeLists.txt that generates your build files (like makefiles) that end up building your program. 

    // the main advantage is that the same CMakeLists.txt can generate:
        // makefiles on linux
        // visual studio project files on windows
        // xcode project ffiles on macOS
        // other build systems like Ninja

    // that's why cmake is called cross platform make!

    // to learn how to properly write CMakeLists.txt files, see CMakeLists.txt inside ./example-project/
    // to use the CMakeLists.txt that you have typed up, you will want to first create a folder named "build":
        // mkdir build
        // cd build
        // cmake ..
    // this is assuming the CMakeLists.txt file is outside the build file (in ..)

    //then inside the build directory, (we already cd'd here), you would just run make:
        // make

    // the above example is if we use make.
    // here is an example using Ninja:
        // mkdir build
        // cd build
        // cmake -G "Ninja" .. 
        // ninja 

    // note that we specify that we are using Ninja to build our files with the -G "Ninja" 
    // also note a generic way to execute build (whether its make or ninja), is to use:
        // cmake --build .

    // this is the common directory structure:
    //     myproject/
        // ├── CMakeLists.txt
        // ├── src/
        // │   └── main.cpp
        // └── build/          # all generated files stay here
        //     └── ...

    // note that you do not add the build folder to your version control.

    return 0;
}

int stdin_stdout() {
    // recall IO streams from C
    // in C++ we have the same thing.
    // for standard input (stdin), c++ takes from the console by default. i.e, waits for keyboard input into the console.
    // for stdout, c++ writes to the console by default.

    // we can use printf() in C++ just like we did in C
    printf("starting stdin_stdout section!\n");
    // but we will focus on using << and working with cout and cin directly (keep reading)

    // using stdout
    // in c++, stdout is handled using the cout stream (cout stands for character output / console output):
    std::cout << "(1) Enter a number: ";

    // note that cout is part of the std namespace, so we use the scope resolution operator ::
    // we will learn more about the scope resolution operator in a later section.. but for now just know that we use it to specify where we want to use cout from.
    // its kind of like when you have a class and you access a method or attribute from that class using . in python, but it's a bit different.

    // using stdin
    // in c++, stdin is handled using the cin stream (cin stands for character input / console input):
    int number;
    std::cin >> number;
    // the above code reads an integer from the console and stores it in the variable number.

    std::cout << "(1) You entered: " << number << std::endl;

    // INSERTION and EXTRACTION OPERATORS:
    // note that we have been using the << and >> operators.
    // these are called the insertion and extraction operators respectively.

    // the insertion operator << is used to insert data into the stream.
    // the stream is the object that handles the input/output, which could be cout or cin, or even a file stream.

    // the extraction operator >> is used to extract data from the stream.
    // for example, when we do std::cin >> number, we are extracting data from the cin stream and storing it in the variable number.

    // you might remember >> and << being bit shift operators in C.
    // in C++, these operators are overloaded to work with streams.
    // that means they can be used for both bit shifting and for streams depending on the context.
    // for example, here is bit shifting:
    int x = 1;
    x = x << 1; // x is now 2
    std::cout << "x is: " << x << std::endl; // prints 2

    // endl
    // note that we have been using std::endl.
    // std::endl is a manipulator that inserts a newline character into the stream and FLUSHES the output buffer.
    // cout can be flushed manually using std::flush, but std::endl is more convenient as it also inserts a newline character.
    // when the buffer is flushed, it means that the data in the buffer is written to the output device (console, file, etc.)
    // notice that when we did "(1) Enter a number: ", this still got printed even though we did not use std::endl.
    // this is because we still did flush the buffer by reading from cin.
    // in other words, here are the following things that flushes cout:
        // 1. using std::endl
        // 2. using std::flush
        // 3. reading from cin
        // 4. newline character '\n'
        // 5. program termination

    // cin behaviour
    // note that cin stops reading input when it encounters whitespace character (space, newline, tab)
    // so if we did the following:
    std::cout << "(2) Enter a word: ";
    std::string sentence; // we make use of the string class from the C++ standard library. more on this later.
    std::cin >> sentence;

    // and we entered "hello world" into the console, sentence would only contain "hello"
    // this is because cin stops reading input when it encounters a space character.
    std::cout << "(2) You entered: " << sentence << std::endl;

    // and to make things worse, if we entered "hello world" into the console, 
    // the next time we use cin, it will read "world" and not wait for input.
    // this is because cin leaves "world\n" in the input buffer,
    // and the next time we use cin, it reads from the buffer and ends when it encounters the newline character.

    // enter "hello world" to the above cin and see what happens when we try to read another string.
    std::cout << "(3) Enter a word: ";
    std::cin >> sentence;
    std::cout << "(3) You entered: " << sentence << std::endl;

    // you should see the following being printed:
    // (2) Enter a word: hello world
    // (2) You entered: hello
    // (3) Enter a word: (3) You entered: world

    // note that we did not even get a newline after "Enter a word: " because cin left it in the buffer.
    // you might have expected this instead:
        // (2) Enter a word: hello world
        // (2) You entered: hello
        // (3) Enter a word: 
        // (3) You entered: world
    // but we did not get that because cin left the newline character in the buffer.
    // this might be even more confusing but the reason for this is as follows:
    // the third prompt (3) and its response are printing so quickly (because no actual user input is needed) that they appear on the same line.
    // the program isn't actually waiting for input at the second prompt, so there's no time for you to see a cursor on a new line.
    // this is because cin is reading from the buffer and not waiting for input.

    // to get around this issue, we can "flush" the input buffer.
    // we can do this by using the ignore() function from the cin stream.

    // ignore() function:
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // this is how we flush the buffer. we need the <limits> header for this.
    // ill explain how this works:
        // std::cin.ignore() takes two arguments
        // 1.) how many characters to ignore. in this case we are ignoring the maximum number of characters that can be stored in a stream.
        // 2.) the delimiter character. in this case, we are ignoring until we reach the newline character.
        // this means we are ignoring everything in the buffer until we reach the newline character, which effectively flushes it.

    // now we can read a sentence properly:
    std::cout << "(4) Enter a word: ";
    std::getline(std::cin, sentence);
    std::cout << "(4) You entered: " << sentence << std::endl;

    // this time, do the following:
    // Enter a sentence: hello
    // (2) You entered: hello
    // Enter a sentence: hello world
    // (3) You entered: hello
    // Enter a sentence: supercalifragilisticexpialidocious
    // (4) You entered: supercalifragilisticexpialidocious

    // at prompt (3), we entered "hello world" and it only read "hello".
    // then we flushed "world\n" from the buffer.
    // at prompt (4), we entered "supercalifragilisticexpialidocious" and it read the whole thing.

    // in order to take in a whole sentence, you would want to use std::getline
    // std::getline reads an entire line of input, including whitespace characters.
    // it reads this input from stdin and stores it in a string.
    std::cout << "(5) Enter a sentence again: ";
    std::getline(std::cin, sentence);
    std::cout << "(5) You entered: " << sentence << std::endl;

    // this should work as expected and not leave anything in the buffer:
    std::cout << "(6) Enter a sentence for the last time: ";
    std::cin >> sentence;
    std::cout << "(6) You entered: " << sentence << std::endl;

    return 0;
}

int no_flush() {
    // in this function you see how different things flush the buffer.

    // newline flushes the buffer
    std::cout << "Hello newline\n";
    usleep(3000000);

    // endl flushes the buffer
    std::cout << "Hello endl" << std::endl;
    usleep(3000000);

    // cin flushes the buffer
    std::cout << "cin time\n";
    int number;
    std::cout << "Hello cin";
    std::cin >> number;
    usleep(3000000);  

    // there is nothing to flush the buffer. only flushes after program termination
    std::cout << "Hello..";
    usleep(3000000);
    // after the sleep is done, program terminates and flushes the buffer.

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
    // #include "example.hpp"
    // for headers part of the C++ standard library, we do not include a .h or .hpp.
    // for instance:
        // #include <vector>
    // note that this is only for C++ standard library headers! 
    
    // STL vs C++ standard library
    // now the main topic of this section: the STL
    // STL stands for standard template library, which consists of certain iterators and data structures in C++
    // the STL is part of the C++ standard library, i.e; the STL is a subset of the C++ standard library
    // (at least as far as i know, but there seems to be debate around this topic so do your own research).

    // STL specifically refers to the components originally designed by Alexander Stepanov which 
    // focus on containers, iterators, algorithms, and function objects.

    // STL headers include:
    // containers
    // #include <vector>
    // #include <list>
    // #include <deque>
    // #include <queue>
    // #include <stack>
    // #include <set>
    // #include <map>

    // algorithms
    // #include <algorithm>

    // iterators
    // #include <iterator>

    // function objects (functors)
    // #include <functional>  

    // meanwhile, here are some examples of headers part of C++ standard library but not in STL:
    // I/O streams
    // #include <iostream>
    // #include <fstream>
    // #include <sstream>

    // string handling
    // #include <string>

    // exception handling
    // #include <exception>
    // #include <stdexcept>

    // C++ time
    // #include <chrono>

    // threading
    // #include <thread>
    // #include <mutex>
    // #include <condition_variable>

    // smart pointers and memory
    // #include <memory>

    // all C compatibility headers
    // #include <cstdio>
    // #include <cstring>
    // #include <cmath>
    // etc...

    // regular expressions
    // #include <regex>

    // random numbers
    // #include <random>

    // type support
    // #include <typeinfo>
    // #include <type_traits>

    // the main idea of the STL is that it provides several useful data structures and algorithms for C++.
    // this is a big upgrade from C in terms of high-level usage.
    // remember in C, we do not even have dynamic arrays and must implement everything ourselves.
    // with C++ we don't have to dedicate extra files to reinvent the wheel. simply just use the already implemented DSA from STL.

    return 0;
}

int stl_containers() {
    // in the following sections we will learn about the containers below:
    
    // SEQUENCE CONTAINERS
        // vector: dynamic array, continuous memory
        std::vector<int> vec; // needs #include <vector>

        // array: fixed sized array, continuous memory
        int arr[] = {1, 2, 3};

        // deque: double ended queue, fast insertion/removal at both ends
        std::deque<int> deq;

        // list: doubly linked list, fast insertion/removal anywhere
        std::list<int> lst; // needs #include <list>

        // forward list: a singly linked lsit , only have next pointers
        std::forward_list<int> flst; // needs #include <forward_list>

    // ASSOCIATIVE CONTAINERS
    // ORDERED
        // map: unique keys with values
        // set: unique keys only
        // multimap: duplicate keys with values
        // multiset: duplicate keys
    // UNORDERED
        // unordered_map: unique keys with values
        // unordered_set: unique keys only
        // unordered_multimap: duplicate keys with values
        // unordered_multiset: duplicate keys

    // don't worry too much about each of the containers right now, we will investigate them each in greater depth.

    // CONTAINERS ARE CLASSES
    // all these containers are actually classes.
    // typically we uppercase (camelcase) classes in C++ (and most other languages) but of course this is not required.
    // for classes from the standard library like vector, string, etc, we do not have CamelCase and instead have snake_case

    // standard library classes: snake case
    // user defined classes: camel case

    return 0;
}

int vectors() {
    // make sure to include vector at the top
    // #include <vector>

    // CREATING VECTORS:
    // empty vector
    std::vector<int> vec;

    // vector of 5 elements initialized to zero
    std::vector<int> vec2(5);

    // vector of 5 elements all initialized to 10
    std::vector<int> vec3(5, 10);

    // initialize vector with manual values
    std::vector<int> vec4 = {1, 2, 3, 4};

    // ADDING ELEMENTS
    vec.push_back(1);
    // add to the end of the vector
    // this is an amortized O(1) operation
    // O(n) when the vector needs to be resized
    // note that the vector gets resized by a factor of 2 each time (doubles in length)

    vec.emplace_back(2);
    // construct element in place at the end
    // specifically we are CONSTRUCTING the element, not copying it
    // this is pointless for types like integers, but useful for things like strings

    // for example,
    std::vector<std::string> str_vec = {"hello"};
    str_vec.emplace_back("world");

    // the above is faster than the following:
    str_vec.push_back("sup");
    // this does two things:
        // 1. creates a temporary string with "hello"
        // 2. moves/copies that string into the vector

    // whereas emplace_back() constructs it directly into the vector's memory, so one step

    // for integers, it's still one step for emplace_back():
    vec.push_back(69);
    // this does not create a temporary variable
    
    // so you might wonder, when do we want to use push_back() instead then?
    // if the object already exists, then push_back will be more efficient than emplace_back or at least equally as much.

    std::string existing_string = "Yoskies";
    str_vec.push_back(existing_string);

    return 0;
}

int references() {
    // a reference in C++ is essentially an alias for an already existing variable
    // if x was an existing variable, and we made y a reference of x, then y and x hold the value of the same data in memory.
    // that is, having a reference variable does not take up more memory.
    // so if y is a reference of x, &x == &y
    // this idea is not to be confused with pointers. 

    // POINTERS vs REFERENCES
    // a pointer stores the value of the memory address of a variable...
    // whereas a reference stores the same value of an already existing variable, and has the same address in memory.

    // USAGE
    // you might already be familiar with references in python
    // when we do x = [1, 2, 3] and y = x, y becomes a reference of x.
    // we see this in action when we do (x is y) or if we change y[0] = 69, then x[0] also becomes 69

    // we can achieve this same affect in C++, except we must explicitly declare the type as a reference.
    std::vector<int> x = {1, 2, 3};
    std::vector<int>& y = x;

    // now y is a reference to x
    // lets also make 'z', without adding &
    std::vector<int> z = x;

    // now let's change value in x
    x[0] = 69;

    // check y
    std::cout << "y[0] is " << y[0] << std::endl;
    // prints 69

    // check z
    std::cout << "z[0] is " << z[0] << std::endl;
    // prints 1

    // by doing std::vector<int> z = x; , we made a full copy of x. we can see that these exist in different locations in memory.

    std::cout << "address of x is: " << &x << std::endl;
    std::cout << "address of y is: " << &y << std::endl;
    std::cout << "address of z is: " << &z << std::endl; 

    // we see that x and y share the same address whereas z shares a different one:
    // address of x is: 0x7fff7bf00da0
    // address of y is: 0x7fff7bf00da0
    // address of z is: 0x7fff7bf00dc0

    // REFERENCES CLARIFICATION
    // so far we have bene saying y is a reference of x.
    // but it is more accurate to say that x and y are variables that reference the same object.
    // the object of course is the array itself which resides in memory.

    // REFERENCES AS PARAMETERS
    // recall when we wanted to modify some arguments in another function in C,
    // we passed their address. for C++ we can also do the same thing , or we
    // could just use references. using a reference type as the parameter
    // avoids the need to derefence pointer variables.

    // consider this lambda function that takes reference type parameter.
    auto mutate_int = [](int &a) { a += 1; };

    int dada = 69;
    mutate_int(dada);
    std::cout << "dada is now: " << dada << std::endl;
    // prints 70
    // note that we passed in dada which is of type int into the parameter for
    // `a` which is of type &int. this is how references as parameters work.

    return 0;
}

int aggregates() {
    // in C++ an aggregate is a type that allows its members to be initialized directly with curly brace initialization.
    // this is known as aggregate initialization.
    // think of it as a simple type that is essentially just a collection of its members.

    // a struct or class in C++ (more on classes later) is an aggregate if it has all of these properties:
        // 1. no user-declared or inherited constructors
        // 2. no private or protected non-static data members
        // 3. no virtual functions of virtual base classes
        // 4. no default member initializers

    // don't worry if you don't know about virtual functions and deffault member initializers. we will cover these topics later.
    // if you don't know about constructors or access specifiers (private, protected, public), then you can see the respective functions: constructors_destructors() and classes().

    // STRUCTS
    // here's an example of an aggregate struct:
    struct Point {
        int x;
        int y;
        void print_pair() { std::cout << '(' << x << ',' << y << ')' << std::endl;}
    };
    Point p = {1, 2}; // aggregate initialization works
    p.print_pair();

    // another
    struct Point2 {
    public:
        int x;
        int y;
        void print_pair() { std::cout << '(' << x << ',' << y << ')' << std::endl;}
    };
    Point2 p2 = {1, 2}; // aggregate initialization works

    // here's a non aggregate struct:
    struct Point3 {
    public:
        int x;
    private:
        int y;
    };

    // Point3 p3 = {1, 2}; 
    // uncommenting this gives an error.

    // this doesn't work either:
    // Point3 p3 = {1}; 

    // can only do this:
    Point3 p3;
    p3.x = 1;
    // or we could also just make a constructor inside Point3 and use that.

    // CLASSES
    // here is an example of an aggregate class:
    class Player {
        public:
            int health;
            int mana;
            int stamina;

            bool is_low_hp () { return health < 25; }
    };
    Player p1 = {100, 70, 200}; // aggregate initialization works!

    // here is an example of a non-aggregate class:
    class Wizard {
        int health;
        public:
            int mana;
    };
    // uncommenting this throws an error since we have a private class member (health)
    // Wizard wiz = {100}; 

    // classes' default access specifier for members is private, and for structs it's public.
    // more on this in the classes() section.

    // here is another example of a non-aggregate class:
    class Knight {
        public:
            int armor;
            int health;
            int strength;
            Knight(int a, int h, int s) : armor(a), health(h), strength(s) {}
    };

    // this code works.. but it's not aggregate initialization!
    Knight kit = {69, 69, 69};
    // even though it is identical to aggregate initialization, 
    // it's actually calling the constructor we defined with the brace-init-list being used as a list of args.
    // this feature is part of C++'s uniform initialization syntax (aka brace initialization) 

    // so you might ask, "if they look the same, what's the difference?"
    // answer:
        // 1. aggregates are simple data than the compiler can optimize more aggressively.
        //    the compiler knows exactly how they are laid out in memory.
        // 2. with aggregates, we automatically get member-wise operations for free without having to write any special code.
        //    i.e, we don't write any constructors and the compiler can generate optimal copying, moving, and comparison operations.
        // 3. when we add a constructor, we're telling C++ that "we want control over how my object is initialized".
        //    this is inherently different from just saying, "this is just a bundle of data"--exactly what an aggregate is.

    // here are some further examples:
    class Aggregate {
    public:
        int x;
        int y;
    };
    class NonAggregate {
        public:
            int x;
            int y;
            NonAggregate(int a, int b) : x(a), y(b) {}
    };
    // these behave differently:
    Aggregate a1;           // x and y are default-initialized (could be garbage)
    // NonAggregate n1;       // won't compile - no default constructor

    Aggregate a2 = {1};    // sets x=1, y is zero-initialized
    // NonAggregate n2 = {1}; // won't compile - constructor needs 2 args

    return 0;
}

int free_and_malloc_review() {
    // recall in C we would use malloc and free. we also can in C++.
    int* ptr1 = (int*)malloc(sizeof(int));
    free(ptr1);

    // but lets review how the program knows how much to free.
    // when we first do malloc(sizeof(int)) , the runtime system tracks
    // allocation sizes. when we call free() , the runtime system is looked
    // up to determine how much to free.

    char* ptr = (char*)malloc(100);  // you specify 100 bytes
    int* nums = (int*)malloc(10 * sizeof(int));  // you specify 40 bytes

    // internally, most implementations do something like storing the size of
    // array just befor your data like this:

    // [SIZE_INFO][YOUR_DATA_STARTS_HERE]
    //            ^-- your pointer points here

    free(ptr);   // free() looks backward to find the stored size (100)
    free(nums);  // free() looks backward to find the stored size (40)

    // a common mistake is doing this:
    char* ptr2 = (char*)malloc(100);
    ptr2 += 50;  // move pointer to middle of allocation.
    free(ptr2);  // CRASH! free() can't find the size info because ptr no longer
    //             points to start.

    return 0;
}

int new_delete_operators() {
    // in C++ we can also use the 'new' and 'delete' keyword for memory management.

    // we can also use 'new' now:
    int* ptr2 = new int;
    delete ptr2;

    // MALLOC vs NEW
    // new does two things:
        // 1. allocates memory onto heap (like malloc)
        // 2. calls the constructor of the object (particuarly useful for classes)

    // it's just like in Java when use 'new'
    // it is particularly useful for when we have classes

    class Dog {
    private:
        char* name;
        int age;

    public:
        // this is a constructor
        Dog(const char* dog_name, int dog_age) {
            name = new char[strlen(dog_name) + 1];
            strcpy(name, dog_name);
            age = dog_age;
        }

        // this is a destructor
        ~Dog() {
            delete[] name;
        }

        void getName() {
            std::cout << "my name is " << name << std::endl;
        }
    };

    // to see more about oop, jump to the oop function below in the notes
    // now lets see how new and delete work with classes:

    Dog* doggy = new Dog("saad", 20);
    // this allocates all the memory for the Dog class
    // the memory allocated is calculated by how many 'member variables' we have
    // that is:
        // char* name (8 bytes)
        // int age (4 bytes)
    // if the compiler also adds padding to the Dog class for allignment then
    // that will also be allocated. in other words , the compiler allocates
    // sizof(Dog) bytes... note the sizeof() operator accounts for padding.
    // after allocation , compiler also calls the constructor.

    // if we didnt use new, it would just allocate the memory on the stack:
    Dog doggy2 = Dog("saadu", 200);
    // this object only lives on the stack frame and not the heap

    // now we can call the destructor with delete:
    delete doggy;
    // this does the following:
        // 1.) call the destructor
        // 2.) frees memory like calling free()
    // remember , since everything is statically typed in C / C++ , the
    // compiler knows how much size each type takes. hence calling free() on a
    // Dog pointer (doggy) frees sizeof(Dog) bytes. same thing for delete.

    // now doggy is a dangling pointer, so we should set it to nullptr:
    doggy = nullptr;

    // NEW WITHOUT NEW
    // the other way to do it would be like this:
    doggy = (Dog*)malloc(sizeof(Dog));
    Dog temp = Dog("shazaza", 69);
    memcpy(doggy, &temp, sizeof(Dog));
    doggy->getName();
    // prints shazaza
    // however this is very bad. memcpy() copies the pointers from temp to
    // doggy. so temp.name and doggy->name both point to the same memory.

    // DELETE WITHOUT DELETE
    doggy->~Dog();
    free(doggy);
    doggy = nullptr;

    // we also use delete[] instead of delete when working on arrays
    int* ptr = new int(1);
    delete ptr;

    int* arr = new int[10];
    delete[] arr;

    // using delete when you should be using delete[] and vice versa can lead to undefined behavior.
    // if we used delete on arr, it could only dealloc the first element
    // if we used delete[] on ptr, it could dealloc more than it should

    // WHEN TO USE MALLOC
    // you might think that its pointless to use new for pointers to data with no constructors like this:
    int* int_ptr = new int(5);
    // and you would be half right.
    // it has no practical difference between using a malloc call:
    int* int_ptr2 = (int*)malloc(sizeof(int));

    // integers have no constructors so they both do the same thing in effect.
    // the main difference is that using new is a lot cleaner.

    // the main scenarios in which we need malloc() are when:
        // 1.) interfacing with C code
        // 2.) need to use realloc() calls 
        // 3.) when implementing very custom memory allocators and doing low level memory management

    // at application level C++, you will rarely use malloc().
    // in fact, both new and malloc() are less preferred than something like smart pointers.

    return 0;
}

int oop() {
    // one of the main upgrades of C over C++ is the that it allows for object oriented programming.
    // object oriented programming allows for classes, which will be the discussed in the next section

    // with object oriented programming we have:

    // 1. BASIC CLASS/OBJECT FEATURES
        // structs with oop capabilities
        // member functions (methods)
        // data members (fields)
        // access specifiers 
        // constructors
        // destructors
        // `this` pointer
        // static members

    // 2. INHERITANCE FEATURES
        // single inheritance
        // multiple inheritance
        // virtual functions
        // pure virtual functions (abstract methods)
        // abstract classes and interfaces
        // virtual destructors
        // override and final specifiers
        // base class access specifiers

    // 3. ENCAPSULATION FEATURES
        // getters and setters
        // friend functions and classes
        // nested classes

    // 4. POLYMORPHISM FEATURES
        // runtime polymorphism
        // compile time polymorphism
        // operator overloading
        // virtual function tables

    // 5. TEMPLATES & GENERIC PROGRAMMING
        // class templates
        // function templates
        // template specialization
        // variadic templates

    // 6. OTHER FEATURES
        // const member functions
        // object composition
        // RAII (resource acquisition is initialization)
        // member initializer lists
        // default and delete functions
        // rule of three/five


        // in the coming sections we will delve into all of these topics
    return 0;
}

int classes() {
    // in this section we explore the fundamentals of classes
        // what are classes
        // class members
        // member functions
        // access specifiers

    // WHAT ARE CLASSES ?
    // classes are encapsulation of data.
    // they encapsulate two things:
        // member variables (infomartion)
        // member functions (methods)

    // these are member functions which we will delve into soon
    // here is a basic example of a class

    class Student {
    private:
        char* name;
        int age;

    protected:
        int money = 0;

    public:
        // constructor (more on these later)
        Student(const char* student_name, int student_age) {
            name = new char[strlen(student_name) + 1];   // this allocates memory
        }
        void moneyUp(int m) {
            money += m;
        }
    };

    // syntax remarks:
    // note that that we need to add ; to the end of the class definition
    // also note that private, protected, and public (access specifiers) are aligned with the class keyword. more on access specifiers soon.

    // CLASS MEMBERS
    // we refer to the components of a class--the variables it stores and functions it has--as class members.
    // so variables are class members, often called: data members, member variables, or fields
    // and class functions are also class members, often called: methods or member functions

    // ACCESS SPECIFIERS
    // access specifiers are keywords that determine the visibility of class members.
    // there are 3 access specifiers: private, protected, and public:

    // private:
        // only accessible within the scope of the class itself
    // protected:
        // accessible within the scope of the class itself and also any derived (children) classes
    // public:
        // accessible from any scope the object is visible

    // if we dont declare an access specifier, we use the "default access specifier".
    // for classes the default access specifier is private
    // for structs the default access specifier is public

    struct cool_struct {
        // no access specifier 
        int x;
        char y;

        // access specifier
    private:
        int z;
    public:
        // constructor for struct
        cool_struct(int ex, char why, int zee) {x = ex; y = why; z = zee;}
    };
    // you might not be familiar with using oop tools on structs like access specifiers and constructors, but dont worry for now! (we will cover this in the next section)

    // now we see that we can still access the field x even though we gave it no access specifier.
    cool_struct structo = cool_struct(4, 'a', 1); // construct locally
    std::cout << "structo.x is " << structo.x << std::endl;
    // we are able to access structo.x by default

    // now lets see the default access for a class
    class Dog {
        char* name; // default access
    public:
        Dog(const char* n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }
        void getName() { std::cout << name << std::endl; };
        ~Dog() {
            delete[] name;
        }
    };

    Dog* saadu = new Dog("saadu");
    saadu->getName(); // prints "saadu"
    // saadu->name;
    // if we uncomment the above it gives us an error as the member is not accessible. code wont compile

    return 0;
}

int structs() {
    // we have oop features in structs.
    // we can use access specifiers and create member functions:

    struct Point {
    private:
        int x, y;
    public:
        // constructor
        Point(int x_val, int y_val) {
            x = x_val;
            y = y_val;
        }

        // no destructor needed as we do not have any allocations to clean up

        // member function
        double l2_norm() {
            return sqrt(x*x + y*y);
        }
    };

    // note that we made a constructor inside the struct, the Point() function member.
    Point* p = new Point(10, 18);
    std::cout << "l2 norm is: " << p->l2_norm() << std::endl; 
    delete p; // cleanup

    // structs also support:
        // 1. inheritance from classes or other structs
        // 2. virtual functions for polymorphism
    // and more stuff. we don't know about these yet so we will not demonstrate them currently. read inheritance and virtual functions section to see.

    // CLASSES vs STRUCTS
    // clearly structs seem to have nearly everything classes do. 
    // so we ask: what is the difference between the two? why are classes needed?
    // well.. they're actually not! there is not any technical benefit of using classes rather than structs.
    // structs can do everything classes can. 
    // the only differences are as follows:
        // default access specifier for structs is public and for classes it's private
        // default inheritance for structs is public and for classes it's private (more on this later)

    // other than that, structs can mimic classes entirely the same.
    // there is no technical advantage in C++ to also having classes.
    // however, using classes has a semantic meaning to it.

    // WHY USE CLASSES INSTEAD OF STRUCTS ?
    // it comes down to philosophy and what programmers typically expect.
    // for complex data types with many features, components, and interactions with other data: use classes
    // for simpler data types where you just need a container to store some information: use structs

    // you can think of it like this:
        // use structs when you would want to use JS objects {}
        // use structs when you want to just a container for some data

    // so the point is, even though structs can be tailored to fully mimic classes, they can also be very simple like this:

    struct point2 {
        int x;
        int y;
    };

    // structs can always mimic classes, but classes cannot always mimic structs.

    return 0;
}

int initializer_list() {
    // before we get into the different kinds of constructors and destructors, we will go over some unique C++ syntax for initializing class members.

    // consider the following class
    class Dog {
    private:
        char* name;
        int age;
    public:
        Dog(const char* n, int a) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            age = a;
        }
        ~Dog() {
            delete[] name;
        }
    };

    // for initializing the name, we allocate some memory for it then copy over the name parameter (n).
    // we can make this constructor much more simple and easier to read by using "initializer list" syntax:

    class Cat {
    private:
        char* name;
        int age;
    public:
        Cat(const char* n, int a) : name(new char[strlen(n) +1 ]), age(a) {
            strcpy(name, n);
        }
        ~Cat() { delete[] name; }
    };

    // the syntax uses a colon : after the constructor params, followed by comma separated initializations,
    // i.e age(a), name(...).

    // each member is initialized in the format: member_name(initial_value)
    // these initializations happen before the constructor body executes, which then calls strcpy(name, n)

    // to make things even better, we can do the following:
    class Tiger {
    private:
        char* name;
        int age;
    public:
        Tiger(const char* n, int a) : name(copy_name(n)), age(a) {}
        ~Tiger() { delete[] name; }

        char* copy_name(const char* n) {
            char* copy = new char[strlen(n) + 1];
            strcpy(copy, n);
            return copy;
        }
    };
    //  this way our copy logic is separated from constructor and it is more readable
    // we could also just use the std::string class instead

    class Bear {
    private:
        std::string name;
        int age;
    public:
        Bear(std::string n, int a) : name(n), age(a) {}
    };
    // std::string constructor automatically handles copying the string so we don't need to do it ourselves.
    // and we have no need for a destructor because string handles its own cleanup automatically.
    // for notes on how std::string works, see the string_handling() function.

    // UNDER THE HOOD
    // what exactly does member_name(initial_value) do?
    // it invokes initialization rules that vary based on the type!

    // INITIALIZATION FOR FUNDAMENTAL PRIMITIVES
    // for something like age(a), it simply does age = a
    // the value is written directly into the memory location for that member

    // INITIALIZATION OF POINTERS
    // for something like name(n) where n is of type char* it is similar to the initialization for fundamental types.
    // we just have name = n. if we have name(new char[10]), then of course we allocate that memory first and give the address to name directly

    // INITIALIZATION FOR CLASS TYPES
    // for something like name(n) where n is type std::string it is more complex.
    // name(n) calls the appropriate constructor for the class, in this case for std::string.
    // the string's constructor is used to initialize the member directly.

    // the most important part to pay attention to is for classes.
    // always remember that member(value) will invoke the constructor of the value class if value is a class type.

    // INITIALIZATION ORDER
    class Example {
        int a;
        int b;
    public:
        // Even though b is listed first, a will be initialized first
        // because that's the declaration order in the class
        Example() : b(42), a(b) { }  // DANGEROUS! 'a' gets undefined value
    };

    return 0;
}

int constructors_destructors() {
    // we have already seen constructors and destructors being used a few times now.
    // we will delve a bit deeper into them now.

    // DIFFERENT TYPES OF CONSTRUCTORS
    // suppose you want to create an "empty" object of a class with no parameters passed in.
    // or suppose you want to create an object with parameters.
    // or suppose you want to copy the data from one object into another, that is; have them reference the same data
    // for this we need different kinds of constructs:
        // 1.) default constructor: no parameters
        // 2.) parameterized constructor: takes params
        // 3.) copy constructor: creates a copy from an existing object
        // 4.) move constructor: transfers "ownership" (only in c++)

    // example class
    class Dog {
    private:
        char* name;
        int age;
        char* breed;
        int weight;
    public:
        Dog() {

        }
    };

    return 0;
}

int lambda_functions() {
    // lambda functions allow for anonymous function objects.
    // this is practical for short functions you wouldn't want to name and just make them in line.
    // they also allow you to define functions within functions , something you
    // otherwise could not do.

    // here is the basic syntax:
    // [capture_clause](parameters) -> return_type { function_body; };

    // eg)
    auto add = [](int a, int b) -> int { return a + b; };
    std::cout << "5 + 3 = " << add(5, 3) << std::endl;
    // now we can use add(a, b) to add stuff. notice we catured nothing in this example.

    // CAPTURING VARIABLES
    // lambda functions have a unique feature called caturing variables, whatever you but inside the [].
    // what it means to capture a variable is that you give a copy of that variable to the lambda object.

    // for example
    int x = 69;
    auto foo = [x](int a) -> int {return x + a; };
    // here , foo gets its own copy of x baked into the lambda object. think of the lambda object as adopting
    // a constant with the value x. in this case u can almost imagine that x is some non-mutable field of the lambda.

    std::cout << "foo(5) is " << foo(5) << std::endl;

    // if we wanted to mutate x , we could pass it by reference like this:
    auto bar = [&x](int a) { x += a; };
    bar(5); // should mutate existing variable x by adding 5 to it

    std::cout << "x is now: " << x << std::endl;
    // should be 69 + 5 = 74 now.

    // CAPTURE CLAUSE OPTIONS
    //  []: captures nothing
    //  [=]: captures all variables by value
    //  [&]: captures all variables by reference
    //  [var]: captures var by value
    //  [&var]: captures var by reference
    //  [=, &var]: captures all variables by value but var by reference
    //  [&, var]: captures all variables by reference but var by value
    //  [this]: captures the `this` pointer

    return 0;
}
