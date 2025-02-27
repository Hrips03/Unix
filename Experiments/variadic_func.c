#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    va_list numbers; 
    va_start(numbers, count); 

    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += va_arg(numbers, int); 

    va_end(numbers); 
    return sum;
}

int main()
{
    printf("%d\n", sum(5, 1, 2, 3, 4, 5, NULL));
    printf("%d\n", sum(3, 4, 5, 7));
}