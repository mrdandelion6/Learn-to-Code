#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add(int num1, int num2);

int main(int argc, char *argv[]) {

    int num1 = 6;
    int num2 = 3;
    if (argc == 3) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
    }

    int sumnum = add(num1, num2);

    int c[32];
    // lets overflow the buffer c

    printf("%d + %d = %d\n", num1, num2, sumnum);

    return 0;
}

int add(int num1, int num2) {
    return num1 + num2;
}