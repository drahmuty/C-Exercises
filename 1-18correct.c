#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
int trim_line(char s[]);

int main(void)
{
    char line[MAXLINE];
    
    while (get_line(line, MAXLINE) > 0)
        if (trim_line(line) > 0)
            printf("%s", line);
    return 0;
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

int trim_line(char s[])
{
    int i;
    
    i = 0;
    while (s[i] != '\n')
        ++i;
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    }
    return i;
}
