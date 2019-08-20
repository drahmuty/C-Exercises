#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 10

int main(void) 
{
    int c, i, j, state, len;
    int words[MAX];
    
    state = OUT;
    len = 0;
    
    for (i = 0; i < MAX; i++)
        words[i] = 0;
    
    while ((c = getchar()) != '0')
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                ++words[len-1];
            
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
//     for (i = 0; i < MAX; i++)
//         printf("%d:\t%d\n", i+1, words[i]);      // Option to print numerial values
    
    for (i = 0; i < MAX; i++)
    {
        printf("%d:\t", i+1);
        for (j = 0; j < words[i]; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
