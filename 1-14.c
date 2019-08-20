#include <stdio.h>

#define MIN 97
#define MAX 123

int main(void)
{
    int c, i, j;
    int LEN = MAX - MIN;
        
    int char_val[LEN];
    int char_num[LEN];
    
    for (i = 0; i < LEN; i++)
    {
        char_val[i] = MIN + i;
    }
    
    for (i = 0; i < LEN; i++)
        char_num[i] = 0;
    
    while ((c = getchar()) != '0')
    {
        for (i = 0; i < LEN; i++)
            if (c == char_val[i])
                ++char_num[i];
    }
    for (i = 0; i < LEN; i++)
    {
        printf("%d\t", char_val[i]);
//         printf("%d\t%d\n", char_val[i], char_num[i]);        // Option to show numerical values
        
        for (j = 0; j < char_num[i]; j++)
            printf("*");
        printf("\n");
    }
}
