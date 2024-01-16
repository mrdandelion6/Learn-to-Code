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
    // note we cannot have nested functions in C

    // jump to a function to see the section of notes
    int types();
    int IOstuff();
    int takeInput();
    int average_temp();
    int iteratingThroughArrays();
    int loopIterationQuestion();
    int welcomeToPointers();
    int assigningToDeferencedPointers();
    int usefulnessOfPointers();
    int passingArrays();
    int pointerArithmetic();
    int pointersToPointers();
    int whyUsePointerToPointers();
    int cDeclarationSynax();
    int cFunctionTypes();
    
    IOstuff();
    

    return 0;
}

int types() {
    // 

    return 0;
}

int IOstuff() {
    printf("yo\n"); // #include <stdio.h> tells C where to find printf function. standard input/output
    printf("here is an integer: %d\n", 10); // #include <stdio.h> tells C where to find printf function. standard input/output
    // format specifiers
    // INTEGERS
        // %d: signed decimal
        // %u: unsigned decimal
        // %o: unsigned octal
        // %x: unsigned hex

    // FLOATS
        // %f: decimal floating-point
        // %e: scienfitic notation (exponential)
        // %g: use %e or %f, whichever is shorter

    // CHAR SPECIFIERS
        // %c: character
        // %s: string

    // POINTER SPECIFIERS
        // %p: pointer address
    
    // SIZE SPECIFIERS
        // %ld: long int 
        // %lu: long unsigned int
        // %lld: long long int
        // %llu: long long unsigned int

    // WIDTH AND PRECISION, these take 2 args
        // %*d: integer width specifier. args: int, width
        // %.f: floating point precision specifier. args: float/double, precision

    double pi = 3.141592653589793238;
    printf("Approximate value of pi: %.*f\n", 4, pi);

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

int usefulnessOfPointers() {
    char grade_bob1 = 'B';
    printf("bob1 got: %c\n", grade_bob1);
    // late penalty applied, now bob1 has a mark of C

    grade_bob1++; // ASCII code keys are in order
    printf("bob1 got: %c\n", grade_bob1);

    char grade_bob2 = 'A'; 
    printf("bob2 got: %c\n", grade_bob2);
    // say bob2 was late as well. lets make a helper function for applying late penalty

    void apply_late_penalty(char grade);
    void proper_late_penalty(char* pt);

    apply_late_penalty(grade_bob2);
    printf("bob2 got: %c\n", grade_bob2); // doesn't change bob's grade because the function's variable value is lost in the stack

    // to get around this we can just have the pointer as an argument to change the variable values directly

    proper_late_penalty(&grade_bob2);
    printf("bob2 really got: %c\n", grade_bob2); // works!

    // pointers give a way from inside a function to change a variable's value that's stored outside of the stack space of the function!
    return 0;
}

void apply_late_penalty(char grade) {
    grade++; // this value gets discard in the stack
}

void proper_late_penalty(char* pt) {
    (*pt)++; // *pt = *pt + 1; 
    // if we did *pt++; it would do pt += 1, then get *pt
}

void change(int *A) {
    A[0] = 50;
}

int passingArrays() {
    // generally want to pass pointers rather than passing arrays

    int scores[4] = {4, 5, -1, 12};
    
    int sum(int A[4]);
    int sum2(int *A);
    int properSum(int *A, int size);

    printf("size of scores: %d\n", sizeof(scores));

    printf("total is %d\n", properSum(scores, 4));
    // when we pass in an array into a function, we are not passing in the array  itself, 
    // but rather the address of the array!

    // it's important to remember we are passing a pointer to the first element of the array (also just the address of the array)
    // and not a copy of the array itself

    change(scores); // mutates the list! this is because we passed in the address to the array!
    printf("first element of scores is: %d\n", scores[0]); 

    return 0;
}

int sum1(int A[4]) { // hence, even though this works, it is misleading to think of it as passing in the array.
    int total = 0;

    for (int i = 0; i < 4; i++) {
        total += A[i];
    }
    
    // printf("size of A: %d\n", sizeof(A)); // we see this doesnt give the same size as scores.
    // this is because what is actually passed is the pointer to the front of the array, which has a size of 4 bytes here.
    return total;
}

int sum2(int *A) { // this is how we should do it
    int total = 0;

    for (int i = 0; i < 4; i++) {
        total += A[i];
    }

    return total;
} // however we still have an issue with this as the sum is locked to 4 element arrays
// cant use sizeof because the argument is just the first element's pointer A[0]
// only way is to pass in the size of the array as an additional parameter

int properSum(int *A, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += A[i]; // offset into the memory
    }
    
    return total;
}

