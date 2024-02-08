// C Notes
// i apologize for using camel case everywhere.. i have been coding in javascript for a week nonstop

// std stands for standard library, io for the input/output, and .h to signify header code
#include <stdio.h> // for scanf and printf
#include <stdlib.h>
#include <stdbool.h> // for using bool types
#include <string.h>
#include <time.h>
#define DAYS 365 
#include "sorting.h"
// use define to define a constant global value!


// note at the top we have #include statements. this is needed for C for using several (common) methods, types, etc.
int main(int argc, char* argv[]) {
    printf("started main\n");

    // in C, even for functions, we must declare the function signatures ahead of time
    // note we cannot have nested functions in C

    // jump to a function to see the section of notes
    int theMainMethod(int count, char* vectors[]);
    int types();
    int IOstuff();
    int compilingWithUNIX();
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
    int memoryModel();
    int dynamicMemory();
    int allocatingMemoryOnHeap();
    int freeingMemory();
    int returningAddressWithPointer();
    int nestedDataStructures();
    int typeConversions(); // some recursion here as well
    int commandLineArguments(int count, char* vectors[]);
    int structs();
    int IOmoreStuff();
    int stringStuff();
    int compilerToolChain();
    int defining_types();
    int headerFiles();
    int headerFileVariables();
    int staticKeywordInsideFunctions();
    int makeFiles();
    int IOStreams();
    int usingFiles();
    int readingFromFiles();
    readingFromFiles();
    

    return 0;
}

int theMainMethod(int argc, char* argv[]) {
    
    // MAIN METHOD
    // C source code has an entry point just like Java, which is the main() method.
    // main method! has a special signature: int main(int argc, char *argv[]) {}. or could also just be empty like main() {}
    
    // argc represents the number of arguments passed into the main method when ran. users cant manually pass in an argc argument, it automatically knows 
    // example: ./main arg1 arg2 will pass the 2 args into main and, along with the program itself as the first argument, hence the value of argc will be 3.

    // char* argv[] stands for argument vector. its an array of "strings", char* refers to a string, ie an array of chars
    // the first element of argv, argv[0] is the program itself. the other arguments are the strings. argv[1] points to "arg1", argv[2] points "arg2".
    // to see this being demonstrated, compile and run notes.c through terminal and pass arguments

    // consequently, main only takes in strings as arguments. of course these strings can be cleverly converted to other data types
    if (argc > 1) {
        for (int i=1; i < argc; i++) {
            printf("arg %d is %s\n", i, argv[i]);
        }
    }
    return 0;
}

int types() {
    // char: single characters which have ASCII keys
    printf("integers on this device are %zu bytes\n", sizeof(1));
    long x;
    printf("longs on this device are %zu bytes\n", sizeof(x));
    long long y;
    printf("long longs on this device are %zu bytes\n", sizeof(y));
    // int: integer value (32 bits) 
    // long: integer value (64 bits)
    // float: float value 
    // strings: strings are a bit different. they are arrays of characters whose ends are terminated by a special null character: \0
        // so strings are like {}'h', 'e', 'l', 'l', 'o', '\0'}.

    char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // dont have to make strings like above of course, can use shorter syntax:
    char str2[] = "bye";
    printf("%s\n", str);
    printf("%s\n", str2);

    //size_t: the type returned by sizeof(). generally size_t is an unsigned int because we dont have negative sizes

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
        // %.*f: floating point precision specifier. args: float/double, precision

    double pi = 3.141592653589793238;
    printf("Approximate value of pi: %.*f\n", 4, pi);
    printf("Approximate value of pi: %.3f\n", pi); // can also just specify num of decimals, eg %.3f

    }

int compilingWithUNIX() {
    // gcc main.c 
    // unless we provide additional arguments to the unix command above, the exe file that is produced will be a.out
    // run the executable by ./a.out

    // gcc -Wall: prints out additional warning messages, recommended to compile with -Wall
    // gcc -Wall -o main main.c: -o specifies the exectuable file to be created as main

    return 0;
}

