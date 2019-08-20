#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, len, state;
    
    while ((c = getchar()) != 0)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                printf("%d", len);
                putchar('\n');
            
            state = OUT;
            len = 0;
        }
        else 
        {
            if (state == OUT)
                state = IN;
            
            ++len;
        }
    }
}
