#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 10

int getch(void);
void ungetch(int);
int getfloat(double *);

char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int n;
    double array[SIZE];
    
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    n = 0;
    while (n < SIZE) {
        printf("%d: %f\n", n, array[n]);
        n++;
    }
    return 0;
}

int getfloat(double *pn)
{
    double val, power;
    int c, sign;
    
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }
    *pn = sign * *pn / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}
