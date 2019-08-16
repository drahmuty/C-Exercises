#include <stdio.h>

int main(void)
{
    int c;
    
    while ((c = getchar()) != '0')
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
    return 0;
}
