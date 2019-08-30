#include <stdio.h>

int atoi(char s[]);
int htoi(char s[]);

int main(void)
{
    char c[2];
    c[0] = 'f';
    c[1] = '0';
    printf("Dec:\t%d\n", atoi(c));
    printf("Hex:\t%d\n", htoi(c));
}

int atoi(char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int htoi(char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0;
         (s[i] >= '0' && s[i] <= '9')
         || (s[i] >= 'a' && s[i] <= 'f')
         || (s[i] >= 'A' && s[i] <= 'F');
         ++i) {
        
        if (s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
        if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
    }
    return n;
}
