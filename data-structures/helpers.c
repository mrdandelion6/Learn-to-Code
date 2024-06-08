#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void print_int_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

