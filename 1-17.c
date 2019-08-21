#include <stdio.h>

#define MAXLINE 1000
#define MAXITEMS 100
#define THRESHOLD 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int i, j;
    int len;
    
    int item[MAXLINE];
    int items[MAXITEMS];
    
    for (i = 0; i < MAXITEMS; i++)
        items[i] = item;
    
    while ((len = get_line(line, MAXLINE) > 0)) {
        
    }
}

int get_line(char[s], int lim)
{
    inc c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!='0' && c!='\n'); ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
          ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