int takeInput() {
    double num1, num2;
    printf("Type two numbers separated by a space: ");
    scanf("%lf %lf", &num1, &num2); // provided by standard io
    // we can use f for doubles in printf, but for doubles in scanf, we must use lf: long float
    // we need & on num1 and & on num2 to provide the addresses for num1 and num2 so that their values can be changed to what the user types in on the keyboard.
    // to read about pointers and memory address manipulation go here:
    int welcomeToPointers();

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


int memoryModel() {
    // imagine memory as a single vast array
    // [buffer, code, global data, heap, -- , stack, os] top to bottom from left to right

    // buffer: allocated memory at zero and very close to zero reserved for prompting segmentation faults when accessed
    // code segment: stores compiled code
    // global data: stores global variables and string literals. these are defined top level outside of any function
    // heap: reserved for dynamic memory allocation using malloc (grows downward)
    
    // unnamed space (may be reserved for things like file buffer)

    // stack: stores stack frames from functions containing variables defined inside functions
    // OS: reserved memory with the largest addresses. normal programs cant access this

    // SEGMENTATION FAULT
    // caused by:
    // 1) accessing restricted memory, example: OS memory, buffer memory
    // 2) accessing nonexistent memory
}

// commented out to prevent warnings
// int* set_i() {
//     int i = 5;
//     return &i; // produces a segmentation fault
// }

// to allocate memory dynamically within functions use heaps instead, using malloc()
int* proper_set_i() {
    // void* malloc(size_t size);
    // malloc takes a size_t argument and returns a void pointer
    // void pointer is used to return a pointer of GENERIC type
    // malloc returns a void pointer because it doesnt need to know how the memory allocated is going to be used
    // simply allocates size bytes of memory on the heap and returns a pointer to that memory

    // when we take that malloc call and assign it to a pointer, the pointer declaration will specify how that pointer's memory is going to be used

    int* pt = malloc(sizeof(int)); // allocate memory on the heap enough for 1 integer
    *pt = 5; // assign integer value 5 to that memory
    return pt; // need to return the pointer
}

int dynamicMemory() {
    int i; 
    // int* pt = set_i(); // this line of code generates a seg fault
    int* pt = proper_set_i();
    printf("*pt is %d\n", *pt);
    free(pt);
}

int* squares(int largest) {
    int* result = malloc(sizeof(int) * largest); // need this value to be int* result not int result[]
    for (int i=0; i < 10; i++) {
        result[i] = (i + 1) * (i + 1);
    }

    return result;
}

int allocatingMemoryOnHeap() {
    int* squares_to_10 = squares(10);

    for (int i=0; i < 10; i++) {
        printf("square of %d is %d\n", i + 1, squares_to_10[i]);
    }
    return 0;
}

int play_with_memory() {
    // MEMORY LEAK!!

    int i;
    int* pt = malloc(sizeof(int)); // we malloc some space
    i = 15;
    *pt = 49; // but we never end up using it! we never returned pt, so we lost the address to the memory we allocated!!

    // so we must free the memory using free();
    free(pt); // free takes a single argument which is a pointer to the beginning of a block of memory that had been returned by a call to malloc
    // free returns the address to the system managing your memory for the program so it can be reallocated.
    return 0; 

    // question? how does free() know how much to deallocate?
    // answer: the memory management system keeps track of how much memory is allocated to pointer when using malloc, so we dont need to worry about passing in how much memory to deallocate into free()
} // remark: free does not "reset" or change the value of pt, it just makes it "writeable" again. so the address in pt is still legal and we can use it, but it might be overriden
// dangling pointer: a pointer that points to memory that has already been freed is known as a dangling pointer

int freeingMemory() {
    // heap memory isnt automatically deallocated, must free it.
    play_with_memory(); // memory leak from this function but it doesnt matter in this case since we terminate the freeingMemory() and then terminate main() right after.
    return 0; // but memory leaks are very destructive for long running programs! for example, calling play_with_memory() in an infinite loop for a web browser.
} // memory will run out.. memory keeps leaking away. we eventually get an out-of-memory-error: ENOMEM

int* returnHelper() {
    int* arr = malloc(sizeof(int) * 3);
    arr[0] = 18;
    arr[1] = 21;
    arr[2] = 23;
    return arr; // returns address
}

int paramHelper(int** pt) { 
    int* arr = malloc(sizeof(int) * 3);
    arr[0] = 18;
    arr[1] = 21;
    arr[2] = 23;
    *pt = arr;
    return 0;
}

int returningAddressWithPointer() {
    // this section focuses on strategies to retrieve an address for a malloc from some other scope

    // strat 1: simply have it return the address
    int* data = returnHelper();
    printf("middle value: %d\n", data[1]);   

    // strat 2: pass in another variable to store it
    data = NULL; // rmk: setting it to null sets it to zero address
    paramHelper(&data);
    printf("middle value: %d\n", data[1]);  

    free(data);
    return 0;
}

int nestedDataStructures() {
    // nested array: an array with elements as pointers. each element may point to another array. [[], [], []].
    // we often dont know the length of an array we might want. so we need a dynamically changing array
    // need to use dynamic memory as opposed to statically defined arrays

    // practice example, create an array of pointers which point to an array of 1 integer and an array of 3 integers respectively
    int** pointers = malloc(sizeof(int*) * 2);
    pointers[0] = malloc(sizeof(int)); 
    pointers[1] = malloc(sizeof(int) * 3);

    // setting values
    *pointers[0] = 55; // this is basically *(pointers[0]) = 55. we first get the 0th element of pointers, then dereference it and set the value to 55.
    printf("first element of first array is %d\n", pointers[0][0]);
    // *pointers[0] is same as pointers[0][0]. the * acts the same as the outer [0]
    pointers[0][0] = 40;
    printf("first element of first array is now %d\n", pointers[0][0]);
    pointers[1][2] = 300;

    // free memory now
    free(pointers[1]); // standard practice is to free memory from bottom-up.
    free(pointers[0]);
    free(pointers);
    // note this "standard practice" is for important reasons.
    // suppose we had freed pointers first. then we might have trouble accessing pointers[0] and pointers[1] as they will become dangling pointers
    // and we need access to pointers[0] and pointers[1] to free them. so free memory in the reverse order you allocated it  
    // good practice is to write the free statements right after the malloc statements so u dont forget.
}


int parseIntegerString(char* s) { // note this will mutate s
    int x = 0;
    while (s[0] != '\0') {
        int y = strtol(s, &s, 10);
        x += y;

        if (y == 0) { // nothing was yielded from string
            s++; // move on to next character
        }
    }

    return x;
}

int recursiveParseString(char* s) {

    if (s[0] == '\0') { // empty string
        return 0;
    }


    int x = strtol(s, &s, 10);

    // 2 recursive cases

    if (x == 0) { // zero or bad string
        return recursiveParseString(s + 1); 
    }

    // good string 
    return x + recursiveParseString(s);
}

int typeConversions() {
    // convert from string to integer

    // strtol!! string to long. strtol() is a special function that returns long.
    // strtol(str, endptr, base)
    // str is the string to convert and base is the number base. 10 for decimal 2 for binary etc.
    // if endptr is not NULL, strtol will also store the address of the first invalid character (i.e., the first character that cannot be part of the representation of a valid long integer) in the location pointed to by endptr. 
    int x = strtol("9", NULL, 10);
    printf("%d\n", x);

    // strtol accounts for leading/trailing spaces
    printf("%d\n", strtol("   9 ", NULL, 10));

    // strtol will ignore any invalid input and count it as 0
    printf("%d\n", strtol("   asassdff ", NULL, 10));

    // strtol begins from left of string and parses right, until it hits invalid input
    printf("%d\n", strtol("   asass 2 ", NULL, 10)); // this should be zero because it his invalid input before getting 2

    // strtol begins from left of string and parses right, until it hits invalid input
    printf("%d\n", strtol("  2 asdaf ", NULL, 10)); // this should be 2 because the 2 is before invalid

    // strtol stops parsing once it reads a noninteger character after an integer character, including spaces
    printf("%d\n", strtol("  23 100 ", NULL, 10)); // this should be 23 because the space will stop strtol from parsing

    // practice: make a method that adds all integers separated with spaces. ignore all noninteger terms in addition.
    char* s = "s1s1ss 10 23 -3sdad 30  ";
    printf("%d\n", parseIntegerString(s)); // should be 1 + 1 + 10 + 23 + (-3) + 30 = 62
    printf(s); // s remains unchanged

    printf("\n\n---------\n\n");

    printf("doing it recursively, %d\n", recursiveParseString(s)); // srecursive version for fun

    return 0;
}

int sumX(char** arr, int size) {
    int x = 0;
    for (int i = 2; i < size; i++) { // start at i = 2 because i = 0 is ./program and i = 1 is s
        x += strtol(arr[i], NULL, 10);
    }

    return x;
}

double avgX(char** arr, int size) {

    if (size == 2) {
        return 0;
    }

    int x = 0;
    int c = 0;
    for (int i = 2; i < size; i++) { 
        x += strtol(arr[i], NULL, 10);
        c ++;
    }

    return (double) x / c;
}

int commandLineArguments(int argc, char* argv[]) {
    // pass in arguments from the command line into main
    printf("you passed in %d arguments\n", argc - 1);

    if (argc < 2) {
        printf("no arguments given");
    }

    else if (strcmp(argv[1], "a")) { // cannot directly compare strings in C. it will end up comparing addresses. (remember theyre pointers!)
        printf("sum is %d\n", sumX(argv, argc));
    }

    else if (strcmp(argv[1], "s")) {
        printf("avg is %f\n", avgX(argv, argc));
    }

    else {
        printf("unrecogized value for first argument.\n please enter a or s as the first argument.\n");
    }
}

struct bars {
    int count;
};

void out_of_park(struct bars* b) {
    b->count++; // short hand for the following
    (*b).count++;
}

int structs() {
    // like arrays but we can store several different types
    // we can make structs on the stack or we can statically allocate it in memoryy

    struct student1 { // goes on stack
        // the "properties" are called members of the struct
        char name[21];
        int student_num;
    }; // size of this struct would be 25 bytes. 21 bytes for the string name and 4 bytes for the integer student_num
    // but this actually wrong! sizeof prints 28. we cant really say how large a struct may be. just use sizeof to find out.
    // making structs like this is risky. size is ambiguous
    printf("%zu\n", sizeof(struct student1));

    // declaring and initializing structs
    struct player {
        char name[32];
        char* position;
        int home_runs;
        float avg;
    };

    // declare  a struct
    struct player p1;

    // init members of the struct
    strcpy(p1.name, "Shohei Ohtani");
    p1.avg = 0.304;
    p1.home_runs = 44;
    // shoudlnt do this for a membeer that varies:
    // p1.position = "pitcher" // we cant go back and change this if we do it like that
    // use malloc instead
    p1.position = malloc(sizeof("pitcher"));

    strcpy(p1.position, "pitcher");
    free(p1.position);

    struct bars BAAA;
    printf("some random value for BAA's member before init: %d\n", BAAA.count);
    BAAA.count = 1;
    printf("after init: %d\n", BAAA.count);
    out_of_park(&BAAA);
    printf("after function: %d\n", BAAA.count);

    return 0;
}

int stringStuff() {
    char name[32]; // name is an array of chars

    // string literals
    printf("Hello World");
    return 0;
}

int IOmoreStuff() {
    // fprintf()
    return 0;
}

int compilerToolChain() {
    // COMPILER TOOLCHAIN:
    // the compilertoolchain is a set of applications that transform source code into a running program

    // generally speaking, a compiler is any program that translates code in one language to a different language
    // typically, compilers accept input in some high level language (like C) and produce output in low level (like assembly)
    // we can compile c files and create .s assembly files by running
    // gcc -S main.c
    // this produces an executable main.s, and you can do cat main.s to see its contents

    // 3 phases of compilation:
    // 1) front end: translates source code to largely-language independent intermediate representation
        // eg; gcc translates all of its input languages into 2 languages: Gimple and generic.
        // can be thought of as "abstract syntax trees"

    // 3) back end: translates intermediate language into assembly language of the machine
    // 2) middle end: semantic analysis, the compiler optimizes the code

    // note the above toolchain is idealized. in reality, the phases may be very overlapped for many compilers
    // for instance, optimizations also occur in the front end and backend of the compiler

    // COMPILER:
    // (source code) -> intermediate code -> assembly code

    // then we need an ASSEMBLER to assemble the assembly code into object code (NOT EXECUTABLE YET!)
    
    //ASSEMBLER:
    // (assembly code) -> object code
    
    // then we need a LINKER to link the object code and create an executable

    // LINKER
    // (main.o) -> main.out


    // SUMMARY:
    // we make source code (main.c)

    // compiler (like gcc) takes source code and turns it into intermediate code then into assembly code (main.s) 

    // assembler takes that assembly code and turns it into object code (main.o)

    // linker takes the all the object code stuff and combines it into an executable (main.out)

    // main.c -> compiler [intermediate -> main.s] -> assembler [main.o] -> linker [main.out]

    // EXECUTABLE FILES
    // contains:
    // - all of instructions
    // - data section: containing items like constant strings
    // - links to dynamic libraries: contain object code that implements functions like printf

    // executables are not portable. cant copy from machine to another and assume it will run.
    // everything excluding source code, ie from assembly code to executable code is produced for specific machine hardware
    // executable not only cares about type of machine but also OS and system configurations 

    // A BIT MORE
    // after executable is made, it needs to be loaded into memory when it is executed. 
    // this is the LOADER's job
    // a LOADER is OS specific.

    // EVEN MORE
    // also , before the compiler takes in the source code we need to prepare it 
    // a PREPROCESSOR takes the source code and prepares it for the front end (the compiler)   
    
    // PREPROCESSOR:
    // - adds function prototypes for library and system calls required
    // - interprets preprocessor directives like "macros"
    // - removes comments

    // basically every line that starts with a # needs to be cleaned up by preprocessor

    return 0;
}

int defining_types() {
    typedef int monkey;
    // monkey is now an alias for int
    monkey x = 1;
    printf("%d\n", x);

    // more complex
    typedef void (*SortFunc_t)(int*, int);
    // SortFunc_t is now an alias for a pointer to a function that takes in two args (int*, int) and returns void

    typedef struct {
        char* name;
        SortFunc_t sort_funct;
    } sort_info;
    // sort_info is now an alias for a struct with the members char* name and SortFunc_t sort_funct

    return 0;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("index %d: %d\n", i, arr[i]);
    }
}

