#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%u\n", setbits(0, 7, 2, 65535));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{    
    unsigned z;

    y = (y & ~(~0 << n)) << (p - n);
    z = ~(~(~0 << n) << (p - n));
    return (x & z) | y;
}
