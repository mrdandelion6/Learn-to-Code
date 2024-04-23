// C Notes
// i apologize for using camel case everywhere.. i have been coding in javascript for a week nonstop

// std stands for standard library, io for the input/output, and .h to signify header code
#include <stdio.h> // for scanf and printf
#include <stdlib.h>
#include <stdbool.h> // for using bool types. though in C, we just use (1) for true and (0) for false
#include <string.h>
#include <time.h>
#define DAYS 365 
#include "sorting.h"
#include <sys/types.h> 

// these libraries are for forking processes
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/socket.h> // this is specific to unix OS. run ur IDE/text-editor through WSL if ur on windows
#include <netinet/in.h>

#include <sys/select.h>

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
    int compilingWithUnix();
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
    int bitwiseOperations();
    int bitShiftLogic();
    int bitFlags();
    int bitArrays();
    int unbufferedIO();
    int pipesInC();
    int concurrencyAndPipes();
    int redirectingInputAndOutputDup2();
    int implementingShellPipeOperator();
    int introToSockets();
    int socketConfiguration();
    int socketCommunication();
    int socketCommunication2();
    int issueWithBlockingRead();
    int usingSelectForReading();
    int unknown_array_iteration();
    unknown_array_iteration();

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
    printf("integers on this device are %zu bytes\n", sizeof(int));
    printf("longs on this device are %zu bytes\n", sizeof(long));
    printf("long longs on this device are %zu bytes\n", sizeof(long long));
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