int headerFiles() {
    // compiling a program withh multiple source files
    // need header files!!

    // moved all of this to functions.h
    // void bubble_sort(int*, int);
    // void selection_sort(int*, int);
    // void insertion_sort(int*, int);

    // typedef struct {
    //     char* name;
    //     SortFunc_t sort_funct;
    // } sort_info; UNC

    // const int NUM_SORTS = 3;
    // sort_info SORTS[] = {
    //     {.name = "bubble", .sort_funct = bubble_sort},
    //     {.name = "selection", .sort_funct = selection_sort},
    //     {.name = "insertion", .sort_funct = insertion_sort}
    // }; // UNC

    int arr[6] = {1, 6, 3, 0, 12, 1};
    printf("at first array is:\n");
    print_array(arr, 6);

    // SORTS[1].sort_funct(arr, 6); // UNC
    printf("\nnow array is:\n");
    print_array(arr, 6);
    // when multiple files are compiled together (see shell notes)
    // each file is compiled and assembled separately and linked at the end
    // to create one executable

    // HEADER FILES:
    // headers are interfaces
    // they define what types functions require
    // the C files implement the header files interface design

    // remark: it is good practice to write #include "header_file.h" at the top of the C file that implements it
    // it may seem redundant, but it ensures types are consist across different files which use the functions in header file
   
    // large projects may have many header files; one for each specific interface

    // note that header files can contain more than just function prototypes. 
    // they can also define macros, constants, enumerations, structs, unions, and other types.
    return 0;
}

