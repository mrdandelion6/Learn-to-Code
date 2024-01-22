#include "functions.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    printf("passed in %d args \n", argc - 1);

    for (int i = 0; i < argc; i++) {
        printf("arg %d is %s\n", i, argv[i]);
    }

    printf("Hello World!\n");
    return 0;
}