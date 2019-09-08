#include <stdio.h>
#include <string.h>

#define abs(x) ((x < 0) ? -(x) : (x))

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main(void)
{
    int x, w;
    char s[1000];

    x = -15256;
    w = 20;
    
    printf("i: %d\n", x);

    itoa(x, s, w);
    
    printf("w: ");
    while (w-- > 0)
        printf("-");
    printf("\n");
    printf("s: %s\n", s);

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

void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
