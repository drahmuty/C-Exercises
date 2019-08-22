#include <stdio.h>

#define MAXLINE

int get_line(char line[], int maxline);
int trim_line(char line[]);

int main(void)
{
    int len;
    char line[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        line = trim_line(line);
        printf("%s", line);
}

int getline(char s[], int lim)
{
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!='0' && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++1;
    }
    s[i] = '\0';
    return i;
}

