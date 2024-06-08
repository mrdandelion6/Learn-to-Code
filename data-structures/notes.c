#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // welcome to my notes on data structures.
    int main_topics();
    int ADTs();
    int counting_steps();

    // run
    counting_steps();

    return 0;
}

int main_topics() {
    // the main topics ill go over in these notes:

    // 1. balance trees
    // 2. hash tables
    // 3. graphs
    // 4. disjoint sets
    // 5. priority queues
    // 6. amortized analysis

    return 0;
}

int ADTs() {
    // ADT: Abstract Data Type
    // an ADT defines:
        // a set of objects
        // a set of operations that can be performed on said objects
        // possibly also their time and space costs (memory and performance)
        // DOESN'T DEFINE HOW THEY ARE IMPLEMENTED!!

    // the implementations of ADTs are called data structures

    // some things that make ADTs great
        // they just provide a specification; a framework for how things work
        // modularity: you can change the implementation without changing the interface
        // reusability: you can use the same ADT in different programs

    return 0;
}

int counting_steps() {

    // lets take a look at the following algo. we will see how we can count the total number of steps.
    #define N 10
    int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i = 1;
    while ( i < N ) {
        int v = A[i];
        int j = i;

        while ( j > 0 && A[j-1] > v ) {
            A[j] = A[j-1]; // move all the values up
            j--;
        }

        A[j] = v;
        i++;
    }
    // sorts the array to ascending
    // note at each iteration of the outer loop, the array is sorted up to i
    // this algorithm is known as insertion sort and has a worst case time complexity of O(n^2)

    // the inner while loop moves our 'v' value to its proper place in the sorted sublist (that goes up to i).
    print_int_arr(A, N);

    // lets try to count the steps this algorithm takes

    // COUNTING STEPS
        // getting/setting variables is 1 step
        // function call: 1 step for the call + 1 step to evaluate each argument + the steps inside the function
        // return statement: 1 step + the steps to evaluate the return value 
        // if/while condition: 1 step + the steps to evaluate the expressions
        // assignment: 1 step + the steps to evaluate the expression
        // arithmetic/boolean operators: 1 + the steps to evaluate the operands
        // array access: 1 step + the steps to evaluate the index
        // constants: free, they don't need to be evaluated

    // lets count the steps for the insertion sort algorithm

    int i = 1; 
    // 2 steps: 
        // - 1 for initializing (setting i)
        // - 1 for assigning 1 to i

    while ( i < N ) { 
    // 2 steps:
        // 1 for boolean comparison
        // 1 for evaluating (getting) i
        // 0 for "evaluating" N; it's a constant cause it's a macro
    // note that if we had len(A) instead (like for python), we would have 5 steps
            // 1 for boolean comparison
            // 1 for evaluating (getting) i
            // 1 for function call of len()
            // 1 for evaluating the argument A
            // 1 for returning the value of len()

        int v = A[i];
        // 5 steps:
            // 1 for assigning v
            // 1 for setting v
            // 1 for getting A
            // 1 for getting i
            // 1 for index access

        int j = i;
        // 3 steps:
            // 1 for setting j
            // 1 for assigning i to j
            // 1 for getting i

        while ( j > 0 && A[j-1] > v ) {
        // 10 or 3 steps:
        // 3 steps, happens if j <= 0:
            // 1 for while condition
            // 1 for boolean comparison
            // 1 for getting j
        // 10 steps, happens if j > 0:
            // 1 for while condition
            // 1 boolean comparison for j > 0 && A[j-1] > v (the whole thing)
            // 1 for boolean comparison j > 0
            // 1 for getting j
            // 1 for boolean comparison A[j-1] > v
            // 1 for getting A
            // 1 for getting j
            // 1 for calculating j-1
            // 1 for index access
            // 1 for getting v
    
            A[j] = A[j-1]; // move all the values up
            // 8 steps
                // 1 for getting A
                // 1 for getting j
                // 1 index access
                // 1 for assigning A[j-1] to A[j]
                // 1 for getting A
                // 1 for getting j
                // 1 for calculating j-1
                // 1 for index access

            j--; // j = j - 1
            // 4 steps:
                // 1 for getting j
                // 1 for assigning j-1 to j
                // 1 for getting j
                // 1 for calculating j-1
        }

        A[j] = v;
        // 5 steps:
            // 1 for getting A
            // 1 for getting j
            // 1 for index access
            // 1 for assigning v to A[j]
            // 1 for getting v

        i++; // i = i + 1
        // 4 steps:
            // 1 for getting i
            // 1 for assigning i+1 to i
            // 1 for getting i
            // 1 for calculating i+1
    }

    return 0;
}
