#include <stdio.h>

#define MAXLINE 1000
#define THRESHOLD 10    // Changed from 80 to 10 for easier testing

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int i, j;
    int len;
    char line[MAXLINE];
    char item[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            copy(item, line);
            printf("%s\n", item);
        }
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

void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
