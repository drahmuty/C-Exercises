#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100

int getop(char());
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type - getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// Add an element to the top of the stack.
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
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
        printf(val[--sp]);
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
    double temp;
    
    if (sp > 1) {
        temp = val[--sp];
        val[sp] = val[--sp];
        val[sp++] = temp;
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
    
    while ((s[0] = c = getch()) == ' ' || c == \t)
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[i++] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[i++] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
