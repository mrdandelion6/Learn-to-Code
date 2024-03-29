#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorting.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {
    
    char str1[5] = "hi";
    char str2[40] = "hhhhhhhhhhhhhhh";
    strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
    printf("%s\n", str1);
    printf("last char is null terminator: %d\n", str1[4] == '\0');

    return 0;
}

