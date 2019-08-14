#include <stdio.h>

int main(void)
{
    int a, b;
    
    while ((b = getchar()) != '0')      // Substituting '0' for EOF
    {
        if (b != ' ')
            putchar(b);
            
        if (b == ' ')
            if (a != ' ')               // This can be condnsed to one line, but I'm keeping with the pace of the book
            putchar(b);
        
        a = b; 
    }
    
    return 0;
}
