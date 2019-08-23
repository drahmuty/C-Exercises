#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void trim_line(char trimmed[], char line[], int len);

int main(void)
{
    int len;
    char line[MAXLINE];
    char trimmed[MAXLINE];
    
    while ((len = get_line(line, MAXLINE)) > 0) {
        trim_line(trimmed, line, len);
        printf("%s", trimmed);
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

void trim_line(char to[], char from[], int i)
{
    int j;
    for (j = 0; to[j] != '\0'; ++j) {
        to[j] = '\0';
    }
    if (from[i] == '\0') {
        printf("%d ZERO FOUND\n", i);
        to[i] = from[i];
        --i;
    }
    if (from[i] == '\n') {
        printf("%d N FOUND\n", i);
        to[i] = from[i];
        --i;
    }
    while (i >= 0 && (from[i] == ' ' || from[i] == '\t')) {
        printf("%d %d\n", i, from[i]);
        --i;
    }
    while (i >= 0) {
        printf("%d %d ADDED\n", i, from[i]);
        to[i] = from[i];
        --i;
    }
}
