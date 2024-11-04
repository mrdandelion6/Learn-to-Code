#include <iostream>
#include <string>
#include <limits>
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
// to run the code for a specific topic, just call it in the main() function by replacing the function under "// RUN"

// BASIC CONCEPTS
int what_is_cpp();
int compiling_cpp();
int compilation_flags();
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
int const_expr();

// ADVANCED TOPICS
int multithreading();
int perfect_forwarding();
int variadic_templates();


int main() {
    // RUN
    stdin_stdout();
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

    // using stdout
    // in c++, stdout is handled using the cout stream (cout stands for character output / console output):
    std::cout << "(1) Enter a number: ";

    // note that cout is part of the std namespace, so we use the scope resolution operator ::
    // we will learn more abouut the scope resolution operator in a later section.. but for now just know that we use it to specify where we want to use cout from.
    // its kind of like when you have a class and you access a method or attribute from that class using . in python, but it's a bit different.

    // using stdin
    // in c++, stdin is handled using the cin stream (cin stands for character input / console input):
    int number;
    std::cin >> number;
    // the above code reads an integer from the console and stores it in the variable number.

    std::cout << "(1) You entered: " << number << std::endl;

    // insertion and extraction operators:
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
    // std::endl is a manipulator that inserts a newline character into the stream and flushes the output buffer.
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

    // note that we did not even get a newline afer "Enter a word: " because cin left it in the buffer.
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

int containers_algorithms() {

    return 0;
}

int references() {



    return 0;
}