#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sorting.h"
#include <stdbool.h>


int main(int argc, char* argv[]) {
    
    char hostname[256];
    
    // get the hostname
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("gethostname");
        return 1;
    }
    

    return 0;
}

