#define _GNU_SOURCE

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // welcome to my notes on data structures.
    int main_topics();
    int ADTs();
    int algorithm_time();

    // run
    algorithm_time();

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
        // DOESNT DEFINE HOW THEY ARE IMPLEMENTED!!

    // the implementations of ADTs are called data structures

    // some things that make ADTs great
        // they just provide a specification; a framework for how things work
        // moduality: you can change the implementation without changing the interface
        // reusability: you can use the same ADT in different programs

    return 0;
}

void print_int_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int algorithm_time() {

    // lets take a look at the following algo:
    #define N 10
    int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    int i = 1;
    while ( i < N ) {
        int v = A[i];
        int j = i;
        while ( j > 0 && A[j-1] > v ) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = v;
        i++;
    }
    // sorts the array to ascending

    print_int_arr(A, N);

    return 0;
}