int headerFileVariables() {
    // we have factored out the typedef struct sort_info
    // and the const int NUM_SORTS = 3
    // and the sort_info SORTS[] array

    // this is an issue because it declares and INITIALIZES!! the variables in the header file
    // which is included in two separate source files.
    // this means the variables will be initialized twice, in both notes.o and sorting.o 
    // when the linker tries to link them it will see duplicate variables

    // solution: separate the declaration from the initalizion 
    // variables should be created in sorting.c in this case
    // but note that a declaration must still happen in header file or else notes.c will not know the type exists
    // when declaring variable in header file thats defined externally, we must use extern like so:
    // extern <type> <var_name>

    int arr[6] = {1, 6, 3, 0, 12, 1};
    printf("at first array is:\n");
    print_array(arr, 6);

    // SORTS[1].sort_funct(arr, 6);
    // now we can use SORTS variable here which was only declared in the header file (with extern)
    // and initialized in the sorting.c file!

    printf("\nnow array is:\n");
    print_array(arr, 6);

    // STATIC VARIABLES
    // conversely.. (continue below about this below this function)

    // we should use header guards to prevent multiple inclusions of the same header file which can lead to errors and duplicated code
    // HEADER GUARDS:
    // header guards are conditional compilation directives that are placed at the beginning of a header file
    // they prevent it from being included more than once in a single translation unit (ie a single source file)
    // implemented using the #ifndef directive.

    // #ifndef: checks if a specific symbol (usually a macro) has not been defined before.
        // if it hasnt been defined before, the header file is included otherwise the inclusion is skipped
        // eg:
        // #ifndef MY_HEADER_H  // (if not defined)
        // #define MY_HEADER_H // (now we define)
        // ... header code stuff ...
        // #endif // MY_HEADER_H // ending the if-body, we usually add a comment to show which if statement is being terminated (for readability)

    // by using header guards we can ensure that each header file is included only once,
    // even if it is included at the top of multiple source files that are being compiled.
   
    // DEPENDENCY OF HEADER FILES:
    // note that if we change a header file which source files use, then we must recompile the source files
    // this is because the header file is a "dependency" of the source files and must be reread anew after it has been changed
    // in other words, each time we run the executable we aren't going to read the header files again
    // the header files are only accessed and parsed ONCE when we compile our program
    
    // tracking dependcies can be tedious, especially for large scale projects
    // for this reason, the compiler toolchain includes a tool for tracking which files need to be recompiled
    // this is known as MAKE
    return 0;
}

