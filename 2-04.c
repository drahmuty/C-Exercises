// Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze_mod(char s1[], char s2[]);

int main(void)
{   
    char a[] = "can you hear me";
    char b[] = "no i can't";

    squeeze_mod(a, b);
    printf("%s\n", a);
}

void squeeze_mod(char s1[], char s2[])
{
    int i, j, k;
    
    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                i++;
            }
        s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
