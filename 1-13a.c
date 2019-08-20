#include <stdio.h>

#define IN 1
#define OUT 0

int printl(int x);

int main(void)
{
    int c, len, state;
    
    len = 0;
    state = OUT;
    
    while ((c = getchar()) != 0)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                printl(len);
                // printf(" %d", len);      // Option to include number next to histogram bar
                putchar('\n');
            }
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

int printl(x)
{
    for (int i = 0; i < x; i++)
        printf("*");
    return 0;
}
