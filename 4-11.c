#include <stdio.h>
#include <ctype.h>

int getch(void);

int getop(char s[])
{
    int i, c;
    static int last = 0;
        
    if (last == 0)
        c = getch();
    else {
        c = last;
        last = 0;
    }
    while ((s[0] = c == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        last = c;
    return NUMBER;
}
