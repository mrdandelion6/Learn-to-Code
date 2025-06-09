# in this file we will learn how to use CMakeLists.txt to compile a C++ project

# MIN VERSION
# every CMake project starts with a minimum version:
cmake_minimum_required(VERSION 3.10)

# PROJECT NAME
# we also need to specify the project name:
project(example-project)

# C++ STANDARD
# optionally, we can specify the C++ standard.
# this is not required, but it is recommended:
set(CMAKE_CXX_STANDARD 17)
# the standard specifies the version of C++ we are using.
# this build system will use C++17 to generate the executables.
# note that set() is a CMake command that sets a variable.
# by setting CMAKE_CXX_STANDARD, we are telling CMake to use C++17.
# this is because CMAKE_CXX_STANDARD is a keyword variable that CMake recognizes.
# similiarly, you can set other variables to configure the build system.

# SOURCE FILES
# now we add the executable:
add_executable(example-project src/main.cpp)
# this command tells CMake to compile the file main.cpp
# and generate an executable called example-project

# COMPILING
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

# COMMENTS:
# use # for comments, like this one

# VARIABLES:
# use set() to define variables and use ${} to access them
set(MY_VARIABLE "Hello, World!")
message(${MY_VARIABLE})
# note that message prints "Hello, World!" to the terminal

# FUNCTIONS:
# use function() to define functions
function(say_hello)
    message("Hello, Function!")
endfunction()

# you can invoke the function like this:
say_hello()

# ADDING DIRECTORIES:
# use add_subdirectory() to add directories
# this is useful for organizing your project
# for example, suppose you have the following directory structure:
    # languages/c++/example-project/
    # ├── CMakeLists.txt
    # ├─ src
    # │   └── main.cpp
    # └── lib
    #     └── math
    #         ├── CMakeLists.txt
    #         ├── src
    #         │   └── math.cpp
    #         └── include
    #             └── math.h

# you can add the math library like this:
add_subdirectory(lib/math)
# this will look for a CMakeLists.txt file in the math directory
# and compile the math library
# so when we call add_subdirectory():
    # 1. CMake will look for a CMakeLists.txt file in the specified directory
    # 2. CMake will execute the CMakeLists.txt file in the specified directory and process the commands
    # 3. CMake will return to root context and continue processing the commands in the root CMakeLists.txt file (this file)

# we have the following in lib/math/CMakeLists.txt:
    #1 add_library(mathlib
    #2     src/math.cpp
    #3     include/math.h
    #4 )
    #5
    #6 target_include_directories(mathlib
    #7     PUBLIC
    #8         ${CMAKE_CURRENT_SOURCE_DIR}/include
    #9 )

# after this, we need to link the math library to the main executable. that will be after the following notes about libraries and scopes.

# LIBRARIES:
# lets analyze the above code line by line.
# 1: add_library() is a CMake command that creates a "library" target.
# prototype: add_library(name source1 source2 ...)
    # a library is a collection of object files that can be linked to other targets.
    # in this case, we are creating a library object called mathlib. that's why we have the name mathlib as the first argument.
# 2-3: the second argument is the source files that will be compiled to create the library.
    # in this case, we are compiling the file math.cpp to create the library.
    # note we also include the header file math.h. this isn't strictly necessary, but we should still do it.
    # it's not needed because the source file includes the header file anyways.
    # we still include it for a few reasons:
        # 1. IDE support: sometimes cmake uses this list to tell IDEs about the files in the project.
        # 2. dependency tracking: if the header file changes, cmake will know to recompile the source file.
# 6: target_include_directories() is a CMake command that specifies the "include directories" for a target.
# prototype: target_include_directories(target scope include_dir1 include_dir2 ...)
    # an include directory is a directory that contains header files, as that is what we "include" in our source files.
    # we need include directories to tell the compiler where to look for header files.
    # for example, if we had #include "math.h" in our math.cpp file, the compiler would look in the include directory for the math.h file.
    # this is of course because we never specify the full path to the header file in the #include directive.
    # by using target_include_directories(), we can specify the include directories for a target, and just putting #include "math.h" in our source file will work.
# 7: PUBLIC is a keyword that specifies the "scope" of the include directory.
    # PUBLIC means that the include directory will be available to any target that links to this target.
    # more on this in the next section.
# 8: the second argument is the include directory that we want to specify.
    # ${CMAKE_CURRENT_SOURCE_DIR} is a variable that contains the path to the current source directory.
    # as the CMakeLists.txt file is in the math directory (.../lib/math/), ${CMAKE_CURRENT_SOURCE_DIR} will be the path to the math directory (.../lib/math/).

# SCOPES:
# CMake has three scopes: PRIVATE, INTERFACE, and PUBLIC.

# PUBLIC means that the property will be applied to the target and any target that links to it.
# for example, if we have a target A that links to target B, and target B has a PUBLIC property, target A will inherit that property.
# so for the above example, ${CMAKE_CURRENT_SOURCE_DIR}/include will be available to any target that links to mathlib.

# INTERFACE means that the property will be applied to any target that links to the target, but not the target itself.
# for example, if we have a target A that links to target B, and target B has an INTERFACE property, target A will inherit that property but target B will not.
# this is useful for specifying properties that should only be applied to targets that link to the target, but not the target itself.

# PRIVATE means that the property will only be applied to the target itself.
# for example, if we have a target A that links to target B, and target B has a PRIVATE property, target A will not inherit that property.
# so in our above example , if we had PRIVATE , ${CMAKE_CURRENT_SOURCE_DIR}/include would only be available to mathlib and not any target that links to mathlib.
