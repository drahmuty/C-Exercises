#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(1, 2, 2, 10));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{    
    unsigned z;

    y = (y & ~(~0 << n)) << (p + 1 - n);
    z = ~(~(~0 << n) << (p + 1 - n));
    return (x & z) | y;
}
