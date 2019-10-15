#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    leap = (year%4 == 0 && year%100 == 0) || year%400 == 0;
    if (year < 1) {
        printf("invalid year\n");
        return -1;
    }
    if (month < 1 || month > 12) {
        printf("invalid month\n");
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
        printf("invalid day\n");
        return -1;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap, maxyd;
    
    leap = (year%4 == 0 && year%100 == 0) || year%400 == 0;
    maxyd = (leap) ? 366 : 365;
    if (year < 1) {
        printf("invalid year\n");
        return;
    }
    if (yearday < 1 || yearday > maxyd) {
        printf("inavlid yearday\n");
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(void)
{
    int y, m, d, yd, pm, pd;
    
    y = 1991;
    m = 2;
    d = 16;
    yd = day_of_year(y, m, d);
    printf("yearday = %d\n", yd);
    pm = 4;
    pd = 2;
    printf("month = %d, day = %d\n", pm, pd);
    month_day(2001, 365, &pm, &pd);
    printf("month = %d, day = %d\n", pm, pd);
    return 0;
}
