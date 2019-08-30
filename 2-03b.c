// Looked up the solution
// Changed for loop to while loop

#include <stdio.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main(void)
{
    char c[3];
    c[0] = 'f';
    c[1] = 'e';
    c[2] = '1';
    // printf("Dec:\t%d\n", atoi(c));
    printf("Hex:\t%d\n", htoi(c));
}

int htoi(char s[])
{
    int i, n, hexdigit, inhex;
    
    i = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;
    inhex = YES;
    while (inhex == YES) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] -  '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else 
            inhex = NO;
        if (inhex == YES)
            n = 16 * n + hexdigit;
        ++i;
    }
    return n;
}
