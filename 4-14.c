#include <stdio.h>

#define swap(t,x,y) {   t temp = x; \
                        x = y; \
                        y = temp; }

int main(void)
{
    int x, y;
    
    x = 1, y = 2;
    printf("x = %d, y = %d\n", x, y);
    swap(int, x, y);
    printf("x = %d, y = %d\n", x, y);
}
