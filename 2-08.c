#include <stdio.h>

#define MAXP 15

unsigned rightrot(unsigned x, int n)
{
    unsigned a, b;
    
    a = x >> n;
    b = x << (MAXP + 1 - n);
    return a | b;
}

int main(void)
{
    int x = 1;
    printf("%d\n", rightrot(x, 8));
}
