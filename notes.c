// C Notes

// std stands for standard library, io for the input/output, and .h to signify header code
#include "functions.h" // for sharing functions
#include <stdio.h> // for scanf and printf
#include <stdbool.h> // for using bool types
#define DAYS 365 
// use define to define a constant global value!

// C source code has an entry point just like Java, which is the main() method.
// note at the top we have #include statements. this is needed for C for using several (common) methods, types, etc.
int main() {

    // in C, even for functions, we must declare the function signatures ahead of time
    int takeInput();
    int average_temp();
    int iteratingThroughArrays();
    int loopIterationQuestion();
    int welcomeToPointers();
    int assigningToDeferencedPointers();
    assigningToDeferencedPointers();

    return 0;
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

// === IMPORTING FUNCTIONS ===
// to import functions from one c file to another must create a header file, for example functions.h
// inside the header file, have the following

#ifndef FUNCTIONS_H // starting place
#define FUNCTIONS_H

int takeInput(); // functions to make accessible between files
int averageTemp();

#endif // closing place


// === ARRAYS ===
int averageTemp() {
    float daytime_high_1 = 16.0;
    float daytime_high_2 = 12.8;
    float daytime_high_3 = 14.6;
    float daytime_high_4 = 19.1;
    float average_temp = (daytime_high_1 + daytime_high_2 + daytime_high_3 + daytime_high_4) / 4;
    // shove all these values into an array instead

    // in C, all elements of an array must be the same type
    // declare the type of elements the array holds, the name of the array variable, and how many elements it holds
    // like this, where n is number of elements array holds: type arrayName[n] 
    float daytime_high[4];

    daytime_high[0] = 16.0; // bracket notation to access array elements
    daytime_high[1] = 12.8;
    daytime_high[2] = 14.6;
    daytime_high[3] = 19.1;

    int index = 1;
    printf("On day %d, the high was %f.\n", index, daytime_high[index]);  

    // array memory in C, line by line memory status
    int A[3]; // an array of 3 elements in declared in the stack, initial values are junk; whatever was previously in those memory addresses
    A[0] = 13; // address values of A[0] is set to value of 13
    A[1] = 55; // same ..
    A[2] = 20; // same ..

    // we can accomplish the same thing with less syntax.
    // initialize the final value at the same time as declaration
    int B[3] = {13, 55, 20}; 
    // arrays are contiguous in memory.
    // this means a space for the entire array is assigned in memory as soon as the array is declared
    // the following elements of the array will have their values stored in memory side by side, no gaps in memory
    // by consequence, arrays cannot change in size

    // for element addresses, the adress of array[0] is same as the address of array
    // if it is an integer array, each element is dedicated 4 bytes or 32 bits
    // address of array[n] = address of array[n-1] + 4 in this case, as each element will take 4 bytes
    // addresses are often displayed in hex

    // trying to access an index out of bounds in C doesn't cause an error, but it will lead to unexpected behaviour (value is typically 0, but it could be anything)
    // C does not care if u try to access memory out of an array's bounds

    // we could do something like:
    B[5] = 999;
    // and the compiler won't care. but this is very dangerous as we may be overriding values in memory that another variable is using.
    // leads to errors that are hard to detect.

    // doing something like
    // int x = A[9999999]; // can lead to a Segmentation fault when compiling

    return 0;
}

int arrayQuestions1() {
    // self test question 1A:
    // we need a variable to store the top 20 high scores for a video game we are programming. 
    // scores are integer values. declare an array named high_score that holds 20 integers.
    int high_score[20];

    // self test question 1B:
    // in the code fragment below an array ages has been declared. 
    // it has room for 8 integer values. Write C statements to set the
    // first three elements of this array to the values 4, 44 and 18, respectively.
    int ages[8];
    ages[0] = 4;
    ages[1] = 44;
    ages[2] = 18;

    // self test question 1C:
    // an airport shuttle is cheaper per person if you have more people in your group. 
    // in the code fragment below, the array named cost holds the shuttles cost for 
    // groups of size 0 to 3. the variable group_size is set in code that is not shown. 
    // use group_size to access the cost array and assign the correct value to total_cost.
    
    int group_size;     // value set in hidden code
    float total_cost;
    float cost[4];
    cost[0] = 0;
    cost[1] = 10.75;
    cost[2] = 20.50;
    cost[3] = 30.0;

    total_cost = cost[group_size];
}

int iteratingThroughArrays() { 
    // array iteration
    /// === FOR LOOPS ===
    float daytime_high[4] = {16.0, 12.8, 14.6, 19.1};
    float average_temp = 0;

    int i;
    for (i = 0; i < 4; i++) { // same as java
        average_temp += daytime_high[i];
        printf("average %f\n", average_temp);
    }

    average_temp = average_temp / 4.0;

    return 0;
}

int loopIterationQuestion() {
    // write a code fragment to loop over an array <ages> of <count> integers and 
    // print the age of the second oldest. uou may assume that count is at least 2.
    int count = 10;
    // variables count and ages are declared and initialized in hidden code.
    
    int ages[10] = {11, 5, 2, 9, 4, 12, 10, 8, 10, 13};
    int i;
    int secondOldest = 0;
    int oldest = 0;
    for (i = 0; i < count; i++) {
        if (ages[i] > oldest) {
            secondOldest = oldest;
            oldest = ages[i];
        }

        else if (ages[i] > secondOldest) {
            secondOldest = ages[i];
        }

    }
    printf("%d\n", secondOldest);

    return 0;
}

// === POINTERS ===
int welcomeToPointers() {
    // pointers are variables with store the addresses of other variables/values 
    // ie, address holding variable is called a pointer
    // the concept that we can manipulate memory addresses as values is a powerful idea which defines C

    int i;
    i = 5;
    printf("Value of i: %d\n", i);
    printf("Address of i: %p\n", &i); // the & operator applied to a variable name returns the address of the variable

    // when defining pointers, we use * infront of the variable.
    // the int means pt holds the address of an integer
    int *pt; // so this means pt is a pointer variable that holds the address of an integer
    // we say the type of pt is "int *"
    pt = &i; // pt is set to the memory address of i.
    printf("Value of pt: %p\n", pt);
    printf("Address of pt: %p\n", &pt);

    // the size of addresses varies but on modern intel processors, the size of addresses is 8 bytes or 64-bits
    // hence the size of pt on my intel 64 bit processor would be 8 bytes.
    // on something like RISC-V 32 the sizes would be 32 bits for addresses (same size as integers)
    
    printf("Value pointed to by pt: %d\n", *pt); // * operator loads the value a pointer points to
    // this is known as deferencing the pointer
    
    // note int *pt; is not a deference, its just a type declaration of int *

    char ch = 'Y';
    char *ch_pt = &ch;

    printf("ch_pt points to a value of %c\n", *ch_pt);
    return 0;
}

int assigningToDeferencedPointers() {
    int i = 7;
    int *pt = &i; // pt points to the address of the variable i

    int *q;

    *pt = 9; // we set the deferenced value of pt to 9, this does not unload pt*, ie) it is not 7 = 9
    // rather what happens is we just set the value stored at the address of pt to 9.
    // since pt was the memory address of i, then the value of i must change to 9.
    printf("val of i: %d\n", i); // prints 9

    // using pt* on the LHS of an expression assigns to the value stored at pt
    // using pt* on the RHS of an expression accesses the value pointed at by pt

    *pt = *pt + 1; // first we calculate the right hand side, and assign it to *pt, just like any basic variable x = x + 1;
    printf("val of i: %d\n", i);

    // tricky!!
    int *pt1 = q; // we are not assigning *pt = q, rather we are assigning pt = q. int *pt is just the declaration for pt.
    int * pt2 = q; // the space can be like this
    int* pt3 = q; // or like this; it doesnt matter

    return 0;
}