#include <stdio.h>

void strcatp(char *, char *);

int main(void)
{
    char s[] = "Hello";
    char t[] = ", world!";
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    strcatp(s, t);
    printf("s: %s\n", s);
    return 0;
}

void strcatp(char *s, char *t)
{
    while (*s++)
        ;
    *s--;
    while ((*s++ = *t++))
        ;
}