// STATIC VARIABLES (continued from above function)
// .. conversely, if we would like to limit the scope of variables to just the file they are defined in
// we can use the static keyword. this will prevent other files from knowing about those variables
static int x = 0;
// note we have another x variable defined in sorting.c
// also note we are doing this outside of the headerFileVariables() function because if we did it inside
// the variable x's scope would be limited to the stack and not globally defined

void staticVarsFunctionExample() {
    static int x = 1;
    printf("%d\n", x);
    x++;
}

int staticKeywordInsideFunctions() {
    // STATIC takes on a different meaning if used within the local scope of a function!!
    // in a local function, the behaviour of the static keyword is similiar to that of static in java
    // that is, variables defined in functions with the static keyword will retain their value across function calls

    // this is because the memory location of local static variables will not be on the function stack,
    // but instead they get stored in the global data section like global variables do.
    
    // however this does not mean static turns local variables into global ones. static keyword does not change the scope of the variables.
    // their scope will still be local to the functions they are defined in.

    // observe how the increment is saved
    staticVarsFunctionExample(); // prints .. 1
    staticVarsFunctionExample(); // .. 2
    staticVarsFunctionExample();// .. 3
    staticVarsFunctionExample();// .. 4

    return 0;
}

int makeFiles() {
    // Makefiles are extremely useful and vital for c programs

    // recall in headerFileVariables(), we talk about how both source files need to be recompiled
    // if a header file they're dependent on is changed. tracking these dependencies is tricky.

    // we use a tool called make for this.
    // the project we've been compiling consists of 3 files:
        // - notes.c
        // - sorting.c
        // - sorting.h

    // we will create a Makefile to build the parts of the project that need it
    // a Makefile is a just literally a file named Makefile (no extension, capital M is important)

    // Makefiles consist of a sequence of rules.
    // each rule has:
        // - target (the excecutable file to be constructed)
        // - recipe (the list of commands to create the target)
        // - dependencies (the stuff the target is dependent on)

    // FORMAT
    // target: dependencies
        // recipe

    // if the dependencies..
        // A) are newer than the target (ie have been modified after the last modification of the target)
            // then the recipes are executed

        // B) dont exist
            // then the recipes are executed if target also doesnt exist yet
    
    // example:
    // notes_sort: notes.o sorting.o
        // gcc notes.o sorting.o -o notes_sort

    // our target is notes_sort, here. so we will create a notes_sort whenever the Makefile is ran if notes.o or sorting.o have been modified.
    // view the Makefile in this repo for examples. 
    // to run the Makefile, simply type `make` in the terminal while the Makefile is in your pwd

    // to run a specific target within the Makefile, for example:
        // clean:
            // rm *.o notes_sort
    // we can just type `make clean` in the terminal
    // for targets like this that arent actual files, preceed the line with .PHONY: `clean`
            // .PHONY: clean
            // clean:
            // rm *.o notes_sort

    // REMARK:
    // when u type `make` and run a Makefile, it only evaluates the first rule in the file.
    // it does not automatically start going from top to down on each rule to evaluate it.
    // what does happen is this:
        // 1.) the first rule is evaluated
        // 2.) all the dependencies are checked
        // 3.) if the dependencies for the first rule are also targets in the makefile, it will jump and evaluate those rules first
        // 4.) this way, the rules in the makefile are recursively evaluated
    
    // hence it is important to select your first rule wisely if you want to just call `make`
    // otherwise you can call a specific rule to evaluate by specifying the target: `make clean`
    // here is an example of a smartly structured Makefile. all of the rules are recursively evaluated here.
        // notes_sort: notes.o sorting.o
        //     gcc notes.o sorting.o -o notes_sort

        // notes.o: notes.c sorting.h
        //     gcc -c notes.c

        // sorting.o: sorting.c sorting.h
        //     gcc -c sorting.c

        // .PHONY: clean
        // clean:
        //     rm *.o notes_sort

    // WILDCARDS
    // quick syntax for multiple files and stuff. here is an example:
    // %.o: %.c sorts.h
        // gcc -c $< -o $@

    // lets analyze this part by part:
        // %.o: %.c sorts.h
        // here the target is %.o and the dependencies are %.c (a source file of the same name) and sorts.h

        // gcc -c $< -o $@
        // here we create an object file from $< which symbolizes the first name in the last of dependencies, ie; $.c
        // and $@ just means the target's name, so we give it the name of the target

    // one last thing is that Makefiles can include variables.
    // this can help a lot against having to rewrite a whole chain of files over and over again
    // at the top we define variables like:
        // OBJFILES = notes.o sorting.o
    // and we can reference the variable by doing $(OBJFILES) instead of having to write notes.o sorting.o each time.
    // the primary benefit of this is that we wont have to go and change several lines of code if we decide to add another file later into the mix.
    // its all factored out into the OBJFILES variable, the only thing we will have to change. basic coding principle.

    return 0;
}

