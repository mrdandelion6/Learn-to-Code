add_library(mathlib
    src/math.cpp
    include/math.h
)

target_include_directories(mathlib 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)