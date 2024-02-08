#include "sorting.h"
#include <stdio.h>

void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubble_sort(int* arr, int size) {
    printf("\n === doing bubble sort=== \n");
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (arr[j-1] > arr[j]) {
                swap(arr, j-1, j);
            }
        }
    }
}

void selection_sort(int* arr, int size) {
    printf("\n === doing selection sort=== \n");
    for (int i = 0; i < size; i++) {
        int current = i;
        for (int j = i; j < size; j++) {
            if(arr[current] > arr[j]) {
                current = j;
            }
        }
        swap(arr, i, current);
    }
}

void insertion_sort(int* arr, int size) {
    printf("\n === doing insertion sort=== \n");
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
            swap(arr, j-1, j);
        }
    }
}

sort_info SORTS[] = {
    {.name = "bubble", .sort_funct = bubble_sort},
    {.name = "selection", .sort_funct = selection_sort},
    {.name = "insertion", .sort_funct = insertion_sort}
};

int x = 1;

