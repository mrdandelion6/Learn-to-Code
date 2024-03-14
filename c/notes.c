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
#include <sys/types.h> 

// these libraries are for forking processes
#include <unistd.h>
#include <signal.h>
#include <errno.h>

// use define to define a constant global value! these are stored in global data


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
    int compilerToolChain();
    int defining_types();
    int headerFiles();
    int headerFileVariables();
    int staticKeywordInsideFunctions();
    int makeFiles();
    int IOStreams();
    int usingFiles();
    int readingFromFiles();
    int scanFFunction();
    int writingToFiles();
    int usingFilesEnd();
    int welcomeToStructs();
    int pointersToStructs();
    int lowLevelIO();
    int writingBinaryFiles();
    int readingBinaryFiles();
    int wavFiles(int argc, char* argv[]);
    int readWriteStructs();
    int movingAroundInFiles();
    int stringsInC();
    int linkedStructures();
    int typedefInC();
    int macrosInC();
    int thePreprocessor();
    int functionLikeMacros();
    int functionPointers();
    int systemCalls();
    int errorsAndErrno();
    int processModels();
    int creatingProcesses();
    int relationshipOfProcesses();
    int relationBetweenShellAndProcesses();
    int usingMacrosForStat_loc();
    int zombieAndOrphanProcesses();
    int runningDifferentPrograms();
    int signalsInC();
    int handlingSignals();
    handlingSignals();
    

    return 0;
}

