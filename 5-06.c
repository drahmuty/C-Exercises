#include <stdio.h>
#define MAXLINE 1000

int getline_p(char *, int);
int atoi_p(char *);
void itoa_p(int, char *);
void reverse_p(char *);
int strindex_p(char *, char *);
int getop_p(char *);

int main(void)
{
//     // getline test
//     int i;
//     char a[] = "Hello, world!";
    
//     i = getline_p(a, MAXLINE);
//     printf("%s (i = %d)\n", a, i);
    
//     // atoi test
//     char b[] = "12345";
//     i = atoi(b); 
//     printf("%d\n", i);
//     // reverse test
//     char s[] = "Hello, world!";
//     reverse_p(s);
//     printf("%s\n", s);
//     return 0;
    
    // // itoa test
    // int i = 12345;
    // char a[100];
    // itoa_p(i, a);
    // printf("%s\n", a);
    // return 0;

    // strindex test
    char a[] = "Hello, world!";
    char b[] = "Hd";
    int ans = strindex_p(a, b);
    printf("%d\n", ans);
    return 0;
}

int getline_p(char *s, int lim)
{
    int c;
    char *t = s;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

int atoi_p(char *s)
{
    int n;
    
    for ( ; *s >= '0' && *s <= '9'; s++)
        n = 10 * n + (*s - '0');
    return n;
}

void itoa_p(int n, char *s)
{
    int sign;
    char *t;
    
    t = s;
    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse_p(t);
}

void reverse_p(char *s)
{
    int c;
    char *t;

    t = s;
    while (*t)
        t++;
    for (--t; s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

int strindex_p(char *s, char *t)
{
    char *sp, *tp, *u;
    
    sp = s;
    tp = t;
    for ( ; *s != '\0'; s++) {
        for (u = s; *t != '\0' && *u == *t; t++, u++)
            printf("u = %d, t = %d\n", *u, *t);
        if (t > tp && *t == '\0')
            return s - sp;
    }
    return -1;
}

int getop_p(char *s)
{
    int c;
    char *t;
    
    t = s;
    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *++s = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    s = t;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER:
}
