#include <stdio.h>

int main(void)
{
    int c;
    
    while ((c = getchar()) != '0')
    {
        if (c == '\t' || c == '\b' || c == '\\')
            putchar('\\');
        if (c == '\t')
            putchar('t');
        if (c == '\b')
            putchar('b');
        if (c == '\\')
            putchar('\\');
        else
            putchar(c);
    }

    return 0;
}
