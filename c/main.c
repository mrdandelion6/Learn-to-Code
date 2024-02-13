#include <stdio.h>
#include <stdlib.h>

void printStuff(int argc, char* argv[]) {
    
    printf("passed in %d args \n", argc - 1);

    for (int i = 0; i < argc; i++) {
        printf("arg %d is %s\n", i, argv[i]);
    }
}

int* set_i() {
    int* i = malloc(sizeof(int));
    *i = 5;
    return i;
}

void pointerHelper(int** ptr) {
    int* arr;

    arr = malloc(3 * sizeof(int));

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    *ptr = arr;
}

void scanTest() {
    // char sta[100];
    char sta[10];
    char ca;

    char arr[3] = {'H', '\0', 'l', 'l', 'o'};

    printf("%s\n", arr);
    // while (fscanf(stdin, "%10c", sta) == 1) {
    //     printf("%s\n", sta);
    // }
}

int main(int argc, char* argv[]) {
    // printStuff(argc, argv);
    // int* pt = set_i();
    // printf("pt is %d\n", *pt);
    // free(pt);

    scanTest();

    return 0;
}

