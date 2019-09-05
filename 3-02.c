#include <stdio.h>

#define MAX 1000

void escape_mod(char s[], char t[]);
void escape_mod_r(char s[], char t[]);

int main(void)
{
    char s[] = "This\tis\ta\ttest!\nIs\nit\nworking?";
    char t[MAX];
    char u[MAX];
    
    printf("ORIGINAL:\n%s\n\n", s);
    
    escape_mod(s, t);
    printf("ESCAPE:\n%s\n\n", t);
    
    escape_mod_r(t, u);
    printf("REVERSE:\n%s\n\n", u);
    
    return 0;
}

void escape_mod(char s[], char t[])
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    t[j] = '\0';
}

void escape_mod_r(char s[], char t[])
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        switch (s[i]) {
            case '\\':
                if (s[++i] == 't')
                    t[j++] = '\t';
                else if (s[i] == 'n')
                    t[j++] = '\n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    t[j] = '\0';
}