int pointerArithmetic() {
    // x / y gives integer divsion if theyre both integer but floating if either are floating
    // but what if int *x; int y ?

    // when we use a + operator on pointer, it depends on the type of the pointer

    int i = 77;
    int *p = &i;

    int *s = p + 1; // s must be type int *.
    // doing + 1 adds 4 bytes to the address since p pointed to an int and ints take 4 bytes

    printf("(int) address of p: %p\n", p); // prints memory address in hexadecimal bytes: eg, 0061FF04
    printf("address of p + 1: %p\n", s); // eg, 0061FF08


    char x = 77; // ASCII key 
    char *q = &x;
    char *r = q + 1;
    // doing + 1 adds 1 byte to the address since p pointed to a char and chars take 1 byte

    printf("(char) address of q: %p\n", q); // prints memory address in hexadecimal bytes: eg, 0061FF04
    printf("address of q + 1:%p\n", r); // eg, 0061FF08

    // pointer arithmetic is useful for arrays
    int A[3] = {13, 55, 20};
    int *z = A;
    printf("value of z deferenced: %d\n", *z); // deference z, prints 13
    printf("value of z + 1 derefd: %d\n", *(z + 1)); // deference z + 1, prints 55

    // we can use array syntax with a pointer!
    p[0]; // this is just p + 0
    p[1]; // this is p + 1. just like when iterating through arrays, we apply a memory offset
    // ie; p[k] == *(p+k)

    printf("val of z[0]: %d\n", z[0]); 
    printf("val of z[1]: %d\n", z[1]); 

    return 0;
}

int pointersToPointers() {
    // storing the address of a pointer in another pointer
    int i = 81;
    int *pt = &i; // we want to store the address of the pointer pt in another pointer q

    int **q = &pt; // stores the address of pt!
    // type is int star star, q is a pointer to pointer to int
    // q -> pt -> i

    printf("%p\n", pt);
    printf("%p\n", *q); // prints same!

    // we can dereference q twice to get *pt, the value stored in the address pt points to, also the value of i
    printf("%d\n", **q);

    // we can keep adding more stars and get ***q
    // this is a very commonly used in coding! eg) matrices, tables of data.

    return 0;
}

void find_largest(int *A, int A_size, int *largest_pt) {
    // set *largest_pt to largest element in array INTEGERS!!
    *largest_pt = *A; // start by pointer to first pointer

    for (int i = 0; i < A_size; i++) {
        if (*largest_pt < A[i]) {
            *largest_pt = A[i];
        }
    }

}
void find_largest2(int **A, int A_size, int *largest_pt) {
    // set *largest_pt to largest element in array of POINTERS!!
    *largest_pt = **A; // start by pointer to first pointer

    for (int i = 0; i < A_size; i++) {
        if (*largest_pt < *A[i]) {
            *largest_pt = *A[i];
        }
    }

}

int whyUsePointerToPointers() {
    
    int i = 81;
    int j = -4;
    int A[2] = {i, j};

    int largest;

    find_largest(A, 2, &largest);
    printf("largest is %d\n", largest);

    // what if instead of holding integers, A held integer pointers?
    // it is common to have an array of pointers so this is a practical question.
    int *B[2] = {&i, &j}; // type of B is int * array so must specify that
    find_largest2(B, 2, &largest);
    printf("largest is %d\n", largest);

    return 0;
}

// === C DECLARATION SYNTAX ===
// basic rule: declarations mimics use
// form declaration statement by mimicking syntax we will later use when using the variable

int cDeclarationSynax() {
    // say we have a variable f
    // f;
    // f[10]; and we subscript it with *
    // *f[10]; make it a pointer
    // (*f[10])(); and we call it as if it was a function

    int (*f[10])(); // declaration, mimicks the eventual use
    // this means array of ten pointers to functions returning int

    // simpler:
    int *g[10]; // an array of 10 pointers that point to int 

    // CASTS
    // syntax for cast is derived from the corresponding declaration
    double x = 3.14;
    int y = (int) x;  // assigns 3 to y
    printf("%d\n", y);

    return 0;
}

int cFunctionTypes() {
    // function types describe the signature of a prototype of a function.
    // you can declare function types using the following syntax:
    // return_type (*function_pointer)(parameter_types);

    int (*sum)(int, int);
    int add(int a, int b);

    // a function pointer; will point to a function that takes two integer arguments and returns an integer
    sum = &add;
    // this is similiar to function expressions in javascript.
    printf("%d\n", sum(3, 2)); // prints 5

    return 0;
}

int add(int a, int b) {
    return a + b;
}
