// C Notes

// std stands for standard library, io for the input/output, and .h to signify header code
#include <stdio.h> // for scanf and printf
#include <stdbool.h> // for using bool types


// C source code has an entry point just like Java, which is the main() method.
// note at the top we have #include statements. this is needed for C for using several (common) methods, types, etc.
int main() {

    // in C, even for functions, we must declare the function signatures ahead of time
    int takeInput(); 
    return takeInput();
}

int takeInput() {
    double num1, num2;
    printf("Type two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2);
    printf("You typed %f and %f\n", num1, num2);
    return 0;
}

bool test() {
    return true;
}