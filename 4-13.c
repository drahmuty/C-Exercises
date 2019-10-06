#include <stdio.h>
#include <string.h>

void reverse_rec(char s[]);

int main(void)
{
    char a[] = "node";
    reverse_rec(a);
    printf("%s\n", a);
}

void reverse_rec(char s[])
{
    static int i = 0;
    static int j = 1;
    int c, k;
    
    k = strlen(s) - j++;
    if (i < k) {
        c = s[i];
        s[i++] = s[k];
        s[k] = c;
        reverse_rec(s);
    }
}
