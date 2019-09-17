#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP       100
#define NUMBER      '0'
#define MAXVAL      100
#define BUFSIZE     100
#define NAME        'n'

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void print_top(void);
void dup(void);
void swap(void);
void clear_stack(void);
void math_func(char s[]);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int type, mod1, mod2;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                math_func(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero division\n");
                break;
            case '%':
                mod2 = pop();
                mod1 = pop();
                if (mod2 != 0.0)
                    push(mod1 % mod2);
                else
                    printf("error: zero division\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 't':
                print_top();
                break;
            case 'd':
                dup();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear_stack();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// Return math function. I looked up this solution.
void math_func(char s[])
{
    double op2;
    
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("error: %s not supported", s);
}

// Add an element to the top of the stack.
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full can't push %g\n", f);
}

// Remove and return the top element of the stack.
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// Print the top element of the stack.
void print_top(void)
{
    if (sp > 0) {
        printf("%f\n", val[--sp]);
        sp++;
    }
    else
        printf("error: stack empty\n");
}

// Duplicate the top element of the stack.
void dup(void)
{
    double temp;
    
    if (sp > 0) {
        temp = val[--sp];
        sp++;
        push(temp);
    }
    else
        printf("error: stack empty\n");
}

// Swap the top two elements of the stack.
void swap(void)
{
    double temp1, temp2;
    
    if (sp > 1) {
        temp1 = val[--sp];
        temp2 = val[--sp];
        val[sp++] = temp1;
        val[sp++] = temp2;
    }
    else
        printf("error: not enough elements to swap\n");
}

// Clear the stack.
void clear_stack(void)
{
    while (sp >= 0)
        val[--sp] = '\0';
}

int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (c == 'n' && (c = getch()) == ' ') {
        while ((s[i++] = c = getch()) != ' ' && c != '\t')
            ;
        return 'NAME';
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
    if (isdigit(c) || c == '-')
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
