#include <stdio.h>

int main(void)
{
    int a, b;
    
    while ((b = getchar()) != '0')      // Substituting '0' for EOF
    {
        if (b != ' ')
            putchar(b);
            
        if (b == ' ')
            if (a != ' ')
            putchar(b);
        
        a = b; 
    }
    
    return 0;
}
