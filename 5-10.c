#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

void push(double);
double pop(void);

int main(int argc, char *argv[])
{    
    int type;
    double op2;
    char s[MAXOP];
    
    if (argc < 4)
        printf("Usage: expr a b +\n");
    while (--argc > 0 && (type = *++argv)) {
        /* Insert reverse polish calculator code here.
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            ...
        }
        */
    }
    return 0;
}
