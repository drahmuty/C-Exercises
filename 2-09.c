/* 
The rightmost bit is removed because we are AND-ing a binary number and the binary value of that number minus 1. 
When you subtract 1 from a number in binary, the rightmost 1 drops to 0 and all of the trailing 0's become 1's.
AND-ing these two binary numbers together results in the rightmost 1 and all following digits to be zero
because they are opposite. All binary digits to the left remain unchanged. 

We can write a faster version of bitcount by using this observation. Instead of shifting one digit to the right
in each iteration, we are now shifting to the next 1 digit, which could be greater than a one-unit shift. 
*/


#include <stdio.h>

int bitcount(unsigned x)
{
    int b;
    
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}

int main(void)
{
    unsigned x = 3;
    
    printf("%d\n", bitcount(x));
}
