#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{    
    printf("char min: %d\n", CHAR_MIN);
    printf("char max: %d\n", CHAR_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    printf("int min: %d\n", INT_MIN);
    printf("int max: %d\n", INT_MAX);
    printf("long min: %ld\n", LONG_MIN);
    printf("long max: %ld\n", LONG_MAX);

    printf("\n");

    printf("uchar max: %u\n", UCHAR_MAX);
    printf("ushort max: %u\n", USHRT_MAX);
    printf("uint max: %u\n", UINT_MAX);
    printf("ulong max: %lu\n", ULONG_MAX);

    return 0;
}
