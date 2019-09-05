#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        printf("low: %d  mid: %d  high: %d  val: %d\n", low, mid, high, v[mid]);
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch_mod(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        printf("low: %d  mid: %d  high: %d  val: %d\n", low, mid, high, v[mid]);
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

int main(void)
{
    int x = 5;
    int v[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    
    int m1 = binsearch(x, v, n);
    int m2 = binsearch_mod(x, v, n);
    
    printf("%d\n", m1);
    printf("%d\n", m2);
}
