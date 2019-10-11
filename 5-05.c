#include <stdio.h>
#include <string.h>

#define SIZE 100

char *strncpy_custom(char *, char *, int);
char *strncat_custom(char *, char *, int);
int strncmp_custom(char *, char *, int);

int main(void)
{
    char a[] = "Hello, world!";
    char b[SIZE];
    char c[] = "My name is ";
    char d[] = "David Ahmuty";
    char e[] = "Apple";
    char f[] = "Applf";
    int result;
    
    strncpy_custom(b, a, 9);
    printf("%s\n", b);
    
    strncat_custom(c, d, 3);
    printf("%s\n", c);
    
    result = strncmp_custom(e, f, 5);
    printf("%d\n", result);
    return 0;
}

char *strncpy_custom(char *s, char *ct, int n)
{
    while (n-- > 0 && (*s++ = *ct++) != '\0')
        ;
    *s = '\0';
    return s;
}

char *strncat_custom(char *s, char *ct, int n)
{
    while (*s)
        s++;
    while (n-- > 0 && (*s++ = *ct++) != '\0')
        ;
    *s = '\0';
    return s;
}

int strncmp_custom(char *cs, char *ct, int n)
{
    for ( ; n-- > 0 && *cs == *ct; cs++, ct++)
        if (*cs == '\0' || n <= 0)
            return 0;
    return *cs - *ct;
}
