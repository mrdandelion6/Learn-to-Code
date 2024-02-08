#ifndef SORTING_H
#define SORTING_H

typedef void (*SortFunc_t)(int*, int);
void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*, int);

typedef struct {
    char* name;
    SortFunc_t sort_funct;
} sort_info; 

// const int NUM_SORTS = 3;
// sort_info SORTS[] = {
//     {.name = "bubble", .sort_funct = bubble_sort},
//     {.name = "selection", .sort_funct = selection_sort},
//     {.name = "insertion", .sort_funct = insertion_sort}
// };

// the initializion of this variable has been moved to sorts.c
// the declaration is kept below:
extern sort_info SORTS[]; 
// must use extern to indicate that the variable is externally defined

#endif // SORTING_H