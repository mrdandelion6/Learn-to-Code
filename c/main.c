#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorting.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {
    
    int fd[2];

    pipe(fd);

    if (fork() == 0) { // in child
        usleep(1000000); // sleep for 1 second
        char* s = "Hello, world!\n";
        close(fd[0]); // close the read end
        write(fd[1], s, strlen(s)); // unsafe, should do + 1
        printf("wrote in parent\n");
    }

    else { // in parent
        // usleep(1000000); // sleep for 1 second
        close(fd[1]); // close the write end
        close(fd[0]); // close the read end 
    }

}

