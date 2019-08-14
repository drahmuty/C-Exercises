#include <stdio.h>

int main(void)
{
    int c;
    int b = 0;
    int t = 0;
    int nl = 0;
    
    while ((c = getchar()) != EOF)
        if (c == ' ')
            ++b;
        if (c == '\t')
            ++t;
        if (c == '\n')
            ++nl;
    printf("Blanks: %d\n", b);
    printf("Tabs: %d\n", t);
    printf("Newlines: %d\n", nl);
    
    return 0;
}
