#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, nl, nw, nc, state;
    
    state = OUT;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != 0)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            putchar('\n');
            putchar(c);
        }
    }
}