int theMainMethod(int argc, char* argv[]) {
    
    // MAIN METHOD
    // C source code has an entry point just like Java, which is the main() method.
    // main method! has a special signature: int main(int argc, char *argv[]) {}. or could also just be empty like main() {}
    
    // argc represents the number of arguments passed into the main method when ran. users cant manually pass in an argc argument, it automatically knows 
    // example: ./main arg1 arg2 will pass the 2 args into main and, along with the program itself as the first argument, hence the value of argc will be 3.

    // char* argv[] stands for argument vector. its an array of "strings", char* refers to a string, ie a string literal since we have char*. (char[] would be a mutable C string, more on this later).
    // the first element of argv, argv[0] is the program itself. the other arguments are the strings. argv[1] points to "arg1", argv[2] points "arg2".
    // to see this being demonstrated, compile and run notes.c through terminal and pass arguments

    // consequently, main only takes in strings as arguments. of course these strings can be cleverly converted to other data types. 
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
    int* pt = &i; // pt points to the address of the variable i

    int* q;

    *pt = 9; // we set the deferenced value of pt to 9, this does not unload pt*, ie) it is not 7 = 9
    // rather what happens is we just set the value stored at the address of pt to 9.
    // since pt was the memory address of i, then the value of i must change to 9.
    printf("val of i: %d\n", i); // prints 9

    // using pt* on the LHS of an expression assigns to the value stored at pt
    // using pt* on the RHS of an expression accesses the value pointed at by pt

    *pt = *pt + 1; // first we calculate the right hand side, and assign it to *pt, just like any basic variable x = x + 1;
    printf("val of i: %d\n", i);

    // tricky!!
    int *pt1 = q; // we are not assigning *pt = q, rather we are assigning pt = q. int * is just the declaration for pt.
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

    int* s = p + 1; // s must be type int *.
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
    int* g[10]; // an array of 10 pointers that point to int 

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
        printf("no arguments given\n");
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
    FILE* score_files = fopen("io-stuff/iostuff.txt", "r"); // this makes the file available as a STREAM
    
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

#define LINE_LENGTH 80

int readingFromFiles() {
    // there are a variety of functions in C standard library that can be used to read data from streams
    // the one to use depends on the kind of data u are reading

    // when reading text or complete lines of data, fgets is often the choice to use.
    // char* fgets(char* s, int n, FILE* stream)
        // fgets returns s on success
        // first arg: s is a pointer to memory where text can be stored
            // s can be a char array or point to a block of memory allocated by malloc
            // this argument specifies where the input should be stored after reading it
        // second arg: n is the maximum number of characters fgets is allowed to put in s, including the \0 null character at end of string

    FILE* opm_scores = fopen("io-stuff/iostuff.txt", "r");

    // define string location for fgets
    char line[LINE_LENGTH + 1]; // char array of size LINE_LENGTH + 1 (add 1 to account for null terminator)

    // OPEN
    if (opm_scores == NULL) {
        fprintf(stderr, "erro: could not open file\n");
        return 1;
    }
    
    // loop to read ALL LINES
    while(fgets(line, LINE_LENGTH + 1, opm_scores)) {
        printf("%s", line);
    }
    // remember: the opm_scores is a pointer to the file.
    // the pointer automatically points to the first line of the file at the start.
    // after each fgets call, the pointer moves down one line
    // if fgets has nothing to read, ie; end of file, then fgets returns NULL and loop ends
    // fgets reads a line and adds null terminator to the end of the line or after at most LINE_LENGTH characters

    // CLOSE
    if (fclose(opm_scores) != 0) {
        fprintf(stderr, "erro: could not close file\n");
        return 1;
    }

    // fgets can also be used to read from stdin (stdin is a stream just like a file)
    // fgets is often more useful than scanf for reading strings from the keyboard
    // this is because scanf stops reading at a space character whereas fgets stops reading after a newline char
    // eg)

    while (fgets(line, LINE_LENGTH + 1, stdin)) {
        printf("you typed: %s", line);
    }
    // for something like a terminal, this loop happens indefinitely as the input stream stdin will stay open and fgets will wait for input.
    // to end the loop, use a keyboard shortcut to signal end of file, CTRL + D.

    printf("\nended\n");
 
    return 0;
}

int scanFFunction() {
    // very same to scanf, but fscanf can choose to read from any input stream whereas scanf is forced to read from stdin

    // prototype:
    // int fscanf(FILE* stream, const char* format, ...)
        // like scanf, fscanf returns the number of items successfully read
        // number of items will be equal to number of format specifiers, unless something goes wrong when reading.

    // we can use fscanf to read from iostuff.txt instead of fgets like last time
    // this is useful if we wanna parse based on spaces

    FILE* scores_file = fopen("io-stuff/iostuff.txt", "r");
    char name[81];
    int total;

    if (scores_file == NULL) {
        fprintf(stderr, "erro: file could not be opened\n");
        return 1;
    }

    while(fscanf(scores_file, "%80s %d", name, &total) == 2) { // we compare to 2 becuase we expect 2 values
        // we choose scores_file as the input stream
        // we read two values separate by a space
            // %80s is a string of 80 characters 
            // %d is a number as you should know by now
        // we pass in ADDRESSES so we can actually change the values, eg &total
        // for a recap on this go to takeInput():
        if (0 == 1) {
            takeInput();
        }
        
        printf("Name: %s, Score: %d.\n", name, total);
    }

    if (fclose(scores_file) != 0) {
        fprintf(stderr, "erro: could not close file\n");
        return 1;
    }

    return 0;
}

int writingToFiles() {
    FILE* output_file = fopen("io-stuff/write_here.txt", "w");
    int some_int = 69;
    float some_float = 0.69;

    // use fprintf, allows to specify stream

    if (output_file == NULL) {
        fprintf(stderr, "erro: couldnt open file\n");
        return 1;
    }

    fprintf(output_file, "some number is: %d\n", some_int);
    fprintf(output_file, "some float is: %.2f\n", some_float);
    // just like printf, we just specify the output stream in first arg

    if (fclose(output_file) != 0) {
        fprintf(stderr, "erro: could not close file\n");
        return 1;
    }

    // insights:
    // when a program writes to a stream, its actually writing to a LOCATION in memory controlled by the OS.
    // that memory is periodically written to the file on the disk. when these write backs occur depends on how the stream is set up.
    // usually the contents of the file will be what you've written.

    // potential error:
    // if the computer loses power in the middle of the program after some fprintfs, the data could not have been written.
    // we dont know if the program would have written to our file if the computer crashes

    // this is why it is not reccomended to use IO: file IO/stdout for debugging.
    // if program crashes abnormally, fprintf and printf statements may not actually be written to disk/screen.

    // hence if u are using print statements to debug, this can be misleading.
    // for debugging, use gdb!!

    // if you need to absolutely make sure that key modifications have been made to a stream you're writing to,
    // then you can FLUSH the stream:
    
    // int fflush(FILE* stream)
    // we typically dont do this, the OS handles it for you. 
    // but it essentially request the OS to write any changes that are in its buffer. 

    return 0;
}

int checkFileOpen(FILE* file, char* name) {
    if (file == NULL) {
        fprintf(stderr, "erro: could not open file %s", name);
        return 1;
    }
    return 0;
} 
int checkFileClose(FILE* file, char* name) {
    if (fclose(file) != 0) {
        fprintf(stderr, "erro: could not open file %s", name);
        return 1;
    }
    return 0;
} 

int usingFilesEnd() {
    // say we want to read the iostuff.txt file and write to write_here.txt and list all the names from iostuff but not the scores:

    FILE* iostuff = fopen("io-stuff/iostuff.txt", "r");
    FILE* writehere = fopen("io-stuff/write_here.txt", "w");
    char name[81];
    int score;

    if (checkFileOpen(iostuff, "io-stuff/iostuff.txt") == 1) {
        return 1;
    }
    if (checkFileOpen(writehere, "io-stuff/write_here.txt") == 1) {
        return 1;
    }

    while(fscanf(iostuff, "%80s %d", name, &score) == 2) {
        printf(name);
        fprintf(writehere, "%s\n", name);
    }

    if (checkFileClose(iostuff, "io-stuff/iostuff.txt") == 1) {
        return 1;
    }
    if (checkFileClose(writehere, "io-stuff/write_here.txt") == 1) {
        return 1;
    }

    return 0;
}

// global struct
struct student {
    char first_name[20];
    char last_name[20];
    int year;
    float GPA;
};

int welcomeToStructs() {
    // recall the usefulness of arrays where the data has to be of all the same type.
    // structs used to aggregate data where the values may be of different type.

    // the syntax is simple and is like a javascript object, but its usage is like that of a class. it is just a template.
    struct student1 { // student is the "structure tag"
        char first_name[20];
        char last_name[20];
        int year;
        float GPA;
    };

    // whenever we declare a variable fo a structure type, we must include struct keyword
    // MANUAL INITALIZATION (compare this with DESIGNATED version below)
    struct student1 faisal;
    // now explicitly initalize the members
    strcpy(faisal.first_name, "Faisal"); // for strings, dont do X = Y, do strcpy(X, Y)
    strcpy(faisal.last_name, "Shaik");
    // remark: we are able to use the unsafe strcpy function as opposed to the unsafe strncopy function (more on this later),
    // because we harded coded the strings to have a size of exactly 20 chars

    faisal.year = 2;
    faisal.GPA = 3.96;

    printf("my name is %s and i am in year %d\n", faisal.first_name, faisal.year);

    // elements of a struct are called members. access members using dot notation, just like class objects.

    // STRUCTS VS CLASSES
    // classes are more powerful and flexible than structs, and are used to create complex, modular, and reusable code. 
    // structs, on the other hand, are simpler and more lightweight, and are used to create aggregates of data that can be easily passed around.


    // USING STRUCTS IN FUNCTIONS
    // recall we cant pass arrays directly into functions, rather the pointer to the first element of the array
    // structs DONT work this way!! 

    void changeStruct(struct student);

    // global struct student, not student1

    // we can also declare and init structs like this
    // DESIGNATED INITALIZATER
    struct student bob = {
        .first_name = "John",
        .last_name = "Doe",
        .GPA = 2.0,
        .year = 6
    };

    changeStruct(bob);

    printf("gpa remains the same: %.1f\n", bob.GPA);

    // we see that structs do not behave the same way as arrays when passing them as arguments in a fuction.
    // they do not get changed. functions just get a copy of the struct.
    // this is in contrast to how class objects are in many coding languages. objects usually refer to an address in memory themselves, thus can be passed in like arrays in C.
    // however, this concept does not extend to structs in C.

    printf("arrays also remains same: %s\n", bob.first_name);

    // solution: to operate on the original struct just send a pointer to the struct instread of the struct itself.
    void goodChangeStruct(struct student* s);
    goodChangeStruct(&bob);
    printf("gpa now changes: %.1f\n", bob.GPA);

    return 0;
}

void changeStruct(struct student s) {
    s.GPA = 4.0;
    strcpy(s.first_name, "adam");
}

void goodChangeStruct(struct student* s) {
    (*s).GPA = 4.0;
}

int pointersToStructs() {
    // basically the same concepts as pointers to ints

    struct student s;
    struct student* p_s = &s;

    s = (struct student) {
        .first_name = "Daa",
        .last_name = "Zaa",
        .GPA = 3.2,
        .year = 3
    };

    // when using dot notation on structs by deferencing pointers, we need to put () around the dereference
    (*p_s).GPA = 2.3;
    printf("GPA changed to %.1f\n", s.GPA);
    // this is because . has higher precedence than *, so *p_s.GPA is same as *(p_s.GPA), which results in an error

    // as this syntax is kind of messy, C has easier syntax for this:
    p_s->year = 1;
    printf("year changed to: %d\n", s.year);
    // is the same as
    p_s->year = 2;


    return 0;
}


int lowLevelIO() {
    // not all files contain text but all files contain binary data.
    // the binary bytes can be translated to human readable text for .txt files etc.
    // we will explore using files where the bytes dont translate to human text.

    // binary files are smaller and more versatile for text files, that is why we use them.
    // binary files come in many different extensions:
        // - .dat
        // - .jpg
        // - .mp3
        // no extension at all, etc.
    
    // when opening binary files with fopen, we add a `b` to the end of our mode argument. eg
    // fopen("testing.dat", "rb") 
    // above we are opening a BINARY file for reading

    // fgets, fprintf, and fscanf are not useful for binary files.
        // this is because binary files dont have a notion of "lines"
        // and those functions read and produce text anyway, not binary data.
    
    return 0;
}

int writingBinaryFiles() {
    // for writing binary data into a file we use the fwrite() function.
    // the prototype is:
        // size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream)
            // ptr is a pointer to the data we want to write to the file. typically the starting address of an array.
            // could also be the pointer to an individual variable if we want to write just 1 value. thats why its void, because its ambiguous.
        // size is the size of each element that we are writing to the file
        // nmemb is the number of elements we are writing to the file
        // stream is a pointer to the file where we will write. this pointer must refer to a stream open in binary mode.

    // fwrite returns the number of elements written to the file if successful, or else it returns 0 on error.
    // typically add error checking code after fwrite calls.

    FILE* binary_file;
    int error;
    int number = 512;
    char character = 's';
    float fraction = 4.5;

    binary_file = fopen("binary_data", "wb");
    if (binary_file == NULL) {
        fprintf(stderr, "erro: could not open binary file!\n");
        return 1;
    }

    error = fwrite(&number, sizeof(int), 1, binary_file);
    error += fwrite(&character, sizeof(char), 1, binary_file);
    error += fwrite(&fraction, sizeof(fraction), 1, binary_file);
    // since we intended to write 3 items to the file, we can check to make sure everything is good by doing the following:

    if (error != 3) {
        fprintf(stderr, "erro: data not fully written to file 1\n");
        return 1;
    }

    error = fclose(binary_file);
    if (error != 0) {
        fprintf(stderr, "erro: could not close file\n");
        return 1;
    }

    // remark: characters are human readable whether in binary file or text file.
    // everything else such as integers and floats are not.

    // writing entire array:
    FILE* binary_file2;
    int numbers[] = {400, 800, 1200, 1600, 2000};

    binary_file2 = fopen("binary_data2", "wb");
    if (binary_file2 == NULL) {
        fprintf(stderr, "erro: could not open binary file 2!\n");
        return 1;
    }

    error = fwrite(numbers, sizeof(int), 5, binary_file2);
    // 5 since we are writing 5 elements from the array, each ints

    if (error != 5) {
        fprintf(stderr, "erro: data not fully written to file 2\n");
        return 1;
    }

    error = fclose(binary_file2);
    if (error != 0) {
        fprintf(stderr, "erro: could not close file\n");
        return 1;
    }


    return 0;
}

int readingBinaryFiles() {
    // we use fread()
    // the prototype is simliar to that of fwrite
    // size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream)
        // only difference is that ptr for fread does not have constant keyword

    FILE* binary_file;
    int error;

    int number;
    char character;
    float fraction;

    binary_file = fopen("binary_data", "rb");
    if (binary_file == NULL) {
        fprintf(stderr, "erro: could not open binary file! if it doesn't exist then first run writingBinaryFiles() to create it. \n");
        return 1;
    }

    error = fread(&number, sizeof(int), 1, binary_file);
    error += fread(&character, sizeof(char), 1, binary_file);
    error += fread(&fraction, sizeof(fraction), 1, binary_file);
    // note that each time we call fread, we move the file pointer accordingly
    // order in which we read values must be in same order in which they were wrote.

    // an important remark about fread here is that it may return 0 even if there is no error.
    // this is a simple case where the binary_file is just empty or the pointer has reached the end of the file.

    // this is different from fwrite where 0 is guaranteed to be an error of some sort.
    // because if we call fwrite, then we must be intending to write something, at least one thing.
    // so fwrite returning 0 guarantees an error and means to items were written to the file,
    // whereas fread returning 0 may or may not be an error, but it means that no items were read from the file.

    if (error != 3) {
        fprintf(stderr, "the data was not properly/fully read from the binary file\n");
    }

    error = fclose(binary_file);
    if (error != 0) {
        fprintf(stderr, "erro: could not close the binary file\n");
        return 1;
    }
    printf("from the file we got: %d, %c, %f\n", number, character, fraction);

    // there is a complication, fread and fwrite may be inconsistent across different machines.
    // this is because different machines may read/write binary data differently.
    // thus it is complicated to transfer binary data between machines.

    return 0;
}

#define HEADER_SIZE 44

int wavFiles(int argc, char* argv[]) {
    // we will utilize our knowledge of binary files and apply it to .wav files.
    // task: take a .wave file and make its volume louder.

    // we will begin by learning how wav files are structured. wav files are much simpler than mp3 files.

    // WAV FILES
    // 2 parts:
        // header: 44 bytes  of data.
            // header contains info about wav file, including parameters required to properly play the file in music programs.
        // sample values: these come after the header.
            // samples are two-byte values. when a wav file is created, the audio signal is sampled many thousands of times every second.
            // each of these samples is stored as one of these 2 byte integers.
        
        // linux and other OS' come with utilities for viewing binary files like .wav files.
        // one such utility is od; prints out the values found in a binary file. see the notes for od in notes.sh

    char* input_name;
    char* output_name;
    FILE* input_wav;
    FILE* output_wav;
    short sample;
    short header[HEADER_SIZE];
    int error;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s inputfile outputfile \n", argv[0]);
        return 1;
    }

    input_name = argv[1];
    output_name = argv[2];


    // ==== OPENING FILES ====
    input_wav = fopen(input_name, "rb");
    if (input_wav == NULL) {
        fprintf(stderr, "erro: could not open %s\n", input_name);
        return 1;
    }
    output_wav = fopen(output_name, "wb");
    if (output_wav == NULL) {
        fprintf(stderr, "erro: could not open %s\n", input_name);
        return 1;
    }
    // =======================


    // === TRANSFERRING HEADER ===
    // should first read the HEADER from the input file and write it to the output file
    fread(header, HEADER_SIZE, 1, input_wav); // we store it in header variable
    // header variable is an array of shorts.
    // now write it into output_wav
    error = fwrite(header, HEADER_SIZE, 1, output_wav);
    if (error != 1) {
        fprintf(stderr, "erro: could not write header to output.wav\n");
        return 1;
    }
    // ===========================


    // === MULTIPLYING SAMPLES ===
    // now we will INCREASE the volume!!
    while (fread(&sample, sizeof(short), 1, input_wav) == 1) {
        sample *= 4; // multiply each sample by 4 to increase the volume
        
        if(fwrite(&sample, sizeof(short), 1, output_wav) !=1) {
            fprintf(stderr, "failed to write short to output_wav\n");
            return 1;
        }
    } // note that we have to do a while loop for this in order to multiply each individual sample.
    // ===========================


    // ====== CLOSING FILES ======
    if (fclose(input_wav) != 0) {
        fprintf(stderr, "erro: could not close input_wav\n");
        return 1;
    }
    if (fclose(output_wav) != 0) {
        fprintf(stderr, "erro: could not close output_wav\n");
        return 1;
    }
    // ===========================

    return 0;
}

