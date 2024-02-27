#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    printf("in main.c : my PID is %d\n", getpid());
    return 0;
}

