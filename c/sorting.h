#ifndef SORTING_H
#define SORTING_H

typedef void (*SortFunc_t)(int*, int);
void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*, int);

#endif