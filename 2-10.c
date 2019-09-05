#include <stdio.h>

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int lower_mod(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main(void)
{
    int c = 'B';
    printf("%d\n", lower(c));
    printf("%d\n", lower_mod(c));
}
