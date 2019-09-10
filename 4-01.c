#include <stdio.h>

int strindexr(char s[], char t[])
{
    int i, j, k, match;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            match = i;
        if (s[i] == '\0')
            return match;
    }
    return -1;
}

int main(void)
{
    char s[] = "dave this is a dave test to find dave a pattern for dave okay dave great thanks";
    char t[] = "dave";
    
    printf("%d\n", strindexr(s, t));
    return 0;
}
