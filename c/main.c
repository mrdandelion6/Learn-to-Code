#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorting.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {
    
    int fd[2];
    pipe(fd);

    printf("fd[0] is %d and fd[1] is %d\n", fd[0], fd[1]);

    if (close(1) == -1) {
        printf("waaa\n");
    }
    
    printf("bars\n"); // wont print
    

    return 0;
}

