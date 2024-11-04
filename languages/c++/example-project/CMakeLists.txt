# in this file we will learn how to use CMakeLists.txt to compile a C++ project

# every CMake project starts with a minimum version:
cmake_minimum_required(VERSION 3.10)

# we also need to specify the project name:
project(example-project)

# optionally, we can specify the C++ standard.
# this is not required, but it is recommended:
set(CMAKE_CXX_STANDARD 17)
# the standard specifies the version of C++ we are using.
# this build system will use C++17 to generate the executables.

# now we add the executable:
add_executable(example-project src/main.cpp)
# this command tells CMake to compile the file main.cpp
# and generate an executable called example-project

# that's all you need to compile a C++ project with CMake in the simplest way.
# to compile the project, we need to create a build directory and run cmake in it.
# here is how you can do it in the terminal:
    # mkdir build
    # cd build
    # cmake ..
    # make

# notice that we do not specify the build system.
# when running cmake in terminal, it will automatically use make
# unless we specify a different build system with the -G flag.
    # eg) cmake -G "Ninja" ..

# now we discuss more CMake commands and features..

# COMMENTS: use # for comments, like this one

# VARIABLES: use set() to define variables and use ${} to access them
set(MY_VARIABLE "Hello, World!")
message(${MY_VARIABLE}) # prints "Hello, World!" to the terminal

# FUNCTIONS: use function() to define functions
function(say_hello)
    message("Hello, Function!")
endfunction()

# you can invoke the function like this:
say_hello()