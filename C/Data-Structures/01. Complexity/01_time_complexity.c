#include <stdio.h>

int main()
{
    int x = 100;
    printf("x = %d\n", x);
    int y = --x;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    return 0;
}