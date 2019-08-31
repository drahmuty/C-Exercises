// Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze(char s[], int c);
void squeeze_mod(char s1[], char s2[]);

int main(void)
{
    // code goes here
}

void squeeze(char s[], int c)
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

void squeeze_mod(char s1[], char s2[])
{
    int i;
    
    for (i = 0; s2[i] != '\0'; i++) {
        squeeze(s1[], s2[i]);
    }
}
