#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int leap;
    char *y, *m;
    
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
        y = daytab+1;
    else
        y = daytab;
    for (m = y; month > 0; month--, m++)
        day += *m;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, month;
    char *y, *m;
    
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
        y = daytab+1;
    else
        y = daytab;
    for (m = y+1; yearday > *m; m++)
        yearday -= *m;
    *pmonth = m - y;
    *pday = yearday;
}

int main(void)
{
    int y, m, d, yd, pm, pd;
    
    y = 1991;
    m = 10;
    d = 1;
    yd = day_of_year(y, m, d);
    printf("yearday = %d\n", yd);
    pm = 4;
    pd = 2;
    printf("month = %d, day = %d\n", pm, pd);
    month_day(2000, yd, &pm, &pd);
    printf("month = %d, day = %d\n", pm, pd);
    return 0;
}
