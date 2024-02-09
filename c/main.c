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

int main(int argc, char* argv[]) {
    // printStuff(argc, argv);
    int* pt = set_i();
    printf("pt is %d\n", *pt);
    free(pt);

    return 0;
}

