#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    
}

int setbits(unsigned x, int p, int n, unsigned y)
{    
    unsigned z;
    
    z = y >> n;
    z = z << n;
    z = ~z;
    z = y & z;
    z = z << (p - n);
    
    
}
