#include <iostream>
// remark .. C++ prefers camel case. i will be using snake case for many things though :p

int main() {

    // WELCOME TO MY C++ NOTES
    // hello, welcome to my C++ notes
    // in these notes, you will learn how to write C++ code
    // we will start with the basics, and eventually move on to more advanced topics
    // these notes assume you are ALREADY FAMILIAR WITH C and have a basic understanding of programming
    // if you are not familiar with C, read my C notes first 

    // in the main() function, we have a bunch of function prototypes that each represent a topic
    // you can jump to the function definition for each prototype to see a specific topic
    // to run the code for a specific topic, just call it in the main() function by replacing the function under "// RUN"

    // TOPICS
    int what_is_cpp();
    int compiling_cpp();
    int cmake();
    int oop();
    int stl();
    int namespaces();
    int scope_resolution_operator();
    int references();
    int function_overloading();
    int exception_handling();
    int default_arguments();
    int raii();
    

    // RUN
    what_is_cpp();
}

int what_is_cpp() {
    // C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language
    // but we ask, why? why do we need C++ when we already have C?

    // why C++ instead of C?
    // C++ is an extension of C, which means that C++ is a superset of C
    // all valid C programs are also valid C++ programs
    // C++ is a more modern language that includes features like classes, objects, and inheritance
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

    return 0;
}