int readWriteStructs() {
    // a good application of previous knowledge

    struct assassin {
        char favorite_wep[20];
        char code_name[20];
        int assassinations;
        float cost;
    };
    // given a struct we can write down the members separately to a file
    // this is tedious to do manually, so we will write the entire struct at once.

    FILE* contracts = fopen("io-stuff/contract_data", "wb");
    int error;
    struct assassin a = {
        .assassinations = 9238,
        .code_name = "six",
        .cost = 890000.00,
        .favorite_wep = "golf club"
    };

    if (contracts == NULL) {
        fprintf(stderr, "coild not open contract_data file\n");
        return 1;
    }

    if (fwrite(&a, sizeof(struct assassin), 1, contracts) != 1) {
        fprintf(stderr, "could not write to contracts\n");
    }

    if (fclose(contracts) != 0) {
        fprintf(stderr, "could not close file contracts\n");
    }

    contracts = fopen("io-stuff/contract_data", "rb");
    if (contracts == NULL) {
        fprintf(stderr, "could not open file after writing it\n");
    }

    // remark: very important that we enter sizeof(struct assassin) instead of trying to manually compute it ourselves.
    // this is because it basically impossible to for sure know the size of the struct even if we know the size of all its members.
    // this is because C is allowed to insert space between the members of a struct!!
        // for eithering speeding up memory accesses or just required by machine.
    
    // now we will read the data into another struct!
    struct assassin b;
    // it is very easy to read from structs, same as writing them!

    if(fread(&b, sizeof(struct assassin), 1, contracts) != 1) {
        fprintf(stderr, "could not properly read from file\n");
    }

    printf("==new assassin stats==\ncode name: %s\nfavorite weapon: %s\nkills: %d\ncost: %f\n", b.code_name, b.favorite_wep, b.assassinations, b.cost);
    // get same stuff!!

    return 0;
}

struct assassin {
        char favorite_wep[20];
        char code_name[20];
        int assassinations;
        float cost;
};


void printAssassin(struct assassin* a) {
    printf("=== assassin ===\n");
    printf("name: %s\n", a->code_name);
    printf("kills: %d\n", a->assassinations);
    printf("weapon: %s\n", a->favorite_wep);
    printf("hire: $%f\n\n", a->cost);
}

int movingAroundInFiles() {
    // move around in files!!
    // note that each read and write call moves the fill position. we want to control this position.
    // a useful function for this is fseek():

    // int fseek(FILE* stream, long int offset, int whence);
        // offset indicates how much the file position should change (in BYTES!!)
        // whence determines how offset is interpreted, it applies to offset relative to a position.

        // whence value (constant)          meaning
        // SEEK_SET                         from beginning of file
        // SEEK_CUR                         from current position of file
        // SEEK_END                         from end of file

    // to move backwards, just use negative offsets.
    // this can be dangerous and prone to errors.
    // for example applying an offset greater than the file size itself will cause issues.
        // the fseek call doing this will succeed, but later read or write calls may fail
        // fseek itself will fail if we pass an invalid file pointer (just check to open)

    // failure for fseek is better cause before or after the fseek call, not during.
   
    // lets practice moving around in files by first writing a bunch of struct elements in a file.

    struct assassin a = {
        .favorite_wep = "golf club",
        .code_name = "Willius Billius",
        .cost = 0.02,
        .assassinations = 0
    };
    struct assassin b = {
        .favorite_wep = "broken sword",
        .code_name = "sword master",
        .cost = 9999999,
        .assassinations = 9999999
    };
    struct assassin c = {
        .favorite_wep = "firework",
        .code_name = "hamlet",
        .cost = 0,
        .assassinations = 40
    };
    struct assassin d = {
        .favorite_wep = "fork",
        .code_name = "jeff",
        .cost = 30,
        .assassinations = 10
    };
    struct assassin e = {
        .favorite_wep = "cat",
        .code_name = "six",
        .cost = 20000,
        .assassinations = 100000
    };

    // we will write 5 assassin structs into a file.
    struct assassin assassins[5] = {a, b, c, d, e};

    FILE* assassin_list = fopen("io-stuff/assassin_list", "wb");
    if (assassin_list == NULL) {
        fprintf(stderr, "could not open file assassin_list\n");
        return 1;
    }

    int writes = 0;
    for (int i = 0; i < 5; i++) {
        writes += fwrite(&(assassins[i]), sizeof(struct assassin), 1, assassin_list);
    }

    if (writes != 5) {
        fprintf(stderr, "could not write all assassin date to assassin_list\n");
        return 1;
    }

    if (fclose(assassin_list) != 0) {
        fprintf(stderr, "could not close assassin_list file\n");
        return 1;
    }

    // done writing process, just focus on the stuff below!

    
    assassin_list = fopen("io-stuff/assassin_list", "rb");
    int num;
    struct assassin read;

    fread(&read, sizeof(struct assassin), 1, assassin_list);
    printAssassin(&read);

    if (assassin_list == NULL) {
        fprintf(stderr, "could not open assassin_list for reading\n");
    }

    printf("Enter assassin number (1-5), or -1 to exit:\n");
    while (num != -1) {
        scanf("%d", &num);

        if (num != -1) {
            // here is the important part
            // notice that our offset value: num*sizeof(struct assassin). we offset by an amount of bytes!
            fseek(assassin_list, num * sizeof(struct assassin), SEEK_SET);
            if (fread(&read, sizeof(struct assassin), 1, assassin_list) != 1) {
                fprintf(stderr, "error reading assassin from list.\n");
            }
            printAssassin(&read);

            printf("Enter again:\n");
        }
    }

    if (fclose(assassin_list) != 0) {
        fprintf(stderr, "could not class assassin_list file after reading from it.");
    }

    // now consider this last question. why do fseek? why not just load ALL the assassins into an array, ie)
    // fread(assassin_array, sizeof(struct assassin), 5, assassin_list)

    // well we could have done that, but this quickly becomes very inefficient for large data sets.
    // imagine parsing a binary file containing 10000000000000 structs into an array. this takes up a lot of memory and time!
    // instead of doing that we could just fseek and find the struct we want (given an index).

    // one more thing for this section: 
    // we can use rewind() to move the beginning of the file instead of doing fseek.
        // could do this with fseek(stream, 0, SEEK_SET), but rewind() is simpler
    // void rewind(FILE* stream). only needs 1 parameter, the stream.
    return 0;
}


int everyIO() {
    // PROTOTYPES:
    // FILE* fopen(const char* path,const char* type)
        // returns a file pointer if successfully opened
    // int fclose(FILE* stream)
        // returns 0 if file successfully closed. returns E0F if file not closed (E0F is defined in stdio.h, usually as -1)
    // void printf(char* format, ...)
        // prints to stdin
    // int scanf(char* format, ...)
        // reads from stdin, returns number of items ... read
    // void fprintf(FILE* stream, char* format, ...)
        // same as printf but we choose stream
    // int fscanf(FILE* stream, char* format, ...)
        // same as scanf but we choose stream

    // char* fgets(char* s, int n, FILE* stream)
        // choose over fscanf if we want to store full lines of text together
        // returns s on success. n specifies number of characters to read. reads characters from stream and stores it into *s
    // size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream)
        // for low level reading. returns size_t which is basically unsigned integers, ie) no negative values.
    // size_t fwrite(void* ptr, size_t size, size_t nmemb, FILE* stream)

    // int fseek(FILE* stream, size_t offset, int whence)
        // SEEK_SET = 0
        // SEEK_CUR = 1
        // SEEK_END = 2
    return 0;
}

