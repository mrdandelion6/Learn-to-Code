#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int swapAround(char *a1, char *a2){
        char str[128];
        char str1[128];
        char str2[128];

        strncpy(str1, a1, 128);
        strncpy(str2, a2, 128);
        strcpy(str, str1);
        strcpy(str, str2);

        return 0;
}

int main(int argc, char * argv[]){
        printf("swapAround running.\n");
        if (argc != 3) {
                fprintf(stderr, "swapAround: argc != 3\n");
                exit(EXIT_FAILURE);
        }
        swapAround(argv[1], argv[2]);
}