int compilingWithUnix() {
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

bool bool_test() {
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
    int length = 10;
    // variables count and ages are declared and initialized in hidden code.
    
    int ages[10] = {11, 5, 2, 9, 4, 12, 10, 8, 10, 13};
    int i;
    int secondOldest = 0;
    int oldest = 0;
    for (i = 0; i < length; i++) {
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
    int* pt; // so this means pt is a pointer variable that holds the address of an integer
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
    char* ch_pt = &ch;

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
    int* pt1 = q; // we are not assigning *pt = q, rather we are assigning pt = q. int * is just the declaration for pt.
    int * pt2 = q; // the space can be like this
    int *pt3 = q; // or like this; it doesnt matter

    // it is standard to see it like this:
    int *ptr;

    // but i like to make it like this:
    int* ptr2;

    int* p1, p2; // this is a common mistake. p1 is a pointer, p2 is an integer

    // proper way to declare two pointers:
    int *p3, *p4;

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

int print_iter(void* arr, int len, size_t elem_size) { // function for iterating an array of unknown type and printing elements

    // even if we know the size of each element, and the length of the array, we still dont know the type of the elements
    // we wont be able to print them out without knowing the type of the elements
    // we can still do it, but we need to pass in a function that knows how to print the elements

    for (int i = 0; i < len; i++) {
        printf("elem %d is %d\n", i, ((char*) arr)[i * elem_size]);
    } // in this case we're just assuming the elements are integers
}


int unknown_array_iteration() {


    return 0;
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

    for (int i = 0; i < A_size; i++) { // bars
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


    int* g2();
    // a function returning int*

    int (*f2)();
    // a pointer to a function returning int

    int (*f3(int x))[10];
    // a pointer to a function that takes in an argument integer and returns an array of 10 integers

    int* (*f4[10])();
    // an array of 10 pointers to functions that return pointers to integers

    // use the spiral reading trick:
    // start from the variable name and move right then left, then right, then left, etc.

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
    // conversely.. (continue about this below this function)

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
        // here we create an object file from $< which symbolizes the first name in the list of dependencies, ie; $.c
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
    // FILE* fopen(const char* path, const char* type)
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
        // ptr is address where read data is stored. size specifies the size of each element to reach in the file. nmemb specifies number of elements to read.
        // the fread() function reads nmemb elements of data, each size bytes long, from the stream pointed to by stream, storing them at the location given by ptr.
    // size_t fwrite(void* ptr, size_t size, size_t nmemb, FILE* stream)
        // same as fread() except ptr is where the place we are writing the data from

    // int fseek(FILE* stream, size_t offset, int whence)
        // fseek moves around in a file from a specfies offset from a starting position (whence).
        // whence can either be the start of file (SEEK_SET), the current position of file pointer (SEEK_CUR), or relative to the end of the file (SEEK_END)
        // SEEK_SET = 0
        // SEEK_CUR = 1
        // SEEK_END = 2. remark for SEEK_END, if we wanna move backwards from the end (ie, left <--), then use a negative offset.
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
    char Cstring4[6] = "BABABABOEEEEEYYYYY AHHHHHHHH THIS STRING IS TOO LONG";
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
    // the n in the name indicates there is a new n parameter in the function which will indicate
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

    // FUNCTION OVERHEAD COST
    // refers to additional work and resources consumed when functions are invoked
    // includes:
        // pushing and popping parameters onto and from stacks
        // managing return address
        // setting up and tearing down a new stack frame

    // when a function is inlined, the overhead from pushing and popping parameters is eliminated.

    // key take away:
    // almost anything that can be done with macros can be done with C directly. just use C.
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
        // open
        // close
        // pipe
        // fork
        // wait

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
    // note that we dont need to pass ERRNO into perror
    
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
    // in this section we define a program, processes, and understand how an OS works with them.

    // program:
        // the executable instructions of either source code or compiled machine code.

    // process:
        // running instance of a program
        // a process includes the machine code of the program + info about the current state of the process, ie) what to step to execute next
        
    // when a program is loaded into memory, it is loaded as a contiguous piece
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
            exit(1); // whats the diff between this and return - 1 ?? ANS: exit() will terminate the entire program, whereas return -1 just ends the current function and returns a value!
        } // furthermore exit() pcarries out addition tasks such as closing files and freeing memoryu allocated by program.

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
    // recall, the lower 8 bits tell us what signal the process was ended by (in all of our processes, there was no signal so its all 00000000). 
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
                printf("Child %d terminated with %d\n", pid, WEXITSTATUS(status));  //WEXITSTATUS, read as W (wait): exit status. returns the exit status program terminated with. so with return 0, 1, 2, 3, 4.
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
    // so called getppid() from an orphan process just returns 1.
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
    // so far we have been duplicating the same program as a child process with wait() calls
    // but we can run a different program entirely using exec()
    // exec() replaces the currently running process with a different executable.
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
    // int execle(const char* path, const char* arg, ... NULL, char* const envp[])

    // int execv(const char* path, const char* arg0, char* const argv[])
    // int execvp(const char* file, const char* arg0, char* const argv[])
    // int execvpe(const char* file, const char* arg0, char* const argv[], char* const envp[])


    // the l's (first three) expect a list of command line arguments to be passed into the called program
    // the v's expect a vector, ie) an array of command line arguments instead of a list
    // p stands for path, which means the path environment variable is searched to find the executable
        // the executable is just given as the file name, not the full path.
        // without the p, exec will expect that the full path is given as the first argument rather than just the file name
    // e stands for environment. you can pass in an array of environment variables and their values
        // so the program executes within a specific environment. tbh not really sure how this works.


    // execvp and execlp are used most often.

    // SHELL CONNECTING TO C CODE:
    // this entire logic explains how the shell executes the our executable c code files.
    // the shell is just a process, and it uses fork() and exec(). 

    // how the shell runs c code:
        // first the shell calls fork() to duplicate itself as a process
        // then that child processes calls exec() to load a different program into its memory
        // the parent shell process then calls wait() and blocks until the child process finishes
        // when wait() call returns, shell prints the >$ to indicate it is ready to receive the next command

    // pretty cool. so it basically duplicates itself, then the clone (child) morphs itself (using exec) into a different program; our c executable.
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

void handler(int code) { // our handler for signal 
    fprintf(stderr, "Signal %d caught\n", code);
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

    // sigaction struct below. rmk: i was getting errors when i had siginfo_t* instead of void* so i changed it into void*. not sure why!!

    // struct sigaction {
    //     void (*sa_handler)(int);
    //     void (*sa_sigaction)(int, void*, void*); // should be (int, siginfo_t*, void*) !!!
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
    
    // remark:
    // two signals cant be changed with sigaction: SIGKILL and SIGSTOP. 
    // SIGKILL will always cause process to terminate and SIGSTOP will always suspend the process.

    return 0;
}

int bitwiseOperations() {
    // the power of C is that since it is a low level language, we can just directly manipulate the bit values of stuff, ignoring whatever type it is.
    // i wont go into much detail about the definitions, but make sure u understand OR, AND, XOR, and NOT operators.

    // bitwise operators: & and | 
    int x = 2; // binary 10
    int y = 1; // binary: 01

    printf("1 and 2: %d\n", x & y); // expect 00, so 0
    printf("1 or 2: %d\n", x | y); // expect 11, so 3

    // bitwise XOR given by ^
    x = 2; // 10
    y = 3; // 11

    printf("2 xor 3: %d\n", x ^ y); // 10 xor 11 should give 01.

    // bitwise NOT given by ~
    x = 2; // 10, well actually 0000 0000 0000 0010

    printf("not 2: %d\n", ~x); // not 10 gives 1111 1111 1111 1101. in 2's compliment this is just (-1) - 2 = -3. 
    // that is because, 1111 1111 1111 1111 is negative 1, and then we turn the second rightmost bit to 0, so -2.

    // 2's compliment referesher!
    // recall 2's compliment, the highest (leftmost) is equal to whatever it's regular value would be, times -1.
    // so 1000 0000 0000 0000 is the most negative value we can get with 16 bits, which is -2^15 = -32768
    // for an integer, it can be 16 bits or 32 bits depending on ur OS.
    // if it's 32 bits like it is for mine, then the most negative value you can have is:
        // 1000 0000 0000 0000 0000 0000 0000 0000, which is -2^31 = -2147483648

    // BITS IN DIFFERENT BASES
    unsigned char a = 0b00010011; // binary constant
    unsigned char b = 0x14; // hex constant
    unsigned char c = 07; // octal constant (preceed with 0)

    return 0;
}


int bitShiftLogic() {

    // lets have a refresher on converting hex to binary first.
    // from 0 - 9, conversion is just same as decimal to binary

    // HEX               BINARY             DECIMAL

    // 0                 0000               0
    // 1                 0001               1
    // 2                 0010               2
    // 3                 0011               3
    // 4                 0100               4
    // 5                 0101               5
    // 6                 0110               6
    // 7                 0111               7
    // 8                 1000               8
    // 9                 1001               9

    // A                 1010               10
    // B                 1011               11
    // C                 1100               12
    // D                 1101               13
    // E                 1110               14
    // F                 1111               15

    // 10           0001 0000               16

    // my tip: just memorize A is 1010, C is 1100, and F is 1111.


    // BIT PLACE CONVENTION
    // we say that bit 0 is the rightmost (least significant bit)
    // we say the k'th bit is the k'th bit to the left of the zero'th bit

    // eg)
    // for the bit: 0000 0100, the second bit is 1. ie) bit two is one.


    // now lets explore some bitwise operator problems
    // eg 1)
        // given a variable b, set the third bit to 1 and leave the other bits unchanged.

        char b = 0xC1; // this is 1100 0001 in binary

        b |= 8;  // note 8 is 1000, sets b to 1100 1001
        // short hand for b = b | 1;

    // eg 2)
        // check if the third bit of b has value 1
        b = 0xC1;
        bool third_bit_is_one = b & 4;
        printf("%d\n", third_bit_is_one); // will be 0

        b |= 4; // gives 1100 0101
        third_bit_is_one = b & 4;
        printf("%d\n", third_bit_is_one); // will be 1

    
    // we can make these problems more general using slli << (shift left logic immediate)
    // consider the problem:
    // given a variablke b, set the k'th bit to 1, not changing the other bits

    // remark srli is >>

    void set_K(int* b, int k);

    unsigned int x = 0xC1; // 1100 0001 which is 128 + 64 + 1 = 193
    printf("%u\n", x);

    set_K(&x, 3); // should give us 1100 1001, which is 193 + 8 = 201
    printf("%u\n", x); // gives 201


    // overflow with shifting
    // say we have a character (chars are 1 byte = 8 bits).
    char y = 0xAE; // so 1010 1110
    // doing slli will just discard the overflown bits

    y <<= 2; // y = y << 2,
    // so 1010 1110 -> 10 1011 1000, and the 10 that moves leftmost discarded
    // so 1010 1100 -> 1011 1000

    return 0;
}

void set_K(int* b, int k) { // k is required >= 0.
    // slli shifts 1 to the left by k binary places,
    // so for example: 1 << 3 , this will return 1000
    *b |= (1 << k); 
}


int bitFlags() {
    // flag bits are commonly used by system calls when a single argument is used to transmit data about multiple options
    // that argument variable is treated as an array of bits, where each bit represents an option/flag that can be turned on and off
    // {0, 1, 0, 0, 1} kind of like json object but values are bits.

    // this concept is used to implement file permissions

    // review of file permissions in linux:
    // each file has an owner and a group. run ls -l to see.
        // drwxrwxrwx 1 mrdandelion mrdandelion 4.0K Mar 31 01:50 .
        // drwxrwxrwx 1 mrdandelion mrdandelion 4.0K Mar 18 18:23 ..
        // -rwxrwxrwx 1 mrdandelion mrdandelion  309 Feb 11 23:06 Makefile
        // -rwxrwxrwx 1 mrdandelion mrdandelion    9 Feb  8 23:34 binary_data
        // -rwxrwxrwx 1 mrdandelion mrdandelion   20 Feb  8 23:34 binary_data2
        // -rwxrwxrwx 1 mrdandelion mrdandelion  15K Feb 13 12:47 igcc-0.2.tar.gz
        // drwxrwxrwx 1 mrdandelion mrdandelion 4.0K Feb 10 22:15 io-stuff
        // -rwxrwxrwx 1 mrdandelion mrdandelion  16K Mar 29 02:10 main
        // -rwxrwxrwx 1 mrdandelion mrdandelion  415 Mar 29 01:45 main.c
        // -rwxrwxrwx 1 mrdandelion mrdandelion 2.3K Feb  6 22:12 main.s
        // -rwxrwxrwx 1 mrdandelion mrdandelion  46K Mar 31 01:50 notes
        // -rwxrwxrwx 1 mrdandelion mrdandelion 141K Mar 31 01:59 notes.c
        // -rwxrwxrwx 1 mrdandelion mrdandelion  32K Feb  9 02:13 notes.o
        // -rwxrwxrwx 1 mrdandelion mrdandelion  32K Feb  9 02:13 notes_sort
        // -rwxrwxrwx 1 mrdandelion mrdandelion 1.3K Feb  8 00:59 sorting.c
        // -rwxrwxrwx 1 mrdandelion mrdandelion  718 Mar 28 23:57 sorting.h
        // -rwxrwxrwx 1 mrdandelion mrdandelion 3.0K Feb  8 01:34 sorting.o
        // -rwxrwxrwx 1 mrdandelion mrdandelion   89 Feb 25 19:05 tempCodeRunnerFile.c
        // drwxrwxrwx 1 mrdandelion mrdandelion 4.0K Feb 10 19:00 wav-stuff

    // first column is permission string: (-)(---)(---)(---) like (file type)(user)(group)(other)
    // third column is owner of the file and the fourth is the group

    // the first (-) is either - or d. it's d if it's a directory otherwise it's -
    // every (---) follows in the order rwx. when a permission is allowed it will show that letter, else its -
    // r is read, w is write, x is execute
    // we can represent these perms with flag bits as each place is either on or off. for now lets just ignore the first file bit.

    // so a nondirectory file with all perms looks like this:
        // -rwxrwxrwx
        // flag: 111 111 111 (ignoring first file / directory indicator)
        // so  1 1111 1111

    // a non directory file where only users can write would look like this:
        // -rwxr-xr-x
        // flag: 111 101 101
        // so 1 1110 1101

    // and a directory with only read perms for everyone would look like this
        // dr--r--r--
        // flag: 100 100 100
        // so 1 0010 0100

    // so we see that we need at least 9 bits to store this bit flag. cant use a byte.

    // one way to change permissions conveniently is using chmod
    // note that chmod has a thing called MODES which are basically the different file permissions in octal representation:
    // 0400 : read by owner
    // 0200 : write by owner
    // 0100 : execute by owner

    // 0040 : read by group
    // 0020 : write by group
    // 0010 : execute by group

    // 0004 : read by others
    // 0002 : write by others
    // 0001 : execute by others

    // OCTAL TO BINARY
    // each octal place is exactly 3 bits in binary. translates just how regular decimals would

    // OCTAL                BINARY
    // 0                    000
    // 1                    001
    // 2                    010
    // 3                    011
    // 4                    100
    // 5                    101
    // 6                    110
    // 7                    111
    // 8                001 000

    // this ends up being useful for a format like rwxrwxrwx, we can just use an octal representation like xyz

    // we can then define constants based on these octals

    // these are our "flags"
    #define OWNER_READ 000400
    #define GROUP_READ 000040
    #define OTHER_READ 000004

    // we could do the same for the other write and execute permissions as well 
    // then just use bitwise operations,
    mode_t mode = OWNER_READ | GROUP_READ | OTHER_READ;

    // similiar could check modes like this:
    mode_t check = mode & (OWNER_READ | GROUP_READ | OTHER_READ);

    // bit flags are nice because they save space abnd operations on them are very fast.
    // also note that bit flags used in system calls are defined in library files.

    return 0;
}

int bitArrays() {
    // we explore the use of flag bits to implement a set, or array
    // simple idea: each bit denotes presence or absence of particular element in a set.

    // can quickly perform set operations with bitwise operators

    // consider the simple case where a set consists of just small positive integers
    // eg) x = {0, 1, 2, 3, 4,, 5, 6, 7, 8, 9, 10, 11} 
    #define white 0
    #define black 1
    #define red 2
    #define orange 3
    #define yellow 4
    #define green 5
    #define blue 6
    #define purple 7
    #define brown 8
    #define pink 9
    #define silver 10
    #define gold 11
    // can make a bijective map to the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11} with bit flags

    unsigned short bit_array; // recal short is 2 bytes, so 0000 0000 0000 0000, 16 bits
    // say we our set only has {7, 5, 3, 2}, mapps to array 0000 0000 1010 1100
    bit_array = 0b000000010101100;

    // to add now, so if we want {10, 7, 5, 3, 2}, can simply use slli

    bit_array |= (1 << 10);

    // this technique is known as BIT MASKING
    // we create a bitmask: a carefully constructed value where specific elements are set or not set
    // we apply the mask to set or unset those values

    // to remove 10 we can do the following

    bit_array &= ~(1 << 10); // we want to make something like 011 1111 1111 and do &= on it.

    // in this example the reason we use a short to contain the bit array because it is large enough to encapsulate our set size.
    // if we wanted more bits, then we can just use an unsigned int instead, giving us 32. 

    // if we want a custom sized bit map, something larger than int etc, then we can just man an actual array of something (like unsigned ints):

    int N = 4;
    unsigned int bit_array2[N];

    // note the array isn't of N bits, it's of N unsigned ints, giving us 32*N bits to work with.
    // hence the operations will be a little more complicated.

    // eg) suppose we want to set a bit at index 34 to 1.
    int bit = 34;

    // we can use integer division to find the index in bit_array2 that contains the integer with the 34th bit.
    // naturally we know the first one is gonna contain 32 bits (bits 0 to 31), so the second one will contain the 34th bit.
    // using integer division:
    int index = bit / 32;

    // now to find how much we need to offset from the 0'th bit of the integer at index 1. we can just do this with mod
    int bit_place = bit % 32; // gives us 2, so bit-2 of the second integer holds the 34'th bit (remember the 0'th bit is the gonna be the "actual first" bit of the integer)

    // so now to set the bit at index 34 to one, we combine the above steps:

    bit_array2[index] |= (1 << bit_place);

    // now lets make a bunch of abitrary bit masking stuff below this function.
    return 0;
}

#define N 4
#define INT_SIZE 32 

typedef struct {
    unsigned int field[N];
} Bitarray;

// having our bitarry inside a struct is useful because it hides the implementation of our set and allows us to use a simple assignment statement to make a copy of the set

// we will now implement functions such as setting the bitarry to be all zero, turning a particular bit on, turning a particular bit off, and checking if particular bit is on or off

int setzero(Bitarray* b) {
    return memset(b, 0, sizeof(Bitarray)) == NULL;
    // sets everything starting from address b to 0 up to sizeof(Bitarray)
}

void set(unsigned int value, Bitarray* b) {
    int index = value / INT_SIZE;
    b->field[index] |= (1 << value % INT_SIZE); 
}

void unset(unsigned int value, Bitarray* b) {
    int index = value / INT_SIZE;
    b->field[index] &= ~(1 << value % INT_SIZE);
}

int ifset(unsigned int value, Bitarray* b) {
    int index = value / INT_SIZE;
    return b->field[index] & (1 << value % INT_SIZE) ? 1 : 0;
} 


int unbufferedIO() {
    // so far we've only been using IO operations that operate on streams, using file objects
    // fopen, fclose, fgets, fscanf, fprintf, .. etc.
    // these are all buffered IO operations.

    // these functions are great to use on files because they hide the complexity of some of the IO system calls
    // we now investigate unbuffered IO calls, ie) we learn about the actual system calls and how they work.

    // we say that buffered IO calls buffer data. ie) the system calls may read or write larger chunks of data than the user has specified.
    // so our unbuffered IO operations collect data in larger chunks.

    // collecting data in larger chunks helps ammortize the cost of data transfer by reducing the number of system calls we might need to make.
    // analogy: instead of sailing on a rowboat to trade a few cargos back and forth between islands, just load several cargos on a frigate.

    // this allows the programmer to ignore the details of data transfer (most of the time).
    // lets look at some file opening and file writing examples

    FILE* f = fopen("io-stuff/write_here.txt", "w"); // recall this returns a pointer to a file struct
    if (f == NULL) {
        perror("file open:");
        exit(1);
    }
    
    fprintf(f, "This is ");
    fprintf(f, "one of several ");
    fprintf(f, "calls to fprintf.\n");
    fprintf(f, "How many write ");
    fprintf(f, "system calls are generated?\n");
    fclose(f);

    // the question is how many write() system calls are generated?
    // on linux we can use a program called strace to run our program and see what system calls are made. do the following in shell:
        // strace ./notes
    
    // we get a lot of output because even simple programs make a lot of system calls:
    // execve("./notes", ["./notes"], 0x7ffe8e2de990 /* 26 vars */) = 0
    // brk(NULL)                               = 0x558b12523000
    // arch_prctl(0x3001 /* ARCH_??? */, 0x7ffe2bf5a9a0) = -1 EINVAL (Invalid argument)
    // mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff98cdb1000
    // access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
    // openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    // newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=20831, ...}, AT_EMPTY_PATH) = 0
    // mmap(NULL, 20831, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ff98cdab000
    // close(3)                                = 0
    // openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    // read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
    // pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
    // pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
    // pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\302\211\332Pq\2439\235\350\223\322\257\201\326\243\f"..., 68, 896) = 68
    // newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
    // pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
    // mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ff98cb82000
    // mprotect(0x7ff98cbaa000, 2023424, PROT_NONE) = 0
    // mmap(0x7ff98cbaa000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7ff98cbaa000
    // mmap(0x7ff98cd3f000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7ff98cd3f000
    // mmap(0x7ff98cd98000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x7ff98cd98000
    // mmap(0x7ff98cd9e000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ff98cd9e000
    // close(3)                                = 0
    // mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff98cb7f000
    // arch_prctl(ARCH_SET_FS, 0x7ff98cb7f740) = 0
    // set_tid_address(0x7ff98cb7fa10)         = 292199
    // set_robust_list(0x7ff98cb7fa20, 24)     = 0
    // rseq(0x7ff98cb800e0, 0x20, 0, 0x53053053) = 0
    // mprotect(0x7ff98cd98000, 16384, PROT_READ) = 0
    // mprotect(0x558b11735000, 4096, PROT_READ) = 0
    // mprotect(0x7ff98cdeb000, 8192, PROT_READ) = 0
    // prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
    // munmap(0x7ff98cdab000, 20831)           = 0
    // newfstatat(1, "", {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}, AT_EMPTY_PATH) = 0
    // getrandom("\xa1\xc3\xa6\x2c\x32\x6b\x06\x6b", 8, GRND_NONBLOCK) = 8
    // brk(NULL)                               = 0x558b12523000
    // brk(0x558b12544000)                     = 0x558b12544000
    // write(1, "started main\n", 13started main
    // )          = 13
    // openat(AT_FDCWD, "io-stuff/write_here.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 3
    // newfstatat(3, "", {st_mode=S_IFREG|0777, st_size=0, ...}, AT_EMPTY_PATH) = 0
    // write(3, "This is one of several calls to "..., 84) = 84
    // close(3)                                = 0
    // exit_group(0)                           = ?
    // +++ exited with 0 +++

    // we are only concerned with the 4'th last line:
        // write(3, "This is one of several calls to "..., 84) = 84

    // we see only one single write() call is made in this function. we have an addition write call because of our print message in main:
        // write(1, "started main\n", 13started main
        // )          = 13

    // however, in this function, even tho we have 5 different fprintf calls, we only did 1 write call for all of them.
    // the write call wrote 84 bits; exactly the length of our combined string from all fprintf calls.

    // but what is the value "3" in the write call? this value is known as a file descriptor.
    // FILE DESCRIPTOR: 
        // an integer that represents an open file or open communication channel
        // file descriptors are type int because the OS uses them as indexes into a table of open files
    
    // but why is it 3? why not 0 or 1?
    // this is because three files, 0, 1, and 2 are already open for us: stdin, stdout, and stderr
        // 0: stdin
        // 1: stdout
        // 2: stderr
    return 0;
}

int pipesInC() {
    // now we start investigating how to actually utilize multiple processes! very cool stuff.

    // since we can use fork() to make multiple processes, which can then work on the task simultaneously, then we will be able to solve problems faster.
    // remark: if we have a single processor only, then having more processes does nothing. however, multiple processesors = simultaneous execution of different processes.

    // but now we realize, for these processes to work together, they need communication.
    // pipes are one form of this communication. 

    // PIPES
        // used to relay information between two related processes
        // a pipe is specified by an array of 2 file descriptors: {x, y}. one for reading data from the pipe, and one for writing data to the pipe.
        // pipe(int arr[2]) is a system call to create a pipe.

    // we can create a pipe by calling the pipe() system call as follows:

    int arr[2];
    pipe(arr);
    // this creates a read file descriptor in arr[0] and a write file descriptor in arr[1].
    // useless to have this for a lone process, the magic happens when we use fork().

    // when calling fork(), the child process inherits the same pipe. ie) it gets a copy of the pipe that can be thought of as a deep copy between the two processes, like this:
    // parent <--> pipe <--> child

    // however, note that pipes are UNI-DIRECTIONAL, ie) one way. so we can choose to either:
        // 1.) parent writes, child reads
        // 2.) child writes, parent reads
    
    // for example we could have 2.)
    // child --(write)--> pipe --(read)--> parent
    // having arrows denoting the flow of data, we simply get:
    // child --> pipe --> parent

    // we must close the unused file descriptors once we decide the flow of data.
    // for example if the parent is only reading, then we would close the parent's write file descriptor
    // if the child is only writing then we close the child's read file descriptor

    // once the pipe is set up, we can use read and write system calls to send and receive data on the pipe.
    // here is an example where the parent writes and child reads

    // IMPORTANT REMARK: the pipe() call must be made before the fork() call because the child process inherits the open file descriptors from the parent.

    #define MAXSIZE 4096
    char line[MAXSIZE]; // a string line
    int fd[2];

    if (pipe(fd) == - 1) {
        perror("pipe");
        exit(1);
    }

    int r = fork();

    if (r > 0) { // in parent
        close(fd[0]); // close reading file descriptor

        printf("Enter a line > ");
        while (fgets(line, MAXSIZE, stdin) != NULL) { // retrieve line from stdin, review how fgets works!! see a demonstration below this function of how fgets works in stdin.

            printf("[%d] writing to pipe\n", getpid());

            if (write(fd[1], line, MAXSIZE) == -1) { // write line to write file descriptor in fd[1]
                perror("writing to pipe");
            }

            printf("[%d] finished writing \n", getpid());
            printf("enter a line > ");
        }
        close(fd[1]); // close writing fd

        printf("[%d] stdin has been closed, waiting for child\n", getpid());

        int status;
        if (wait(&status) != -1) {
            if (WIFEXITED(status)) {
                printf("[%d] child exited with %d\n", getpid(), WEXITSTATUS(status));
            } else {
                printf("[%d] child exited abnormally\n", getpid());
            }
        }
    }

    else if (r == 0) { // in child
        close(fd[1]);
        printf("[%d] child \n", getpid());
        char other[MAXSIZE];

        while (read(fd[0], other, MAXSIZE) > 0) { //  reads from read fd
            printf("[%d] child received %s\n", getpid(), other);
        }

        printf("[%d] child finished reading",  getpid());
        close(fd[0]);
        exit(0); // remark, we didnt need to do close(fd[0]) cause a call to exit() automatically closes all file descriptors for us.
    } 
    
    else {
        perror("fork");
        exit(1);
    }
    

    return 0;
}

// fgets demsontration from stdin:
int fgets_stdin() {
    char s[10];
    fgets(s, 5, stdin); // program waits for users to type something on keyboard.
    printf("you typed: %s\n", s);
    return 0;
}

int concurrencyAndPipes() {
    // some important details of how pipes really work
    // recall pipes are used to communicate between two separate processes, but it is up to the OS to decide when these processes run
    // so it is likely that the processes wont run in lock step with each other

    // this is an example of the consumer-producer problem

    // PRODUCER CONSUMER PROBLEM
    // one process writes data
    // one process consumes data

    // we can think of this as the consumer being the process that reads stuff from the process that writes stuff
    // if the consumer doesnt consume fast enough than the data can pile up
    // we can think of the pipe as a queue, where data is "queued" by producer and dequeed by consumer when it is read

    // supposed the queue has a limited size, then this can be a problem.
    // we dont want the producer to put data into a full queue
    // similarly, we want to make sure that the consumer doesnt try to remove data from an empty queue (in the case that the producer produces slower than the consumer consumes)

    // so overall, we are concerned with 3 scnearios
    // 1.) producer adding to a full queue
    // 2.) consumer removing from an empty queue
    // 3.) producer and consumer acting at the exact same time

    // note that the pipe is a queue data structure in the OS.
    // we dont have to worry about 3 because the OS manages the pipe structure and ensures that the producer and consumer dont act simultaneously
    // similariy we dont have to worry about reading from and empty pipe as the OS manages this case as well. the read() call will block if the pipe is empty.
    // and lastly, the OS also takes care of 1.) as it causes write() call to be blocked when pipe is full.

    return 0;
}

int redirectingInputAndOutputDup2() {
    // in this section we learn how to redirect input/output from one file descriptor to another with dup2() system call

    // motivation:
    // we take a look at the shell's redirection operators.
    // many useful shell programs read their input from stdin and write to stdout
    // for example:
        // grep Saitama io-stuff -r
        // searches for lines containing "Saitama" in recursively in io-stuff. outputs this:
        // io-stuff/iostuff.txt:Saitama 999999

    // this would only print to shell but we can redirect output to save it to a file with redirection operator:
        // grep Saitama io-stuff -r > temp.txt

    // we can even use output of one program is the input for another program with pipe |
        // grep Saitama io-stuff -r | wc
        // this gives:       1       2      36
    
    // so | has the following form
    // <producer> | <consumer>
    // where <producer> is what produces the input which goes into <consumer> which may produce an output 

    // now supposed we just want to change stdout for the shell process so it writes to a file by default instead of the screen
    // we use dup2 to do this.

    // DUP2()
    // dup2 makes a copy of an open file descriptor. 
    // we will use it to reset the stdout file descriptor, so writes to stdout go to a file instead of screen.

    // a file descriptor is really an index into a table, the "fd table", which is part of the PCB.

    // recall each process has its own PCB. hence, each process has its own unique fd table.
    // table contains pointers to data structures that contain information about open files.
    // eg) the 0 index in fd tables usually contain a link to the console (stdin coming from terminal).

    // when a child process is created (using fork), it obtains a copy of the fd table from its parent
    // even though the file descriptor tables are separate, the pointers in them may point to the same object!
    // changes to the object (eg a console) will be observed by both processes.

    // the way to use dup2 is as follows:

    // 1.) open file to set stdin to read from or stdout to write to (in our case we are gonna change stdout)
    FILE* stream;
    if ((stream = fopen("io-stuff/write_here.txt", "w")) == NULL) { // rmk, its important to add the extra () around: stream = fopen("io-stuff/write_here.txt", "w" or else error.
        perror("file open");
        exit(1);
    }

    // fileno() is a function that extracts the file number of a file pointer. for example stdout is typically 1:
    printf("%d\n", fileno(stdout));

    // any opened files will usually have a file number 3, 4, 5.. so on depending on the order they were opened. 
    // recall that 0, 1, and 2 are taken by stdin, stdout, and stderr, so we begin assigning new file numbers to new streams starting from 3. 
    printf("%d\n", fileno(stream)); // as expected, we get three.

    if (dup2(fileno(stream), fileno(stdout)) == -1) { // set file number of stream to be filenumber of stdout
        perror("dup2");
        exit(1);
    }

    // dup2(fileno(stream), fileno(stdout)); is the call we made in case it is hard to see it surrounding the error check.

    printf("whats up!\n"); // prints to stdout which is now write_here.txt

    // it is good practice to close any file descriptors we are not going to be using.
    // we should close stream because we are not going to be writing to the file directly with something like fprintf, but we write to it as stdout.

    if (fclose(stream) != 0) {
        perror("closing file");
        exit(1);
    }
    
    // closing the file doesnt change anything, it's still our stdout.

    printf("yooo!??!?\n");

    return 0;
}

int implementingShellPipeOperator() {
    // we will walk through an example that uses pipe and dup2 to implement the shell's pipe operator.
    // the shell pipe operator | allows us to connect 2 processes such that the stdin for one process becomes the stdout for another process    

    // lets play around on sort and uniq programs.
    // sort can take a filepath as an argument and print all the lines in the file in a sorted manner.
    // eg)
        //$ sort "io-stuff/iostuff.txt"
        // Blast 140000
        // Garou 200000
        // Genos 9000  
        // Genos 9000  
        // Genos 9000  
        // King 200
        // Saitama 999999
        // Sonic 5000
        // Tornado 110000
        // Watchdog 100000

    // similarly, uniq also takes in a file path and returns everything excluding lines that are exactly same as the previous line.
    // what if we want everything unique?
    // something like:
        // hi
        // yo
        // hi
    // wont get filtered because hi and hi are not adjacent. so we can sort then do a pipe to uniq.
    // like this sort: "io-stuff/iostuff.txt" | uniq
    // we will implement in this in C with dup2

    int fd[2], r; // r is going to be the fork() return value

    // first lets make the pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }
    
    if ( (r = fork()) > 0 ) { // in parent
        int file = open("io-stuff/iostuff.txt", O_RDONLY); // O_RDONLY imported from fcntl.h
        // havent went over using open() system call yet, learn it urself kid. doesnt return a pointer to FILE but rather the file descriptor.

        if (dup2(file, fileno(stdin)) == -1) { // set parent's stdin to be the file
            perror("dup2");
            exit(1);
        }

        if (dup2(fd[1], fileno(stdout)) == -1) { // set parent's stdout to be the pipe's write descriptor
            perror("dup2");
            exit(1);
        }

        // close stuff!!
        if (close(fd[0]) == -1) { // parent's not going to read from pipe so close it
            perror("close");
            exit(1);
        }
        if (close(fd[1]) == -1) { // the writes go to stdout, which will automatically write to pipe.
            perror("close");    // recall that we traditionally used write() and read() system calls to communicate over pipe
            exit(1);            // we wont be doing that anymore since we are just setting the file descriptors as stdin and stdout with dup2 now, so we close the write descriptor as well.
        }
        if (close(file) == -1) { // we arent gonna be using the input file directly so close it.
            perror("close");
            exit(1);
        }

        execl("/usr/bin/sort", "sort", NULL); // now we swap the parent process to be sort, which will carry over the same stdin and stdout
        fprintf(stderr, "ERROR: exec should not return \n");
    } 

    // rmk: it is very important to do close(fd[1]) or else the read end of the pipe will not know when the pipe queue is empty.
    
    else if (r == 0) { // in child

        if (dup2(fd[0], fileno(stdin)) == -1) { // set child's stdin to the pipe's read fd
            perror("dup2");
            exit(1);
        }

        // closing stuff!
        if (close(fd[1]) == -1) {
            perror("close");
            exit(1);
        }
        if (close(fd[0]) == -1) {
            perror("close");
            exit(1);
        }

        execl("/usr/bin/uniq", "uniq", NULL); // now we swap the child process to be uniq, which will carry over the same stdin and stdout
        fprintf(stderr, "ERROR: execl should not return\n");
    }

    else {
        perror("fork");
        exit(1);
    }

    // so a quick walkthrough:
    // first we make a pipe
    // then we work
    // then in parent process:
        // open our input text file
        // set our file to be the stdin
        // set our pipe write to be stdout
        // close pipe read, pipe write, and the input txt file
        // execl to sort
    // in child process:
        // set our pipe read to be stdin
        // dont mess with stdout
        // close stdin and stdout
        // execl to uniq

    // understanding how the execl() works:
    // once the pipes are all setup correctly, our parent process does execl to sort so that sort executes instead.
    // sort begins to read from stdin then writes to stdout which is passed through the pipe as stdin of the child.
    // the child calls execl on uniq which also reads from the child's stdin (the pipe). then it outputs the result to stdout which is just the console.

    return 0;
}

int introToSockets() {
    // so far: 
    // pipes to communicate between child and parent processes
    // signals to communicate between unrelated processes
    // however both pipes and signals can only be used to communicate with processes that are on the same machine.

    // sockets can be used to communicate over a network; between processes on 2 different machines.

    // we are going to need some background information on the internet:
    // each machine has an internet protocol: aka an IP address.
    // this is an address that can be used to send a message to it from any other machine thats connected to the internet.

    // there may be lots of different programs that need to communicate over the internet, but we only have one IP address for each machine.
    // messages sent across the internet are destined for a particular program; we need PORTS to specify this. 

    // PORTS
    // if a machine's IP address is like street address, then a PORT is like an apartment number in the building at that address
    // so the full location of a program running on a machine connected to the internet is its machine address plus the port
    // 195.67.7.8: 22

    // messages sent from one machine are enclosed as "packets"
    // think of these as packages; contain both the address and a payload-the contents of the package.
    // however the packet does not specify the route it travels to get to the destination. the route is determined as the packet moves (dynamically).

    // when packet leaves machine, it is received by another device called a router. a router facillitates the transfer of packets between networks.
    // routers are connected to multiple networks and know which network the packet should be sent to in order to get it closer to its final destination.

    // Client and Server:
    // SERVER: 
    // a server is a program running on a specific port of a certain machine waiting for another program or many other programs to relay data.
    // many common services have defined ports. eg) web pages are typically served on port 80.
    // secure webpages use port 443

    // in other cases, the person running the server publishes the machine address and port, basically saying: to run my game join at this address <machine address>:<port>
    // like hosting a minecraft server with port forwarding.

    // CLIENT:
    // users run a client program when they want to start interacting with a server.
    // the client program sends the initial message. in some cases the client sends only a single message. in other cases, the client begins a connection.
    // a connection is a conversation betweewn the two machines that involves multiple messages.
    // once the programs have established a communications channel, then either machines can send data to each other.

    // now the question boils down to, "how can we establish a communications channel" ?
    // to do this we can use SOCKETS!!

    // there are many different kinds of sockets, but the different types all rely on the same system calls. here are some examples:
        // datagram sockets
        // stream sockets
        // raw sockets
        // domain sockets
        
    // as a result, these system calls have many different and sometimes confusing options to allow you to set up the kind of socket that you want.

    // we will just focus on one kind: stream sockets.
    // stream sockets are built on the TCP protocol. TCP sockets:
        // are connectetion oriented sockets
        // guarntee there will be no message loss in transit
        // messages will be delivered in the order they are sent.

    // the first system call we need is socket()
    // int socket(int domain, int type, int protocl)

    // this system call is used to create an "endpoint" for communication. 
    // after having everything set up, we will need one end point in the client program and one end point in the server.
    // so both programs must independently invoke this system call.

    // the return value of socket() is an int which is -1 if we get an error. 
    // if the call is successful, the return value is an index to an entry in the file descriptor table 

    // the domain parameter sets the "protocol family", ie the general set of rules used for communications. we will typically set this to the defined constant PF_INET or AF_INET. 
    // actually AF_INET and PF_INET are defined to be the exact same value. we have 2 definitions of same thing for historical reasons.
    
    // the second parameter type which specifies the type of socket. as we are working with stream sockets, we will use SOCK_STREAM.

    // the third parameter protocol configures which protocol specifically the socket will use for communication.
    // recall that stream sockets use the TCP protocol. actually TCP is the only protocol available for stream sockets, so we just provide 0 in the protpcol parameter.
    // providing 0 tells the socket system call to use the default protocol for this type of socket.

    // both our client and server programs will call socket() like this and create a socket end point. 
    // the file descriptor returned by the socket call will be the system calls that establish a connection. (this is explain in next section)

    // next section we learn how to configure socket in our server program to wait for connections on a specific port and address.

    return 0;
}

int socketConfiguration() {
    // once we create our endpoints using socket system call (with stream sockets), we can now configure that socket to wait for connections at a specific address.

    int listen_soc = socket(AF_INET, SOCK_STREAM, 0); // note that u need #include <sys/socket.h> for this which is linux specific. im running vscode through WSL for this.
    // our "listening" socket.

    if (listen_soc == -1) {
        perror("socket");
        exit(1);
    }

    // we have made a stream socket. now we want to actually set up the address.
    // must use the bind() system call for this
    // int bind(int socket, const struct sockaddr* address, socklen_t address_len);

    // bind() takes 3 parameters
    // 1st parameter of bind is socket we want to configure

    // 2nd of bind is a pointer to a sockaddr struct. there is a lot to know about this parameter.
    // the sockaddr struct is a generic address family. address family is another name for domain.
    // address families define how network addresses are represented and interpreted. different address families support different types of network communication protocols.
    // again, note that the type for the address parameter in bind() is const struct sockaddr* which is GENERIC. 
    // in our case, we will be using the address-family (aka DOMAIN) AF_INET. so we use the more specific struct sockaddr_in instead of sockaddr. the in stands for internet.
    struct sockaddr_in {
        short sin_family; // this specifies domain / family address
        __u_short sin_port; // this specifies the port our socket is on
        struct in_addr sin_addr; // this specifies the machine address. need #include <netinet/in.h>
        char sin_zero[8];
    };

    // 1.) -- SIN_FAMILY --
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; // we set family to AF_INET

    // 2.) -- SIN_PORT --
    // next we set add.sin_port to the port number we want.
    // port numbers range from 0 to 65535. different ports have different uses/reservations:
        // ports 0-1023 are reserved for well known services, such as Telnet (runs on port 23).
        // ports 1024-49151 are known as registered ports. if you use these ports for a service u want to make public, you can REGISTER with IANA: the internet assigned numbers authority. 
            // IANA also looks after assigning domain names at highest level.
        // ports 49152-65535 are known as dynamic ports. for a server to run on your own machine, these ports will be fine. 
            // but for a server running on a shared machine, dont use same port number as someone else. ie) dont setup a socket with a port that a differnet program is already using. 

    // suppose we use port 54321 for a project:
    addr.sin_port = htons(54321);
    // we must use htons on the port number. htons stands for host to network short 
    // we need to use this because different machines could have different bit representations of the same number. 
    // eg) little endian vs big endian machines will have different bit orders.
    // we want to ensure the 2 machines that are communicating are speaking the same language.
    // so we add a middle language as a "protocol" so both machines know what to expect over the network.
    // so we use htons to put the port numbers in the protocol format.

    // more specifically, htons converts "the byte order of host machine to NETWORK BYTE ORDER".
    // suppose the machine already uses network byte order, then htons does nothing.

    // TERMINOLOGY SIDE NOTE: recall structs have "members". these can also be called fields. the terms are interchanged depending on the context but yeah.

    // 3.) -- SIN_ADDR --
    // now the third member, in_addr, is a struct itself. in_addr specifies the machine address of the socket.
    // the only field of sin_addr is s_addr.
    addr.sin_addr.s_addr = INADDR_ANY; // we just set it to this constant.
    // this configures the socket to accept connections from any of the addresses of the machine..
    // but wait , dont machines have a single address? not always actually. a machine can have multiple network interface cards and can be plugged into several networks.
    // this way a machine could have several IP addresses, each on a different network.
    // so "a machine has a different address per network"

    // rmk: a machine also has an address for itself. this is localhost: 127.0.0.1
    // so a computer X may have an IP address like 123.456.78.910
    // then to join a server on X from some computer we could connect to it using that address.
    // however if we run the client program on the same machine (on X), we could connect to the server just using localhost 127.0.0.1

    // 4.) -- SIN_ZERO --
    // now the last field, sin_zero, is just used for extra padding.
    // this is just used to make the sockaddr_in struct the same length as the generic sockaddr struct. pretty simple, we just add 8 bits.
    // recall that when we malloc sockaddr_in, the stuff that was in the memory space previously wont automatically be reset unless we set it to something.
    // we already set all the other 3 members, so they wont contain any old data. so we also want to set the padding to something, we just do memset and set everything to 0.
    // the reason we want our old data to be wiped is bc it could contain vulernable information that malicious third parties could intercept and use to do bad things 
    memset(&addr.sin_zero, 0, 8);

    // now we have set up our stuct sockaddr_in and we are ready to pass it as an argument to bind().
    // but wait, isn't bind expecting a pointer to sockaddr struct not sockaddr_in?
    // we just cast it lol. so call like this: bind(X, (struct sockaddr*) &addr, Y)

    // 3rd and last parameter to bind is just the length of the address we are passing. can easily get this by using sizeof() on struct sockaddr_in.
    // now we are finally ready to call bind:

    // the return value of bind is used for error checking:
    if (bind(listen_soc, (struct sockaddr*) &addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        close(listen_soc);
        exit(1);
    }
    // confirming the success of bind is particularly important. suppose the port we picked is not available because its already in use. then bind would fail in this case.
    
    // so now we have bound a socket to a particular port on a particular machine. next we need to tell the machine to start looking for connections.
    // the system call to start looking for connections is listen()
    // int listen(int socket, int backlog)
    
    // the return value of listen is for error checking 
    // the first parameter socket is the same socket we r setting up. 
    // the second parameter backlog is a little more complicated. backlog denotes the maximum number of "partial connections" the server can hold.

    // PARTIAL CONNECTIONS:
    // basically a pending request to connect to the server. the requests are not immediately connected, they most go through some "work" of being accepted.
    // backlog denotes the maximum number of this queue.

    // for our purposes, we shall just set backlog to 5. then we call listen like so:
    if (listen(listen_soc, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // now the last system call that our server needs to establish a connection with the client is accept()
        // int accept(int sockfd, struct sockaddr* address, socklen_t* addrlen)
    // first param: sockfd is just the listening socket we've been setting up.
    // second param: address. accept uses address to communicate back to the caller; the address of the client.
    // so when accept returns, the second parameter will point the a struct that holds the client's address information.

    // note that accept() is a blocking system call, just like read(). it will wait until a connection is established.
    // so for example, if u call accept and no client attempts to connect then accept will not return immediately; it will block.
    // accept can return if there was an error tho. return value is -1 if accept() fails.
    // however, on success, the value of accept() isnt 0, it's a positive integer representing a new socket which we will use to communicate with the client. we will explore this soon.
 
    // so basically since the return value is being used to return a new socket index, it cant be used to return the address of a client.
    // thats why we have the struct addr* pointer.
    // also just as before, we will actually pass in struct sockaddr_in* and cast it as (struct sockaddr*)

    struct sockaddr_in client_addr;
    // only thing we need to configure for this struct will be the sin_family
    client_addr.sin_family = AF_INET;

    // similarly, the third parameter will be set to the length of the address. we already know what the size is going to be since it's a sock stream with domain AF_INET and TCP protocol.
    // so we calculate that as below: 
    __u_int client_len = sizeof(struct sockaddr_in);
    // and pass in the pointer of client_len into the accept() call.

    // now we make the call:
    int client_socket = accept(listen_soc, (struct sockaddr*) &client_addr, &client_len);
    // when we make this call, the program blocks and waits for a connection to be made from client side. we will now write a program, client.c, that sends a connection.
    // remeber, the return value of accept will be the file descriptor for client socket stream, and -1 if it fails.
    if (client_socket == -1) {
        perror("accept");
        exit(1);
    }


    /* from here on, start reading client.c as well */
    // we must make a connect() system call from client program. this will be client.c
        // int connect(int sockfd, const struct sockaddr* address, soclen_t addrlen)

    // first parameter is going to be a socket created on the client side.
    // second parameter is going to be the address of the socket on the server to which we want to connect. we have to know this address!

    // we gotta know the port number, but we also need to know the machine address: ie) the IP address of the machine.
    // humans know the machine "names" typically, but probably not the IP address. so we can get the IP address by providing a sys call with the machine's name.
    // this is assuming we somehow know the machine's name.
    // the sys call we use for this is getaddrinfo()
        // int getaddrinfo(char* host, char* service, struct addrinfo* hints, struct addrinfo** result)
    // this looks at the internet address of a machine based on its name. this is a powerful system call. 

    // we just show the simplest possible use case of getaddrinfo() here. we completely ignore the second and third parameters of getaddrinfo, and just set them as NULL.
    // the first parameter, host, is a string which is the name of the host machine. the last parameter is a pointer to a pointer of a linked list of structs.
    // there could potentially be more than one address that satisfies our request for address information (not sure how). 
    // each element in the linked list is information about one of those valid addresses.

    // the getaddrinfo() sys call expects us to create a pointer and pass its address. then it allocates memory for linked list of address info and sets the pointer to point to the list.
    // struct addrinfo* result; // so we pass this address as last param into getaddrinfo()

    // btw all of this code is gonna be on client.c so yea
    // so the system call getaddrinfo() allocates memory for the linked list in result on the heap. 
    // we also get a function we call to free that memory when we are finished.
    // this function is freeaddrinfo(struct addrinfo* result); just pass in result when we are done.

    // but before we free the result, we want to use the information obtained in it to set the server address and connect.
    // we will look at only the first address information struct from the linked list. this is the one pointed at directly by result.
    // after called getaddrinfo, we can obtain this by just doing
    // server.sin_addr = ( (struct sockaddr_in *) result->ai_addr )->sin_addr;

    // lets break it down: (starts dancing* jk)
    // result->ai_addr returns a sockaddr generic address. we cast that to sockaddr_in then extract sin_addr from that.
    // recall sockaddr_in has a sin_addr address. we then assign that to the server sockaddr_in that we are making for connect().
    // like shown above: server.sin_addr = ( (struct sockaddr_in *) result->ai_addr )->sin_addr;

    // now we have successfully set up our server sockaddr_in, and we can call connect.
    // note that connect returns -1 if we fail. btw make sure u are reading client.c to understand all of this, or else it will sound like raw yaps.


    // IMPORTANT REMARK ABOUT CONNECTING TO HOSTS:
    // the getaddrinfo() is useful because we can just pass in something like a URL for a website that's hosted on a domain and retrieve its IP address.
    // however, for connecting to a local machine, we note that there is no notion of a "host name".
    // the idea of a host name for a local machine only extends to the local network. 
    // for example my computer's name may be Faisal's Computer, and this information would be useful only on my local network.
    // however if someone who was far away wanted to connect to a server hosted locally on my machine, they would need my actual IP address.
    // because, consider that "Faisal's Computer" is not a unique name. it's not a server hosted somewhere on the web.
    // in other words, getaddrinfo() is useless for setting up connections to servers hosted on local machines from far away.
    // disclaimer: not entirely sure about all of this, it is just what i think from researching on the net.

    return 0;
}

int socketCommunication() {
    // we already learned how to set up a connection, now we learn how to use the connection.

    // review:
    // SERVER SIDE:
    // 1.) socket(): create server's socket with socket() system call
    // 2.) bind(): bind socket to machine IP and particular port
    // 3.) listen(): start listening for partial connections (ie pending requests)
    // 4.) accept(): call blocking system call which waits for a connection request. 
    //               return of accept() value is the file descriptor for a new socket which will be used for communication with client.

    // CLIENT SIDE:
    // 1.) socket(): create client's socket with socket() system call
    // 2.) getaddrinfo(): option call if we want to get the machine address of server from its name
    // 3.) connect(): connect to the server by passing in our client socket and the server's address. we must know the server's address to connect to it.

    // connecting to multiple clients:
    // after we call listen(), it is gonna be there forever, still listening. but we would need to call accept() again to start waiting for a new connection.
    // recall that when we call accept(), our program begins to block. when blocking, we wont be able to talk to any currently connected clients.
    // so the way to handle multiple clients is by making use of some of the stuff we have already learned before: forking etc.
    // for now we will just focus on communicating between one client.

    // rmk: sometimes we refer to a socket as a socket descriptor since it's actually just a fd into the fd table.
    // once we have the stream socket set up between the client and server, we use this socket descriptor just like we use a file descriptor.
    // so we can use read() and write() system calls.

    // the following is going to be communication using dup2(), but we will explore communication without dup2 as well in next function.

    int serv_soc = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr; 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(46050);
    memset(&(server_addr.sin_zero), 0, 8);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if ( bind(serv_soc, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        exit(1);
    }
    
    if (listen(serv_soc, 5) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    __u_int client_len = sizeof(struct sockaddr_in);

    int client_soc = accept(serv_soc, (struct sockaddr*) &client_addr, &client_len);
    if (client_soc == -1) {
        perror("accept");
        exit(1);
    }

    // redirect input
    dup2(client_soc, fileno(stdin));
    
    char s[50];
    while (1 != 0) {
        scanf("%s", &s);
        printf("%s\n", &s);
    }

    return 0;
}

int socketCommunication2() { // this version uses write() and read() system call for communication

    int serv_soc = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr; 
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(46050);
    memset(&(server_addr.sin_zero), 0, 8);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if ( bind(serv_soc, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        exit(1);
    }
    
    if (listen(serv_soc, 5) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    __u_int client_len = sizeof(struct sockaddr_in);

    int client_soc = accept(serv_soc, (struct sockaddr*) &client_addr, &client_len);
    if (client_soc == -1) {
        perror("accept");
        exit(1);
    }

    // we use write() system call instead on the socket file descriptors.

    write(client_soc, "hello\r\n", 7); // 5 chars for hello plus r and n characters. 
    // note that we dont explicitly send the null terminating character in this example as we dont have enough space for a null terminator.
    // we use \r\n. this is called a "network newline"
    // we need to specify a specific order for the bytes so that machines that use different byte orders can work together.
    // similiarly, we are required to specify how to identify a new line so that machines that use a different sequence of characters render strings properly.

    // also in the client we will need to allocate some space like a buffer for data to read.
    // char buf[10]; in client.c

    char line[10];
    read(client_soc, line, 10);
    line[9] = '\0'; // add null terminator to end since we didnt send one.
    printf("message: %s\n", line);

    // important remark: we are assuming that one read / write call is sufficient to relay the information
    // but this is not true in general and just works for this specific case.
    // remember, we are talking about communication over the internet. data is wrapped up in IP packets, sent from machine to machine, and reassembled on the other end.
    // the stream socket protocol guarantees lossless transmition in same order. 
    // however, it does not guarantee that a "bunch" of data written with a single write statement will all arive at the same time.
    // in other words, there's no guarantee that it will all be available for the same read statement.
    // it might come in two different pieces for example, so we would need 2 read statements.

    // in real programs, we need to make use of the fact that the return value from read reports how many bytes were succesfully read.
    // we check this return value and call read again if we were expecting more bytes.

    //  it's especially important to check the return value of read because if the write end of the socket is closed, read will return 0.
    // for example we are using the client socket to relay information bidirectionally. if the write end of that socket were to be closed than read returns 0.
    // this tells us that we have already read all the data that will be sent on that socket and we do not need to call read() again.

    // if we did call read() again while the other end of the socket is closed, the read call will just immediately return 0.
    // if the other end of the socket is open, your read() will block forever, waiting for data that will never arrive.

    // its also good practice to explicitly close() the socket descriptor once we are done with it. 
    // this will cause the connection to be terminated. when our program exits, the system will explicitly send a close() on any sockets we didnt close.   
    // but its just good practice. also avoids problems that occur when a program doesnt immediately terminate; which leaves the other partner in the conversation waiting.
    close(serv_soc);
    // we dont close client_soc because the client closes that.

    return 0;
}

// multiplexing
int issueWithBlockingRead() {
    // we introduce a problem with using a blocking read() calls to read from multiple sources.
    // then we introduce a new system call that solves this problem by telling us which sources are ready for processing.

    // consider a simple scenario with a parent who has 1 child and a pipe set up between them.
    // the parent wants to read from chill so we call read() which will block until we get some write() from the parent or the parent closes the write end of the pipe().
    // simple enough.

    // now consider a parent with two children, child1 and child2. suppose the parent has two pipes set up, pipe1, and pipe2, and is reading from both children.
    // so we need 2 different calls to read(), one for each pipe. 
    // infact we probably want to have multiple read calls to each child since they usually will have more information.

    // suppose we read them in the order: read child 1 pipe, then read child 2 pipe. and we read them like this in a loop.
    // this works fine if child 1 writes. but what if child 1 doesnt write at all but child 2 writes a bunch.
    // we wont be able to get to child 2 pipe read call because the read call for child 1's pipe will be blocking the program.
    // this is rlly bad because we are keeping one child's writes waiting, and they can accumlate a lot to the point the pipe even gets full.    

    // similarly even if we read for child 2 first, after we read once we get to the read call for child 1 and our program just blocks as child 1 has nothing to say.
    // so essentially we are required for both of them to read and write sequentially in order, which is a big restraint. so order reading calls cant fix this.

    // the resolution to this is the select() system call which lets us specify a set of file descriptors to read from, and then blocks until at least one of them is ready.
    // then select() tells us which file descriptors are ready so we can call read() only on those and avoid blocking on the non ready ones.

        // int select(int numfd,  
        //            fd_set* read_fds, 
        //            fd_set* write_fids, 
        //            fd_set* error_fds, 
        //            struct timeval* timeout)

    // we will only make use of the first 2 parameters for now

    // select(numfd, read_fds,  NULL, NULL, NULL)

    // the basic idea is that the caller specifies a set of file descriptors to watch. select() blocks until one of these file descriptors has data to be read, or until the resources has been closed.
    // in either case, we can then be certain that the file descriptors that select() specifies will be "ready", ie) it wont cause ready to block.

    // the way this happens is that select() modifies the read_fds set we pass in to contain only fd's that are ready. 
    // can have more than one fd ready when select() returns.

    // note that select returns 1 if it is successful.

    // we show an example of reading without using select first, then in the next function we show the same code but with select. test out the functions for yourself and see how select allows us to read from multiple processes.

    char line[MAXSIZE]; // this will hold the read values
    int pipe_child1[2], pipe_child2[2];

    // before we fork, create child1 pipe:
    if (pipe(pipe_child1) == -1) {
        perror("pipe1");
        exit(1);
    }

    int r = fork();
    if (r < 0) {
        perror("fork1");
        exit(1);
    } 
    
    else if (r == 0) { // child1
        close(pipe_child1[0]); // we are not going to read from parent
        printf("[%d] child\n", getpid());

        while(1) { // this causes a block for writing!!! select() gets around this.
            //yuh
        }

        char message[10] = "HELLO FROM 1";
        write(pipe_child1[1], message, 10);
        close(pipe_child1[1]);
        printf("child1 finished write\n"); // note that this never gets printed since while(1) happens forever.
        exit(0); // exit child1
    }

    else { // in parent
        close(pipe_child1[1]); // not writing to child1

        // now make another pipe for child2:
        if (pipe(pipe_child2) == -1) {
            perror("pipe2");
            exit(1);
        }

        r = fork(); // create second child. approaching nesting hell lol
        if (r < 0) {
            perror("fork2");
            exit(1);
        }

        else if (r == 0) { // in child 2
            close(pipe_child2[0]); // not reading from parent
            printf("[%d] child\n", getpid());

            char message[10] = "HELLO FROM 2";
            write(pipe_child2[1], message, 10);
            close(pipe_child2[1]);
            printf("child2 finished write\n"); // this statement shows us that we finished writing but program is still blocked
            exit(0); // exit child2
        }

        else { // back in parent
            close(pipe_child2[1]); // not writing to child 2

            // we now begin reading.
            // the following is how it looks without select()
            if ( (r = read(pipe_child1[0], line, MAXSIZE)) < 0) {
                perror("read1");
                exit(1);
            } else if (r == 0) {
                printf("child1 is closed");
            } else {
                printf("read from child1: %s\n", line);
            }
            
            if ( (r = read(pipe_child2[0], line, MAXSIZE)) < 0) {
                perror("read2");
                exit(1);
            } else if (r == 0) {
                printf("child2 is closed");
            } else {
                printf("read from child2: %s\n", line);
            }
            
        }
        // can close read pipes here but the program automatically does this since we exit so we dont.
        // in the next function we demonstrate the solution to this. it will be the same code but we handle the reading with select().
    }

    return 0;
}

int usingSelectForReading() {
    char line[MAXSIZE]; // this will hold the rea~d values
    int pipe_child1[2], pipe_child2[2];

    // before we fork, create child1 pipe:
    if (pipe(pipe_child1) == -1) {
        perror("pipe1");
        exit(1);
    }

    int r = fork();
    if (r < 0) {
        perror("fork1");
        exit(1);
    } 
    
    else if (r == 0) { // child1
        close(pipe_child1[0]); // we are not going to read from parent
        printf("[%d] child1\n", getpid());

        while(1) { // this causes a block for writing!!! select() gets around this.
            //yuh
        }

        char message[15] = "HELLO FROM 1";
        write(pipe_child1[1], message, 15);
        close(pipe_child1[1]);
        exit(0); // exit child1
    }

    else { // in parent
        close(pipe_child1[1]); // not writing to child1

        // now make another pipe for child2:
        if (pipe(pipe_child2) == -1) {
            perror("pipe2");
            exit(1);
        }

        r = fork(); // create second child. approaching nesting hell lol
        if (r < 0) {
            perror("fork2");
            exit(1);
        }

        else if (r == 0) { // in child 2
            close(pipe_child2[0]); // not reading from parent
            printf("[%d] child2\n", getpid());

            char message[15] = "HELLO FROM 2";
            write(pipe_child2[1], message, 15);
            close(pipe_child2[1]);
            exit(0); // exit child2
        }

        else { // back in parent
            close(pipe_child2[1]); // not writing to child 2


            // ======= READING WITH SELECT() =======
            // we now begin reading.
            // the following is how it looks WITH select()

            // first set up the file descriptor sets.
            // note that an fd_set is implemented as a bit field stored in an array of ints. recall bit manipulation and flags.

            fd_set read_fds; // need #include <sys/select.h> for this
            FD_ZERO (&read_fds); // first make the set empty (clear out junk in memory)
            FD_SET(pipe_child1[0], &read_fds); // add reading fd 1
            FD_SET(pipe_child2[0], &read_fds); // add reading fd2

            // now we just need to set up numfd. numfd is a bit confusing. what we need to do is set this parameter to be the value of the highest file descriptor in your set, plus 1.
            
            int numfd = 1;
            (pipe_child1[0] > pipe_child2[0]) ? (numfd += pipe_child1[0]) : (numfd += pipe_child2[0]);

            // now we are ready to make a call to select() with the fd read sets.
            if (select(numfd, &read_fds, NULL, NULL, NULL) != 1) {
                perror("select");
                exit(1);
            } // note that select will block until at least one of the descriptors in the set are ready.

            // now read_fds only contains file descriptors that are ready to be read as select() modified this.
            // now we need to check which members are in the set. we have a another set operation for this: FD_ISSET()
                // int FD_ISSET(int fd, fd_set* fdset)

            // returns 1 if it is in the set, else 0.
            
            if (FD_ISSET(pipe_child1[0], &read_fds)) { // recall that if (1) evaluates to true in C just like in other languages.
                // now if the read pipe of child1 is ready, we do the following:

                if ( (r = read(pipe_child1[0], line, MAXSIZE)) < 0) { // note these if chain is just what we had in the old code, but now we only do this when we know read() is not gonna block.
                    perror("read1");
                    exit(1);
                } else if (r == 0) {
                    printf("child1 is closed");
                } else {
                    printf("read from child1: %s\n", line);
                }

            }

            if (FD_ISSET(pipe_child2[0], &read_fds)) {
                // and if read pipe of child 2 is ready, then we do this.

                if ( (r = read(pipe_child2[0], line, MAXSIZE)) < 0) {
                    perror("read2");
                    exit(1);
                } else if (r == 0) {
                    printf("child2 is closed");
                } else {
                    printf("read from child2: %s\n", line);
                }

            }
 
        }
    }
    
    // now we have seen how select() helps us. when we run this function, we dont get an indefinite block like we did in the previous function.
    // lastly, we go over the 3 stuff we set to NULL: select(numfd, read_fds, write_fds, error_fds, timeout)
    // write_fds: just like read_fds, write_fds is a file descriptor set for writing fds.
    // error_fds: just like the other two, error_fds is a file descriptor set for error fds.
    // timeout: a pointer to the struct timeval. we can use it to set a time limit for how long select will block before returning even if no file descriptors are ready. think of javascript.

    // another rmk: the fd sets we pass in get modified so we need to reconfigure them before another select() call.

    return 0;
}


// =================================================================================================================================================================

// END OF CSC209 NOTES !!! 

// that concludes all my notes on C pertaining to CSC209. i may continue to add more notes to this repo as i learn more C but they will be unrelated to CSC209.
// hope you enjoyed reading these notes as much as i enjoyed writing them.

// =================================================================================================================================================================
