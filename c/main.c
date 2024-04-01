#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorting.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {
    
    char s[10];
    fgets(s, 5, stdin);
    printf("you typed: %s\n", s);
    
    return 0;
}