int IOStreams() {
    // we always use printf and scanf, but there is more.
    // writing and reading from files etc.

    // c's input and output functions read and write from STREAMS.

    // INPUT STREAM: source of data that provides input to program
    // OUTPUT STREAM: a destination for data output by program

    // when we do scanf to read data from keyboard, we actually read from the input stream called STANDARD INPUT
    // by default, standard input is set to read from keyboard

    // similiarly, printf writes data to standard output which is the screen by default

    // furthermore, there is a third stream that is automatically open as well called standard error.
    // the default location for standard error is also screen.

    // STREAM                 STANDARD NAME         DEFAULT LOCATION
    // Standard Input         stdin                 Keyboard
    // Standard Output        stdout                Screen
    // Standard Error         stderr                Screen

    // why have 2 different streams for output? 
    // ans: we can change the location for specific streams giving different output behaviours for each stream.
    // for example, maybe we want normal output to be saved in a file but error messages to appear on screen.

    // streams have standard names (see table above). 
    // streams are powerful because of how versatile they are; 
        // they can refer to disc files, network connections, computer devices, etc.

    // REDIRECTING STREAMS!

    int number;
    scanf("%d", &number);
    printf("the num is %d\n", number);

    // want to instead read the input from a text file, not keyboard.
    // we can do this by compiling the program with ./notes < iostuff.txt

    // for example:
    // sort < names.cat > students.txt
    // this sets the stdin of sort to be from names.cat and the stdout to be students.txt

    return 0;
}