int stringsInC() {
    char text[6]; // can create a string with char array
    text[0] = 'h';
    text[1] = 'e';
    text[2] = 'l';
    text[3] = 'l';
    text[4] = 'o';

    
    printf(text); // this is not a good idea because the char array has no terminating string
    printf("\n"); // we might get a bunch of gibberish printed after it
    // we could add text[5] = '\0'; to make it work properly

    // only way to do the above "safely" without \0 is with a loop:

    for (int i = 0; i < 5; i++) {
        printf("%c", text[i]);
    } // this is safe, no risk of gibberish being printed
    printf("\n");

    // C STRINGS:
    // c strings are char arrays that have a "null character" 
        // else we dont consider it a string.
    // aka terminating character at the end of the array to signify that the string is done

    char Cstring1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", Cstring1);

    // note for something like the following:
    char Cstring2[20] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // note that the element at index 5 is \0
    // every element in the array after index 5 is set is set to \0 
    // so Cstring2 is {'h', 'e', 'l', 'l', 'o', '\0', '\0', '\0', '\0', '\0', '\0', '\0' ...} so on for 20 entries of \0

    // regular way to make strings
    char Cstring3[6] = "hello";
    // shorthand for doing the same as creating Cstring1

    // the following is not a legal string
    // char Cstring4[6] = "BABABABOEEEEEYYYYY AHHHHHHHH THIS STRING IS TOO LONG";
    // printf(Cstring4);
    // does not crash program, but only prints:BABABA + gibberish

    // there is short cut for creating string variables.
    // we do not need to specify the size like the following example shows
    char Cstring5[] = "Whats upppppppppp!";
    // in this case, C automatically passes an X inside [] where X is the length of the string + 1 for the null terminator
    // this helps cus we dont needa count every character when making strings.
    // also note this doesnt make the array a dynamically changing one or anything
    // the size will be fixed to whatever X was (X = str length + 1)

    // STRING LITERALS
    // not same as a string variable
    // string literals are string constants that cant be changed
    char* stringLiteral = "hello";
    // here we have a pointer to a string instead of a char array
    printf("%s\n", stringLiteral);

    // attempting to change the string literal will cause undefined behavior
        // stringLiteral[0] = 'c'; 
        // causes a seg fault

    // STRING LENGTH
    char weekday[10] = "Monday";
    printf("%lu\n", sizeof(weekday)); // this prints 10, not 6!
    // on an array, sizeof(arr) always gives the number of bytes occupied by the array arr
    // sizeof() is a compile time operation, and hence not useful for determining the length of a string or any array for that matter
    // unless the length is known at compile time.

    // we can use functions from the C standard library 
    // remember to do #incude <string.h> at top
    printf("%lu\n", strlen(weekday)); // strlen returns the length of the string excluding the null termination character.
    // prints 6 as needed
    
    
    // COPYING STRINGS

    // we can use the function strcpy, the prototype is as follows
    // char* strcpy(char* s1, const char* s2)
    //  strcpy() is known as an unsafe function.. will see how :)

    // copies the characters from string s2 into the beginning of the array s1
    // the stuff at the start of s1 gets overriden
    // whats weirder is that s1 isnt required to be a string when strcpy is called
    // however s2 is required to be a string: string literal or char array with null terminator

    char s1[40]; // note s1 is not a string because there is no null terminaton character
    char s2[14] = "University of";
    strcpy(s1, s2); // doesnt mutate stuff in s2
    printf("%s\n", s1);


    char s3[5];
    strcpy(s3, s2);
    printf("%s\n", s3); // since s3 doesnt have enough space for everything in s2
    // the case is undefined, depends on the compiler
    // this is why its unsafe, we cant rlly know or detect bugs on different machines

    // there are often safe counterparts to unsafe functions like these in the C standard library
    // safe versions often add an 'n' somewhere in the name of the unsafe ones
    // the n in the name indicates therre is a new n parameter in the function which will indicate
    // how much activity the function is allowed to do before it stops.

    // strncpy() is the safe counterpart to strcpy(). here is prototype:
    // char* strncpy(char* s1, const char* s2, int n)
    // same as strcpy(), but has n.
    // n indicates the max number of characters s1 can hold, and thus indicates the max number of characters to copy over INCLUDING NULL CHARACTER
    char x1[5];
    char x2[32] = "BARSSSSSSSSSS";
    strncpy(x1, x2, sizeof(x1));
    // this is also unsafe!! not guaranteed to add a null terminator unless we find one in the first n characters of x2!
    printf("%s\n", x1); // only enough characters to fill x1 are copied, but not a null terminator
    // will print some random stuff after first n characters of x2

    // so what we must do is explicitly add a null string after strncpy is called
    x1[4] = '\0';
    printf("%s\n", x1); // this works! prints BARS

    // CONCATENATING STRINGS
    char ss1[10] = "Mon";
    char ss2[10] = "day";
    // want to add them together
    // s3 = s1 + s2 wont work because it just sums the addresses together
    // we can use the function strcat()
    // char* strcat(char* s1, const char* s2)

    // strcat adds the characters from s2 to the end of string s1
    // both s1 and s2 must be strings prior to calling strcat.

    char q1[30];
    char q2[14] = "University of";
    char q3[15] = " C Programming";

    strncpy(q1, q2, sizeof(q1));
    strcat(q1, q3); // adds q3 to the end of q1
    printf("%s\n", q1); // prints good because we have enough space
    // just like strcpy(), strcat() is an unsafe function. 
    // q1 couldve had too little space for having everything from q3 appended to it
    
    // use strncat
    // char* strncat(char* s1, const char* s2, int n)
    // n indicates the max number of characters that should be copied over from s2
    // this value of n is excluding null terminator

    // important!! unlike strncpy, strncat always adds a null terminator to the end of s1 automatically!

    // safe way:
    strncpy(q1, q2, sizeof(q1));
    strncat(q1, q3, sizeof(q1) - strlen(q1) - 1);
    // we see that sizeof(q1) - strlen(q1) = space left in q1 for more characters,
    // then we also subtract 1 to ensure space for a null terminator. 


    // SEARCHING THROUGH STRINGS
    // std C library has several functions for this
    // one is: strchr, which searches for a single character inside a string
    // char* strchr(const char* s, int c)
    // s is the string to search, and c is the character to search for in the string provided as an ASCII code
    // strchr searches from left to right in the string.

    // strchr returns a pointer to the character that was found or NULL if it was not found.
    // so strchr doesnt return the index of the character in the string but rather returns the address to where that character is.

    char r1[30] = "University of C Programming";
    char* p;
    p = strchr(r1, 'v'); // p points to the address of v within r1
    // hence you could say p is a substring of r1
    printf("%s\n", p); // will print "versity of C Programming"
    // since p is the offset address of v in r1, we can use arithmetic to find the offset from s1 to p which represents the index.
    // offset = p - r1
    printf("index of the character v in r1 is %d\n", p-r1);
    // this works because each char is a byte

    // for searching for an entire substring within a string we use strstr()
    // char* s strstr(const char* s1, const char* s2)
    // strstr searches left to right in s1 for the first occurence of the substring s2
    // just like strchr, strstr returns a pointer to the first character which begins the match to the substring s2

    p = strstr(r1, "sity");
    if (p == NULL) {
        printf("substring not found");
    }
    else { // we end up finding it since sity is indeed in r1
        printf("substring found starting at index: %d\n", p-s1);
    }
    printf("substring is %s\n", p); // prints "sity of C Programming"

    return 0;
}


// we can typedef it as follows:
typedef struct node1 {
    int value;
    struct node1* next;
} Node;

Node* create_node(int num, Node* next) { // this is kind of reverse, instead returning a next node, we return a new node 
    Node* new_node = malloc(sizeof(Node)); // that is fed a next node for it as a parameter.
    new_node->next = next;
    new_node->value = num;
    return new_node;
}

int linkedStructures() {
    // linked lists etc
    // linked structure facts:
        // user-defined
        // requires a traverse() function to go over elements as opposed to the easy indexing of built in arrays
        // dynamic size as opposed to arrays' fixed size

    // linked lists consist of nodes
    // in C, we make nodes using structs
    struct node {
        int value;
        struct node* next; // points to the next node struct
    }; // same as python implementation of linked lists 


    // traversing linked lists.
    // we typically allocate nodes on the heap.
    // Node* front = malloc(sizeof(Node));
    // front->next = malloc(sizeof(Node));
    // since the nodes of a linked lists may be scattered , we do not readily know the memory offset to the i'th node like we would with arrays
    // hence we are forced to essentially follow a trail of nodes until we get to the i'th one we want.
    // whereas for arrays it is as simple as arr[i] = *(arr + i)
    
    Node* front = NULL;
    // we build it in reverse because of how create_node() is defined
    front = create_node(3, front); // set (3) to point to NULL, (3) -> NULL
    front = create_node(2, front); // set (2) to point to (3), (2) -> (3) -> NULL
    front = create_node(1, front); // set (1) to point to (2), (1) -> (2) -> (3) -> NULL

    // let us now iteratre through this linked list and print the values
    Node* curr = front;
    while (curr != NULL) {
        printf("%d\n", curr->value);
        curr = curr->next;
    }


    // INSERTING IN LINKED LISTS
    
    // linked list before insertion:
    void printLinky(Node*);
    printLinky(front);

    Node* insertLinked(Node* node, int val, int index);
    front = insertLinked(front, 9, 3);

    if (front == NULL) { // a little error catching
        fprintf(stderr, "Index Error\n");
    }
    else {
        printLinky(front);
    }

    return 0;
}

