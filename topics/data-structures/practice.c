#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // welcome to my notes on data structures.
    int insertion_sort(); 

    insertion_sort();

    return 0;
}

int insertion_sort() {
    // trying to implement insertion sort on my own.
    // copilot don't give me any hints.

    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = 6;

    int i = 1;

    while ( i < 6 ) {
        int v  = arr[i];
        int j = i;

        while ( j > 0 && arr[j-1] > v) {
            // moving everything up
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = v; 
        i++;
    }

    print_int_arr(arr, size);
    return 0;
}