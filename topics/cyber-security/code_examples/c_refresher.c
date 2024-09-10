#include <stdio.h>
int main() {
    int x[] = {2, 4, 6, 8, 10}, y = 3, *z;
    
    z = &y;
    *z = 2;
    x[y] = 3;

    z = x;
    ++(*z);
    ++z;
    *z = 2*(*z);
    printf("%d %d %d %d %d %d %d\n", x[0], x[1], x[2], x[3], x[4], y, *z);
}