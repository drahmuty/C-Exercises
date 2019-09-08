/*
The original version of itoa cannot handle the largest negative integer because when it inverses the sign
it does not have enough binary bits to represent that number as a positive number. The greatest positive
integer in a two's complement system is one less than the largest negative integer. 

In a 16-bit system:
1000 0000 0000 0000 = -32768
0111 1111 1111 1111 = 32767
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void)
{
    int x = -727379968;
    char y[MAX];

    printf("int = %d\n", x);

    itoa(x, y);
    
    printf("str = %s\n", y);

    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, negative, a;

    negative = (n < 0) ? 1 : 0;
    
    i = 0;
    do {
        a = (n < 0) ? -1 : 1;
        s[i++] = a*(n % 10) + '0';
    } while(a*(n /= 10) > 0);

    if (negative)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}
