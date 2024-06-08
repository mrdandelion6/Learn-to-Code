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
    int xlx = __LINE__; // for latex typesetting, just ignore.

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

    // we can find the total steps by calculating the "cost" of each line and then multiplying by the "frequency"; the number of times that line runs.
    // lets count the steps for the insertion sort algorithm

    i = 1; 
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

    // now lets determine the WORST CASE frequency of each line. then we can multiply the cost by the frequency to get the total steps.
    
    i = 1; // 1 frequency
    while ( i < N ) { // N frequency: N-1 true + 1 false
        // the reason it's N-1 times true is because we loop N-1 times before it's false [1, N-1] inclusive.
        // would've been N times if i started at 0

        int v = A[i]; // 1 * (N-1) freq, recall N-1 times true
        int j = i; // 1 * (N-1) freq

        while ( j > 0 && A[j-1] > v ) { // (i + 1) * (N-1) freq : but i is not constant, it changes each iteration
            // worst case is loop runs all i times true, from j = i to j = 1 and 1 time false for j = 0
            // we use i because we can evaluate the sum later 
            // however, note that when calculating the total cost, we apply i for the "true" steps, and 1 for the "false" steps
            // this is because the true steps run i times and the false step just runs once.
            // recall the true steps were 10 and the false ones were 3, so we would have 10i + 3 for the total cost, and this would happen N - 1 times.
            A[j] = A[j-1]; // 1 * (i) * (N-1) freq
            j--; // 1 * (i) * (N-1) freq
        }

        A[j] = v; // 1 * (N-1) freq
        i++; // 1 * (N-1) freq
    }

    // now let's calculate the total cost.
    
    i = 1; // line 1
    while ( i < N ) { // line 2
        int v = A[i]; // line 3
        int j = i; // line 4

        while ( j > 0 && A[j-1] > v ) { // line 5
            A[j] = A[j-1]; // line 6
            j--; // line 7
        }

        A[j] = v; // line 8
        i++; // line 9
    }

    // line 1:
        // 2 steps * 1 freq = 2 total
    
    // line 2: (let's assume we have i < len(A) instead of i < N, so 5 steps).
        // 5 steps * N = 5N

    // line 3:
        // 5 steps * (N-1) = 5N - 5

    // line 4:
        // 3 steps * (N-1) = 3N - 3

    // line 8:
        // 5 steps * (N-1) = 5N - 5

    // line 9:
        // 4 steps * (N-1) = 4N - 4

    // so excluding the inner while loop, we have:
    // 2 + 5N + 5N - 5 + 3N - 3 + 5N - 5 + 4N - 4 = 22N - 22 + 2 
    // = 22N - 15

    // now let i be the i'th iteration of the outer loop
    // for the inner loop, we then have the following cost at each iteration of the outer loop:
    
    // line 5:
        // 10i + 3 steps

    // line 6:
        // 8i steps
    
    // line 7:
        // 4i steps

    // then in total, our while loop has the following cost:
    tex_output("our cost of the inner loop is:\n");
    add_tex_output(
        "\\begin{align*}\n"
        "&\\sum_{i=1}^{N-1} (10i + 3) + 8i + 4i\\\\\n"
        "=&\\sum_{i=1}^{N-1} 22i + 3\n"
        "\\end{align*}"
    );

    add_tex_output(
        "so our total cost is:\n"
        "\\begin{align*}\n"
        "& 22N - 15 + \\sum_{i=1}^{N-1} 22i + 3\\\\\n"
        "&= 22N - 15 + 22\\frac{(n-1)n}{2} + 3 (n-1)\\\\\n"
        "&= 11n^2 + 14n - 18\n"
        "\\end{align*}"
    );

    return 0;
}
