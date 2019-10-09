#include <stdio.h>

int strendp(char *, char *);

int maint(void)
{
    int result;
    char s[] = "What is your favorite color?";
    char t[] = "color?";
    
    result = strendp(s, t);
    printf("%d\n", result);
    return 0;
}

int strendp(char *s, char *t)
{
    char *tp = t;

    while (*s)
        *s++;
    while (*t)
        *t++;
    while (*s == *t) {
        *s--;
        *t--;
    }
    if (t >= tp)
        return 0;
    else
        return 1;
}
