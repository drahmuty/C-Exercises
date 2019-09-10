#include <stdio.h>
#include <ctype.h>

double atof_sn(char s[])
{
    double val, power, eval, epower;
    int i, sign, esign;
    
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    else
        return val;
    esign = (s[i] == '-') ? 1 : 0;
    if (esign)
        i++;
    for (eval = 0.0; isdigit(s[i]); i++)
        eval = 10.0 * eval + (s[i] - '0');
    epower = 1.0;
    while (eval-- > 0)
        epower *= 10.0;
    if (esign)
        return val / epower;
    else
        return val * epower;
}

int main(void)
{
    char s[] = "5.1e-1";
    
    printf("%f\n", atof_sn(s));
}
