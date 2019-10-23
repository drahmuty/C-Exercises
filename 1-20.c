#include <stdio.h>

#define TAB 4

int main(void)
{
    int c, i, sp;
    
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            i = 0;
        }
        else if (c == '\t') {
            sp = TAB - (i % TAB);
            while (sp-- > 0)
                putchar(' ');
            i = 0;
        }
        else {
            putchar(c);
            i++;
        }
    }
    return 0;
}
