#include <stdio.h>

#define MAX 4

int main(void)
{
    int c, i;
    int char_val[MAX];
    int char_num[MAX];
    
    char_val[0] = 'a';
    char_val[1] = 'b';
    char_val[2] = 'c';
    char_val[3] = 'x';
    
    for (i = 0; i < MAX; i++)
        char_num[i] = 0;
    
    while ((c = getchar()) != '0')
    {
        if (c == char_val[0])
            ++char_num[0];
        else if (c == char_val[1])
            ++char_num[1];
        else if (c == char_val[2])
            ++char_num[2];
        else
            ++char_num[3];
    }
    for (i = 0; i < MAX; i++)
    {
        printf("%d\t%d\n", char_val[i], char_num[i]);
    }
}
