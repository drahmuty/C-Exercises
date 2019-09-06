#include <stdio.h>

#define MAX 1000

void expand(char s1[], char s2[])
{
    int i, j, k, first, last;
    
    i = j = 0;
    s2[j++] = s1[i++];
    for ( ; s1[i] != '\0'; i++) {
        if (s1[i] == '-') {
            first = s1[i-1], last = s1[i+1];
            if (first < last &&
                ((first >= 'a' && last <= 'z') ||
                (first >= 'A' && last <= 'Z') ||
                (first >= '0' && last <= '9')))
                for (k = first + 1; k < last; k++)
                    s2[j++] = k;
            else
                s2[j++] = s1[i];
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

int main(void)
{
    char s1[] = "I can spell the alphabet A to Z!\nA-Z\na-z\nI can count from 0 to 9 too!\n0-9\n";
    char s2[MAX];
    
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}
