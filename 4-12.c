#include <stdio.h>

void itoarec(int n, char s[]);

int main(void)
{
    int a;
    char s[100];

    a = 256;
    itoarec(a, s);
    printf("%s\n", s);
    return 0;
}

void itoarec(int n, char s[])
{
    static int i = 0;
    
    if (n < 0) {
        n = -n;
        s[i++] = '-';
    }
    if ((n / 10) > 0)
        itoarec((n / 10), s);
    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
