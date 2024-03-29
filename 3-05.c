#include <stdio.h>
#include <string.h>

#define abs(x) ((x < 0) ? -(x) : (x))

void reverse(char s[]);
void itob(int n, char s[], int b);

int main(void)
{
    int n, b;
    char s[1000];
    
    b = 16;
    for (n = 0; n < 20; n++) {
        itob(n, s, b);
        printf("int: %d  base: %d  new: %s\n", n, b, s);
    }

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

void itob(int n, char s[], int b)
{
    int i, sign, m;
    
    sign = n;
    i = 0;
    do {
        m = abs(n % b);
        s[i++] = (m < 10) ? (m + '0') : (m - 10 + 'A');
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