int usingFiles() {
    // want a way to store values across executions; DATA PERSISTENCE
    // we can do this via local files

    // we can open files for reading like so:
    // FILE* file = fopen(const char* filename, const char* mode);

    // modes are "r": reading, "w": writing, "a": appending

    // FILE is a typedef struct from stdio.h library
    FILE* score_files = fopen("iostuff.txt", "r"); // this makes the file available as a STREAM
    
    // fopen can fail for several reasons:
        // file doesnt exist
        // dont have permissions to open file
    
    // if fopen fails, it returns NULL instead of a valid file pointer. so we need a NULL check.
    if (score_files == NULL) {
        fprintf(stderr, "Error opening file\n"); 
        return 1; // returning 1 means error
        // note that fprintf allows us to choose the output stream. this is a specified output stream.
    } else {
        printf("File opened!\n");
    }

    // if we open a file we should also close it.

    // we can fclose within the condition for an if statement, then check if it returns 0 or not
    if (fclose(score_files) != 0) { // fclose returns 0 if it closed the file successfully.
        fprintf(stderr, "fclose failed\n");
        return 1;
    } // fclose can fail if the file pointer is invalid, for example if it is NULL.

    return 0;
}

int readingFromFiles() {
    // there are a variety of functions in C standard library that can be used to read data from streams
    // the one to use depends on the kind of data u are reading

    // when reading text or complete lines of data, fgets is often the choice to use.
    // char* fgets(char* s, int n, FILE* stream)
    

    return 0;
}