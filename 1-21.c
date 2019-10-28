// entab program

#include <stdio.h>

#define TAB 4

int main(void)
{
    int c, pos, ns, nt;
    
    pos = 1;
    nt = ns = 0;
    while ((c = getchar()) != EOF) {
        while (c == ' ') {
            if (pos % TAB == 0) {
                nt++;
                ns = 0;
            } else
                ns++;
            pos++;
            c = getchar();
        }
        for ( ; nt > 0; nt--)
            putchar('\t');
        for ( ; ns > 0; ns--)
            putchar(' ');
        if (c == '\n') {
            putchar(c);
            pos = 1;
        } else if (c == '\t') {
            putchar(c);
            pos += TAB - (pos - 1) % TAB;
        } else {
            putchar(c);
            pos++;
        }
    }
}
