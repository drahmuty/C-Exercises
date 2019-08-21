#include <stdio.h>

int f_to_c(int);
int c_to_f(int);

int main(void)
{
    int i, min, max, inc;
    
    // Compute Fahrenheit to Celsius
    min = 0;
    max = 200;
    inc = 20;
    
    printf("F\tC\n");
    
    for (i = min; i <= max; i = i + inc)
        printf("%d\t%d\n", i, f_to_c(i));
    
    // Compute Celsius to Fahrenheit
    min = 0;
    max = 100;
    inc = 10;
    
    printf("\nC\tF\n");
    
    for (i = min; i <= max; i = i + inc)
        printf("%d\t%d\n", i, c_to_f(i));
}

int f_to_c(x)
{
    return (5.0 / 9.0) * (x - 32);
}

int c_to_f(x)
{
    return (9.0 / 5.0) * x + 32;
}
