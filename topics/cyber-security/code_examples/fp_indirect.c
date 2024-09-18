#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f2() {
    printf("hello from f2\n");
}

void f1() {
    printf("jaja from f1\n");
}

int main() {
    int (*f) (void);
    // this is a function pointer
    // recall the syntax: int (*f) (void) means that f is a pointer to a function that returns and integer and takes no arguments (void)
    

    int diff = (char*)&f2 - (char*)&f1; 
    // gives offset between f1 and f2

    f = &f1;
    f = (int (*)())((char*)f + diff); 
    // f now points to f2
    
    (*f)(); 
    // indirect call to f2
}