Node* insertLinked(Node* node, int val, int index) {
    if (index == 0) {
        Node* new = malloc(sizeof(Node));
        new->value = val;
        new->next = node;
        return new;
    }

    if (node == NULL) {
        return NULL;
    }

    node->next = insertLinked(node->next, val, index - 1);
    if (node->next == NULL) {
        return NULL;
    }
    return node;
}

void printLinky(Node* node) {
    Node* curr = node;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

int typedefInC() {
    // aliases for types.
    // two ways. 1.) typedef and 2.) macros

    // typedef allows alias for a type and is evaluated at compile time

    // macros allows to define a keyword that is replaced by a specified spring by preprorcessor before being compiled
    // will do macros in next function

    typedef unsigned int size_t;
    // recall how size_t has always been an unsigned int.

    // thiis is how it happens in stddef.h:
        // #define __SIZE_TYPE__ long unsigned int
        // typedef __SIZE_TYPE__ size_t;

    typedef int monkey;
    // monkey is an alias for integer type
    // typedef <existing_type> <alias_type>

    // typedef is particularly useful for aliasing structs

    struct student {
        char first_name[20];
        char last_name[20];
        int year;
        float gpa;
    };

    // everytime we want declar a struct student we need to call struct student every time. a lot to type
    struct student s;
    // even worse for pointers
    struct student* p;

    // so we can just typdef it:
    typedef struct student Student;
    // and we can do
    Student s2;
    Student* p2;

    // could also do it like this
    typedef struct blah {
        char blah[20];
    } Blah;

    // and we can even omit the initial name like this

    typedef struct {
        char BONG[20];
    } Bong;

    // tho oftentimes, we will still want the initial name.

    return 0;
}

int macrosInC() {
    // we can alias things other than types with macros
    // macros are very powerful in C, but we'll only go over replacing constant values and evaluating simple expressions.

    // we start macros with a #define
    #define MAX_NAME_LENGTH 40
    // we replace all occurences of MAX_NAME_LENGTH with 40. useful
    // macro language isnt C, we dont need an equal sign or semicolon

    // one might ask, why use this instead of global variables?
        // no memory allocation: macros are processed by preprocessor before compiling and do not consume memory at runtime. makes code more readable and maintainable without runtime overhead.
        // for example, having a bunch of global variables would increase runtime overhead by a lot.
        // global variables can be modified, macros cannot.

    // we can also make expressions with macros that are like little functions
    // except macros happen even BEFORE compilation, by the preprocessor. this makes macros much more efficient.
    #define WITH_TAX(x) ((x) * 1.13)
    // note: should not have any space between WITH_TAX and parameter (x).
    // also we must put x inside () each time we reference it in our expression. moreover, our entire expression should be inside ().
    // this is because () makes the expression evaluate.

    // if we dont put () around x when referencing it, it will substitute whatever is in x directly without any evaluations.

    printf("%f\n", WITH_TAX(100.0));

    // some further notes:
    // always use capital letters for macros or else it is bad styling
    // using macros can lead to difficult to debug errors.
    // to avoid errors put () around values u expect to be placed in expressions
    #define MY_INT (42)
    // not necessary to put () around the 42 for this cause because it is a single int, but its a good habit


    return 0;
}

int thePreprocessor() {
    // PREPROCESSOR DIRECTIVES
    // any line that begins with a # symbol is a preprocessor directive
    // these are used to modify C source code before it is compiled.

    // the following command executes the preprocessor on notes.c and outputs the preprocessed result in terminal
    // cpp notes.c 
    // the preprocessor transforms the code by executing all the directives and expanding all the macros
    // this creates a "stream of tokens" that are passed to the compiler's parser.
    
    #define MEANING_OF_LIFE (42)

    int x = MEANING_OF_LIFE; // this replaces with a STRING "42"
    // preprocessor doesnt care that 42 is an integer; just replaces text with text
    // preproccesor will even replace text that matches the macro that is in a comment.
    // for example, the following will be replaced by (42) by the preprocessor: MEANING_OF_LIFE
        // not sure how to show this, as using the preprocessor through cpp notes.c will just end up cleaning all comments.
        // the only occurences of macros the c preprocessor wont replace are those within "". so "MEANING_OF_LIFE" wont get replaced.

    // we can use macros within macros

    #define ANSWER (2 * MEANING_OF_LIFE)
     
    // preprocessor also includes several predefined macros
    printf("%d\n", __LINE__); // integer for line. will print 2587 (unless i changed the current line of this code)
    __FILE__; // name of the C source file
    __DATE__;
    __TIME__;
    // double underscores are a convention for system defined. __init__

    // some macros are defined by specific systems.
    // printf("Compiled on linux? %d\n", __APPLE__); // code produces an error for non mac

    // if we want to check macros that may potentially be undefined we can use conditional directive checks 
    
    #if __APPLE__
    const char OS_STR[] = "OS/X";
    #elif __gnu_linux__
    const char OS_STR[] = "gnu/linux";
    #elif __WIN32__ || _WIN32 || WIN32
    const char OS_STR[] = "win32";
    #elif __WIN64__ || _WIN64 || WIN64
    const char OS_STR[] = "win64";
    #elif __linux__
    const char OS_STR[] = "linux";
    #elif __unix__
    const char OS_STR[] = "unix";
    #else
    const char OS_STR[] = "unknown";
    #endif
    printf("1: Compiled on %s\n", OS_STR);

    // another way is to use ifdef

    #ifdef __APPLE__
    const char OS_STR2[] = "OS/X";
    #elif defined(__gnu_linux__)
    const char OS_STR2[] = "gnu/linux";
    #elif defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
    const char OS_STR2[] = "win32";
    #elif defined(__WIN64__) || defined(_WIN64) || defined(WIN64)
    const char OS_STR2[] = "win64";
    #elif defined(__linux__)
    const char OS_STR2[] = "linux";
    #elif defined(__unix__)
    const char OS_STR2[] = "unix";
    #else
    const char OS_STR2[] = "unknown";
    #endif
    printf("2: Compiled on %s\n", OS_STR2);

    // this is extremely helpful for determining the system the source code is being compiled on

    // defining macros from command line before compiling into an executable:
    // use -D flag (stands for define im guessing)
        // gcc -D DEBUG=3 notes.c -o notes
    // the above defines a macro DEBUG and gives it a value 3
    // if we omit the =3, the default value given to DEBUG is 1
        // gcc -D DEBUG notes.c -o notes
    
    // this way, we can also use macros for debugging
    #ifdef DEBUG
    printf("Running in debug mode at level %d\n", DEBUG);
    #endif
    // combining this technique with a build system like Make, this allows us to easily reconfigure systems for debugging

    // be careful. macros can be abused!
    // preprocessor directives can usually be replaced with just C language like global variables etc. but one thing we need them for always including header files.

    // lastly, recall guarding header files.
    // let us show an example first where the same header file code be accidentally copied twice

    // file1.c:
    // #include "sorts.h"
    // #include "sorts2.h"

    // sorts2.h
    // #include "sorts.h"

    // we see in file1.c, we include sorts.h and sorts2.h, and when we do this everything in sorts2.h basically gets copied over by the preprocessor.
    // hence, we end up with two includes for include sorts.h as there was one in sorts2.h as well.
    // to avoid this we must use header guards (see line 1167 or just word search it)

    // sorts 2.
    // if

    return 0;
}

int functionLikeMacros(){
    // many of the features in this section are SYSTEM SPECIFIC
    // also remark: using function like macros is rarely a good idea. recommended to avoid using.

    #define PAGE_PRESENT  0
    #define PAGE_PROT     1
    #define PAGE_RW       2
    #define PAGE_USER     3
    #define PAGE_DIRTY    4
    #define PAGE_ACCESSED 5
    // macros with simple values like integers dont need () wrapped around them

    #define SET(var, flag) ((var) |= 1 << (flag))
    // we SLLI 1 by (flag), so if flag is 3, then 1000 is whaht we get (shifted 1 by 3 binary digits)
    // then we do a bitwise OR on var and set it equal to it, |= like +=.

    int page_flag = 0;
    SET(page_flag, PAGE_USER);
    // we see that the macro changed the value of page_flag, unlike a function that wouldn't have done this
    // this is because the macro literally just gets added into the code by the preprocessor, it doesnt create a stack.

        // SET(page_flag, PAGE_USER);
        // expands to
        // ((page_flag) |= 1 << (3))

    // note that PAGE_USER gets expanded to 3.

    printf("PAGE_FLAG VALUE IS: %d\n", page_flag); // we get 8, since 8 = 1000 (slli it by 3 which is PAGE_USER)

    // more comlex

    #define WARN(cond) \
        do { \
            if (cond) fprintf(stderr, "Warning (%s:%d): %s\n", __FILE__, __LINE__, #cond); \
        } while (0)
    // note the do while(0) loop just runs 1 single iteration
    // this is common defensive coding practice to avoid issues related to macro expansion in complex code structions
    // this allows us to include multiple statements
  
    // also enforces the requirement that the warn macro is used a statement
    // for example, the following does not have ; at the end unlike our WARN which does
    #define WARN2(cond) if (cond) fprintf(stderr, "BARS??")
    // the compiler is fine with this not having a ;, but this can lead to errors during runtime.'
    // on the other hand, if we try removing the ; from our inside our do-while, we see we can a compile time error, the compiler complains.
    // theres more to it probably.

    // also note that # on #cond. this is the STRINGIFICATION operator. it preserves the argument as a string.

    // note that the backslashes \, signal that the macro continues over to the next line
    // this lets us create macros that span multiple lines.
    // in a way, this allows us to create "nested functions" since we cannot do that in C with regular functions. but still, this is rarely a good idea to do.

    #define ISSET(var, flag) ((var) & (1 << (flag)))
    // returns the bitwise operation of var with the bitmask 1 << flag
    // note the bitmask will have all zeroes except for the at the "binary place" (flag + 1), eg 1 << (3) = 1000. we have 1 in the 4th binary place
    // so var & (1 << flag) will only evaluate to true if var has a 1 at the (flag + 1) binary place.
    // in other words ISSET() checks if the binary value at the (flag + 1) decimal place IS SET to 1. (the SET function basically ensures this, it sets it to 1)

    page_flag = 0;
    SET(page_flag, PAGE_USER);
    WARN(ISSET(page_flag, PAGE_USER));

    // now we will give examples why macros are bad to use

    #define GREATER(a, b) ((a) > (b) ? (a) : (b))
    // remember ternary operator:
    // (condition) ? (expression_if_true) : (expression_if_false)

    int x = 2;
    int y = 1;
    
    y ++;

    printf("%d\n", GREATER(x, y)); // this prints 2 as expected

    y = 1;
    printf("%d\n", GREATER(x, ++y)); // prints 3
    // preprocessor takes it in like this:
    // ((x) > (++y) ? (x) : (++y))
    // and this makes the ++y happen twice.
    // this is why its risky to use macros. a function wouldnt do this.
    // we cant expect the macro the act like a function

    // now we show issues with nesting macros
    // the following works fine
    page_flag = 0;
    printf("%d\n", SET(page_flag, PAGE_DIRTY));

    // just like how this works
    page_flag = 0;
    printf("%d\n", page_flag += 16);

    // note that this works
    page_flag = 0;
    SET(page_flag, PAGE_USER);
    SET(page_flag, PAGE_DIRTY);

    // but trying to combine the step like this doesnt work:
    page_flag = 0;
    // SET(SET(page_flag, PAGE_USER), PAGE_DIRTY);  
    // we get a compiler error. uncomment and see ur IDE complain.
    // this is because in C, we cannot assign to expressions
    x = 0;
    // cannot assign expression to a value
    // (x += 1) = 2;
    // same for java

    // so why use macros ?
    // just dont unless u want to just have global constant data like simple integers.
    
    // some arguments to why macros are good:
        // removes function call overhead
        // counter argument: just use inline keyword on functions
        // inline int add(int a, int b) {}

        // macros are type neutral
        // counter argument: thats also a weakness
    
    // INLINE KEYWORD
    // a quick intro to the inline keyword
    // suggests the compiler to perform inlining for a function.
    // inlining is a compiler optimization  where the compiler replaces a function call with the actual body of the function at the call site.
    // important to note that this isn't like macros, ie; we still create a stack frame for the function call as normal.
    // only removes overhead cost of function calls.

    // FUNCTION OVERHEAD COST
    // refers to additional work and resources consumed when functions are invoked
    // includes:
        // pushing and popping parameters onto and from stacks
        // managing return address
        // setting up and tearing down a new stack frame

    // when a function is inlined, the overhead from pushing and popping parameters is eliminated.

    // key take away:
    // almost anything that can be done with defines can be done with C directly. just use C.
    // useful to be able to read macros bc legacy code uses them.

    return 0;
}

int functionPointers(){
    // we do not need to differentiate between data and functions
    // we can capture functions in variables! we do this with function pointers.
    // i comment a lot of stuff out here cus i use imported functions which needs a combined compile with sorting.c

    // motivation: consider that we have some several different functions with same signature
    int arr[10] = {91, 22, 11, 14, 0, 2, 2, 91, -3, 7};
    // insertion_sort(arr, 10); //  works fine as long as we compile sorting.c with it
    // print_array(arr, 10);

    int arr2[10] = {91, 22, 11, 14, 0, 2, 2, 91, -3, 7};
    // bubble_sort(arr2, 10); 
    // print_array(arr2, 10);

    // now say we want to change all of the bubble_sort calls to insertion_sort calls or vice versa.
    // we would need to change every line of code where the function was being called and change it.
    // what if we could just capture the function being used in a variable and just use that over and over again.
    // that way we would only need to change one variable; simple concept.

    // we can do this using function pointers!
    void (*ptr)(int*, int);
    // since all the functions have the same signature we can do any of the following:
    // ptr = selection_sort;
    // ptr = bubble_sort;
    // ptr = insertion_sort;

    // we can now simply call the function like this
    // ptr(arr2, 10);
    // print_array(arr2, 10);

    // this adds an insane amount of flexibility.
    // we can now freely pass functions as parameters
    // just need proper type, for example
        // void funcx(void (*sort_func)(int*, int)) {}
    // just pass in a function as the arg into funcx.

    // just like an array variable is treated as a pointer to its first element,
    // a function pointer is treated like a pointer to that function

    // note that functions and any code in general is stored in the code segment area in the memory model
    // hence function pointers point to memory in code segment where the function is (i think).

    // FUNCTIONS THAT RETURN FUNCTION POINTERS
    // the syntax can get really ugly from this one
    // supposed i have a function point of the following type:
    void (*f_ptr)(int*, int);
    // now supposed i have a function func_x() which takes some args (int argc, int argv[]),
    // and returns void (*f_ptr)(int*, int) that type

    // to do this it gets rlly messy. 
    // must make it like this:
    // void (*funcx(int argc, int argv[]))(int*, int) {}
        // see the example below after this section

    // basically it is just void (*f_ptr)(int*, int), but we add (int argc, int argv[]) after f_ptr, 
    // so we make it f_ptr(int argc, int argv[]) and add all the other stuff as well.

    // but we can make this a lot more clean just using typedef

    typedef (*sort_func)(int*, int); 
    // now sort_func is a type for stuff like f_ptr
    // we can just do what we are familiar with now:
    // sort_funcy funcy(int argc, int argv[]) {}
    // a lot cleaner now.

    return 0;
}

void (*funcx(int argc, int argv[]))(int*, int) {}

typedef (*sort_funcy)(int*, int); 
sort_funcy funcy(int argc, int argv[]) {}

int systemCalls() {
    // a system call is a a function that requests a service from the OS
    // for example exit(). requests OS to terminate program

    // more examples are low level IO calls.
    // high level IO functions like scanf and printf are not system calls.
    // they are library functions instead, that use low level IO functions which are system calls.
    // library functions:
        // fgets
        // fopen
        // fclose
        // scanf
        // printf
    
    // system calls
        // write
        // read
        // exit

    return 0;
}

int errorsAndErrno() {
    // when system calls dont work correctly
    
    // system calls or library functions that use system calls return certain values if error occurs
    // ones that return int type will return -1 to indicate error
    // ones that return pointer type will return NULL to indicate error

    // we would also like to know what kind of error occured
    // the return value does not suffice for this; it just tells us if an error occurs, not what kind
    // we get around this using errno

    // errno
    // we use a global variable known as ERRNO, which stores the kind of error that occured
    // it has a type of int.
    // the integer value of ERRNO correponds with different errors as specified by errno.h header file
    errno;
    #include <errno.h>
    // we can ctrl click errno.h to see all these errors.

    // however we dont need to memorize this mapping.
    // we have functions that explain error codes for us.
    // one such function is perror:
    // void perror(const char* s);

    // we can put a custom string s in perror, and it will print that error message along with our error it parses from errno:
    // perror("error");
    // output: error: <errno_parsed_error>
    
    // for example
    FILE* x = fopen("BARSS", "r");
    if (x == NULL) {
        perror("error opening file");
    }
    // this will print:
    // error opening file: No such file or directory

    // when no errors occur, perror will just print "<your_stuff>: Undefined error: 0"

    return 0;
}


int processModels() {
    // what does it mean to run a program?
    // define a program, processes, and understand how an OS works with them.

    // program:
        // the executable instructions of a program, either source code or compiled machine code.

    // process:
        // running instance of a program
        // a process includes the machine code of the program + info about the current state of the process, ie) what to step to execute next
        
    // when a program is loaded into memory, it is loaded into a contiguous piece
    // the contiguous piece is the memory model we are familiar with:
        
        // 0 (buffer area)
        // code
        // global data
        // heap
        // empty (file buffer)
        // stack
        // OS

    // the OS keeps track of additional info for a process
        // PID: process ID
            // just the ID of the running process
        // PC: program counter
            // points to next instruction to be executed in code
        // SP: stack pointer
            // points to top of stack 

    // these are all stored in the PCB: process control block.
    // the process control block stores the current value of important registers.
    // enter top in bash to see all the processes running

    // number of active proccesses is much larger than the number of processes executing instructions at an instance of time
        // an active process is in the RUNNING, READY, or BLOCKED state
        // all processes have owners.
    // the number of processors, aka CPUs determines how many processes can execute an instruction at the same time.
        // eg) if a computer has 4 CPUs, then 4 processes can be running simultaneously
        // we say those processes are in the "running state"
        // processes that are waiting to be executed as soon as a CPU is available are in the "ready state"
        // other processes may be waiting for an event to occur, these processes are in a sleeping state / blocked state

    // the OS gives an illusion of running hundreds of processes simultaneously by switching between the ready and running processes very quickly.
    // the OS scheduler is responsible for deciding which processes to execute and when.

    // knowing about how the OS schedules processes and when it blocks them helps when we write programs that create or manage cooperating processes. 

    return 0;
}

int creatingProcesses() {
    // use fork system call (on Windows is CreateProcess())
    // creating a process requires a system call because the OS needs to set up process data structures such as the control block.

    // when a process calls fork, it passes control to the OS
    // calling fork duplicates said process
    // a new process will be created with everything exactly the same (almost)
    // the new process will have a different PID however, and the return value of fork is different
    // we say the original process is the parent and the newly created process is the child

    // child process starts executing just after fork returns`
    // however, we cant say whether the parent process or child process will begin executing first
        // when OS is finished creating new process, control can be returned to either parent or child process.
    
    // example

    int i;
    pid_t result; // include <sys/types.h> at top

    i = 5;
    printf("%d\n", i);
    result = fork(); // fork!! need include <unistd.h> for it
    // child process created
    // child process begins executing from here, right after fork() returns
    
    // in the parent process, as it continues to run, the return value of fork() is the child process' PID, which is some positive integer
    // in the child process, the return value of fork just gives 0
    // if fork fails, then the return value of fork in parent is -1, and a new process is not created
    // fork could fail if there are already too many running processes for user or across the entire system.

    if (result > 0) { // parent process follows this path
        i = i + 2;
    }

    else if (result == 0) { // child process follows this path
        i = i - 2;
    }

    else { // else there was an error and child process wasnt created
        perror("fork");
    }

    printf("ya %d\n", i); // we see we get two prints, ya 7 and ya 3
    // we cant determine their order. ya 7 corresponds to parent's diverged process and ya 3 corresponds to child's diverged process
    // remember that the child and parent processes are 2 separate processes, and dont share memory
    return 0;
}

int relationshipOfProcesses() {

    // cant be bothered to explain all this, just run it from main() and see cool stuff

    int result;
    int i, j;

    printf("[%d] original process.  (my parent is %d)\n", getpid(), getppid());

    for (i = 0; i < 5; i++) {
        result = fork();

        if (result == -1) {
            perror("fork:");
            exit(1); // whats the diff between this and return - 1 ??
        }

        else if (result == 0) { // child process
            for (j = 0; j < 5; j++) {
                printf("[%d] Child %d %d\n", getpid(), i, j);
                usleep(100); // usleep slows down processes
            }
            exit(0); // children exit before continuing loop, else we would get grandchildren etc.
        }
    }

    printf("[%d] Parent about to terminate\n", getpid());

    // we get something like:
    // >$ ./notes
    // started main
    // [2258] original process.  (my parent is 374)
    // [2259] Child 0 0
    // [2260] Child 1 0
    // [2261] Child 2 0
    // [2262] Child 3 0
    // [2258] Parent about to terminate
    // [2263] Child 4 0
    // [2259] Child 0 1
    // [2261] Child 2 1
    // [2260] Child 1 1
    // [2262] Child 3 1
    // [2263] Child 4 1
    // >$ [2259] Child 0 2
    // [2261] Child 2 2
    // [2260] Child 1 2
    // [2262] Child 3 2
    // [2263] Child 4 2
    // [2259] Child 0 3
    // [2261] Child 2 3
    // [2260] Child 1 3
    // [2262] Child 3 3
    // [2263] Child 4 3
    // [2259] Child 0 4
    // [2261] Child 2 4
    // [2260] Child 1 4
    // [2262] Child 3 4
    // [2263] Child 4 4

    // note that the parent terminates before children have printed their first message
    // parent process has no reason to wait for its children to finish executing; they are all equal in the eyes of the OS !!
    // also it looks like the program hasnt finished running but it actually has. the >$ just comes early and more stuff get printed after it,
    // so it looks like the processes are still running because the shell doesnt recreate the >$ after all the prints since it already made it before
    // just type anything in and it works!!
    
    return 0;
}

int relationBetweenShellAndProcesses() {
    // relation between the shell and the processes it spawns
    // can use the wait() system call to force the parent process to wait until its children have been terminated. prototype is:
    // pid_t wait(int* state_loc)
    // wait() returns the process ID of the terminated child on success, else returns -1

    // STAT_LOC ARGUMENT
        // information about how the child terminated; ie terminates with error or terminates cleanly, is stored in the integer value of the stat_loc argument.
        // after a child process terminates, the exit status is stored in the stat_loc arguement (value returned on termination) 
        // this value is NOT necessarily equivalent to to the return value on termination
        // various bits in the state_loc argument are used for different purposes! it is complex.
        // for example, lowest 8 bits tell us whether the process terminated normally or whether it terminated because it received a signal.
        // for example, ctrl+C is a signaled termination.
        // if the process terminated due to a signal, the lower 8 bits tell us which signal.
        // the return value of the process is in the next 8 bits.
        // examples of this can be found below at line 2690.


    // must call wait for each child that was created to wait for all of the child processes:

    // here is the code modified from before:

    int result;
    int i, j;

    printf("[%d] original process.  (my parent is %d)\n", getpid(), getppid());

    for (i = 0; i < 5; i++) {
        result = fork();

        if (result == -1) {
            perror("fork:");
            exit(1); // whats the diff between this and return - 1 ??
        }

        else if (result == 0) { // child process
            for (j = 0; j < 5; j++) {
                printf("[%d] Child %d %d\n", getpid(), i, j);
                usleep(100); // usleep slows down processes
            }
            exit(i); // children exit before continuing loop, else we would get grandchildren etc.
        } // make each child exit with its own unique status value i. cant be return i, should be exit(i)
    }

    // modification: now wait for the children:
    for (i = 0; i < 5; i++) { // we call wait() 5 times, once for every child
        pid_t pid;
        int status;
        if ( (pid = wait(&status)) == -1 ) { // error
            perror("wait");
        }
        else {
            printf("Child %d terminated with %d\n", pid, status);
        }
    }
    printf("[%d] Parent about to terminate\n", getpid());
    
    // now everything terminates at the end:
        // Child 1118 terminated with 0
        // Child 1119 terminated with 256
        // Child 1120 terminated with 512
        // Child 1121 terminated with 768
        // Child 1122 terminated with 1024
        // [1117] Parent about to terminate
    
    // note that the parent terminates last.
    // recall, the lower 8 bits tell us what signal the process was ended by (in all of our processes, there was no signal so its al 00000000). 
    // the next 8 bits give us the return value. so for child 0 we have, 0000 0000 0000 0000
    // for child 1, 0000 0001 0000 0000 = 2^8 = 256 since the return value was 1
    // for child 2, 0000 0010 0000 0000 = 2^9 = 512 since the return value was 2
    // for child 3, 0000 0011 0000 0000 = 2^8 + 2^9 = 256 + 512 = 768 since the return value was 3
    // for child 4, 0000 0100 0000 0000 = 2^10 = 1024 since return value was 4
        // for each child, focus on the upper 8 bits, and notice that they are just 1, 2, 3, 4 in binary for each child respectively.

    // the man page for wait gives us info about how to extract specific data from the stat_loc argument using MACROS.
        // macros are stuff like #define PI 3.14159. these are not stored in global data / heap / stack, they are stored in code area of memory model.
        // when we use a macro in our source code, the preprocessor replaces instances of the macro with its definition before the compiler begins compiling assembly code and object code.

    // so we dont rlly need to know how to bits themselvess are arranged, just used the macros to correctly extract data.
    // will show how to use macros in next function

    return 0;
}

int usingMacrosForStat_loc() {
    int result;
    int i, j;

    printf("[%d] original process.  (my parent is %d)\n", getpid(), getppid());

    for (i = 0; i < 5; i++) {
        result = fork();

        if (result == -1) {
            perror("fork:");
            exit(1); 
        }

        else if (result == 0) { 
            for (j = 0; j < 5; j++) {
                printf("[%d] Child %d %d\n", getpid(), i, j);
                usleep(100); 
            }

            if (i == 2) { // force child 2 to abort abnormally. produces a signaled termination with exit value 6
                abort();
            }
            exit(i); 
        } 
    }

    for (i = 0; i < 5; i++) {
        pid_t pid;
        int status;
        if ( (pid = wait(&status)) == -1 ) { 
            perror("wait");
        }
        else {
            if (WIFEXITED(status)) { // WIFEXITED, read as W: if exited. returns true if the process exited normally (not signalled)
                printf("Child %d terminated with %d\n", pid, WEXITSTATUS(status));  //WEXITSTATUS, read as W: exit status. returns the exit status program terminated with. so with return 0, 1, 2, 3, 4.
            } else if (WIFSIGNALED(status)) { // WIFSIGNALED, read as W: if signaled. returns true if the process ended from a signal.
                printf("Child %d terminated with a signal %d\n", pid, WTERMSIG(status)); // WTERMSIG, read as W: termination signal. returns the signal's status the program terminated with
            } else {
                perror("abnormal exit: neither signaled nor normal termination");
            }
        }
    }
    printf("[%d] Parent about to terminate\n", getpid());

    // note that when we are waiting for child processes, we are just calling wait() 5 times abritrarily. if we want to specify the child to wait for we can use:
        // pid_t waitpid(pid_t pid, int* stat_loc, int options)

    // note that our wait() and waitpid() functions block the calling process until wait() returns the value, ie) until the child process terminates.
    // if we dont want a block like this, we can use WNOHANG in waitpid().
        // WNOHANG option can be passed to waitpid as an argument for the options parameter.
        // WNOHANG disables the calling process from being blocked. this is used when the parent process just wants to check if a child has terminated but not block code execution.
        // in the case that the child process has not yet terminated, WNOHANG will return 0. 
        // so basically use WNOHANG in waitpid() if you just want to check if a child process has terminated at the given time and not wait for it to actually finish terminating.

    // note that both wait() and waitpid() are limited to only a process' child functions. we cannot use wait() or waitpid() to wait for any other processes aside from direct children. so no grandchildren either.
    return 0;
}

int zombieAndOrphanProcesses() {
    // recall processes can only wait for its direct children
    
    // what happens if a child process terminates before a parent calls wait?

    // ZOMBIE
    // any child process that has already terminated while it's parent process has not is called a zombie.
    // this is because even though the child has exited, the OS needs to keep the exit info of the process somewhere, in case parent calls wait() to get this value
    // so the OS cant delete the process control block of the terminated child process until it knows it is safe to clean it up.
    // so a zombie process is a process that is dead but is still hanging around to collect its termination status.

    // PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                                                                                                                                                                       
    // 342 root      20   0 1115092  87804  27652 S   0.3   0.6   0:13.00 python3.10
    //   1 root      20   0  165852  11212   8232 S   0.0   0.1   0:00.41 systemd
    //   2 root      20   0    2456   1348   1232 S   0.0   0.0   0:00.02 init-systemd(Ub
    //   5 root      20   0    2456      4      0 S   0.0   0.0   0:00.00 init
    //  34 root      19  -1   47808  15480  14444 S   0.0   0.1   0:00.12 systemd-journal
    //  52 root      20   0   21960   5856   4472 S   0.0   0.0   0:00.24 systemd-udevd
    // 920 root      20   0   2260   58562   4472 Z   0.0   0.0   0:00.00 zombie <defunct>

    // note that "zombie <defunct>" in the last row. also note the Z under S in the last row. the S (at top of column) stands for state, and Z stands for zombie. 

    // ORPHANS
    // what happens to a child process when its parent terminates first?
    // we call such a process an orphan.
    // the parent of an orphan process just becomes 1. this is the init process.
    // so called getppid() from an orphan process just returns 1. so the parent process becomes the init process.
    // when a process becomes an orphan it is adopted by the init process.

    // INIT PROCESS
    // the first process that OS launches is the init process
    // the primary job of the init process is to call wait() continuously in a loop, to collect the termination status of any adopted processes.


    // what happens if the parent never calls wait()? why dont we have a clutter of hundreds of zombie processes in the process table? 
    // zombies are cleared once their parent also terminates (assuming wait() is never called by the parent process).
    // zombies will become adopted by the init process once their parent process terminates (ie the zombie becomes an orphan).
    // when this happens, wait() will finally be called from the new parent of the zombie which is the init process.
    // thus, the zombie processes will be freed.

    return 0;
}

int runningDifferentPrograms() {
    // so far we have been duplicated the same program as a child process with wait() calls
    // but we can run a different program entirely using exec()
    // exec() replaces the currently running processes with a different executable.
    // there are several variants of the exec() function.

    // execl() is one version of the exec
    // int execl(const char* path, const char* arg0, ...  NULL);
    // note last arg must be NULL which indicates teh end of the arugment list
    // the ... consists of the remaining arguments to the command line executable 
    // arg0 should specify the name of the program itself, ie the first argument passed into argv[].

    // when the process calls execl, control is passed to the OS

    printf("in notes : my PID is %d\n", getpid());
    execl("./main", "main", NULL); // the called process will have same PID

    // this code is unreachable if execl() is called successfully. this is because execl() will not jump back.
    perror("exec"); // however, if an error occurs then this code will be executed.
    return 1;

    // more versions of exec, 6 in total.

    // int execl(const char* path, const char* arg0, ... NULL)
    // int execlp(const char* file, const char* arg0, ... NULL)
    // int execle(const char* path, const char* arg, ... NULL???, char* const envp[])

    // int execv(const char* path, const char* arg0, char* const argv[])
    // int execvp(const char* file, const char* arg0, char* const argv[])
    // int execvpe(const char* file, const char* arg0, char* const argv[], char* const envp[])


    // the l's (first three) expect a list of command line arguments to be passed into the called program
    // the v's expect a vector, ie) an array of command line arguments instead of a list
    // p stands for path, which means the path environment variable is searched to find the executable
        // the executable is just given as the file name, not the full path.
        // without the p, exec will expect that the full path is given as the first argument rather than just the file name
    // e stands for environment. you can pass in an array of environment variables and their values
        // so the program executes within a specific environment.


    // execvp and execlp are used most often.

    // SHELL CONNECTING TO C CODE:
    // this entire logic explains how the shell executes the our executable c code files.
    // the shell is just a process, and it uses fork() and exec(). 

    // how the shell runs c code:
        // first the shell calls fork() to dupelicate itself as a process
        // then that child processes calls exec() to load a different program into its memory
        // the parent shell process then calls wait() and blocks until the child process finishes
        // when wait() call returns, shell prints the >$ to indicate it is ready to receive the next command

    // pretty cool. so it basically dupelicates itself, then the clone (child) morphs itself (using exec) into a different program; our c executable.
}

int signalsInC() {
    // some examples of signals: 
        // CTRL + C: ends program
        // CTRL + Z: pauses program (type fg to wake it up)
        // Segmentation Fault: a signal sent by the OS to the process, terminates the process

    // in general: signals are a mechanism that allow a process or the OS to interrupt a currently running process and notify it that an event has occured.

    // how signals work?
    // each signal is identified by a number between 1 and 31.
    // type man 7 signal to see list of signals 
    // eg: SIGINT has a integer value of 2 and it is the signal sent when we type ctrl + c in temrinal, which interrupts program.
    // ctrl + z sends SIGSTOP: has value of 17

    // how do we send arbitrary signals to the process?
    // can use a library function called kill() or from command line using a program also called kill

    // USING KILL FROM TERMINAL:
    // to send arbitrary signals to a process from terminal using kill, must know the PID of the process
    // type:
        // kill -<signal_name> <PID>
    // eg:
        // kill -STOP 3819
        // kill -INT 3819

    // note we didnt type SIGSTOP, just STOP.
    // can also type in the numbers directory

    // library function kill uses the same idea.
        // kill(pid_t pid, int sig);
    // pid is the process id to send the signal to and sig is the integer value of the signal we want to send.
    // recall we can get pid's of children from return value of fork()

    // note, kill() requires signal.h

    return 0;
}

int handlingSignals() {
    // change default behaviour of signal, eg:
        // print a msg
        // save some state
        // ignore signal 

    // we can write a function to be executed when the signal is received by the process
    // how does this function get called?

    // well lets consider what happens when a process receives a signal.
    // the PCB (process control block) has a signal table which similiar to the open file table
    // each entry in the signal table contains a pointer to code that will be executed when the OS delivers the signal to the process
    // this is known as the signal handling function
    
    // we can change the behaviour of a signal by installing a new signal handling function
    // the sigaction() system call will modify the signal table so that our function is called instead of the default function.

        // int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact);

        // signum is the signal being modifed.
        // act is a pointer to a struct that we need to initialize ourselves before we call sigaction
        // oldact is a pointer to a struct that will hold the previous state of the signal after sigaction is called (we dont initialize this)

    // we wont use oldact arg in our examples, but it sometimes helps to save the previous state of the signals.

    // sigaction struct: (getting an error when i uncomment not sure why)

    // struct sigaction {
    //     void (*sa_handler)(int);
    //     void (*sa_sigaction)(int, siginfo_t*, void*);
    //     sigset_t sa_mask;
    //     int sa_flags;
    //     void (*sa_restorer)(void);
    // };


    // void handler(int code);
    // void (*f_ptr)(int) = &handler;

    // struct sigaction newact;
    // newact.sa_handler = f_ptr;
    // newact.sa_flags = 0; // default flags
    // sigemptyset(&newact.sa_mask); // set sa_mask to empty so no signals are blocked during handler
    // // newact is set up at this point.

    // sigaction(SIGINT, &newact, NULL); // call sigaction system call to install our new handler for the SIGINT signal.


    // for some reason the code above is producing errors when i compile it.. will investigate later.
    
    // remark:
    // two signals cant be changed with sigaction: SIGKILL and SIGSTOP. 
    // SIGKILL will always cause process to terminate and SIGSTOP will always suspend the process.

    return 0;
}

void handler(int code) { // our handler for signal 
    fprintf(stderr, "Signal %d caught\n", code);
}