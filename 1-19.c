#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse_line(char s[]);

int main(void)
{
    int len;
    char line[MAXLINE];
    
    while (get_line(line, MAXLINE) > 0) {
        reverse_line(line);
        printf("%s", line);
    }
}

int get_line(char s[], int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!='0' && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse_line(char s[])
{
    int i, j;
    char t[MAXLINE];
    
    i = j = 0;
    while (s[i] != '\n')
        ++i;
    --i;
    while (i >= 0) {
        t[j] = s[i];
        --i;
        ++j;
    }
    if (j >= 0)
        t[j] = '\n';
    i = 0;
    while (t[i] != '\n') {
        s[i] = t[i];
        ++i;
    }
}
