#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    unsigned y, z;
    y = ~x;
    z = ~(~0 << n) << (p + 1 - n);
    y = y & z;
    x = x & ~z;
    return x | y;
}

int main(void)
{
    unsigned x;
    printf("%u\n", invert(256, 4, 3));
}
