#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

double calculateAreaOfTriangle(double height, double base)
{
    return 0.5 * height * base;
}

int main()
{
    double height = 0;
    double base = 0;
    printf("Enter a height of triangle: ");
    scanf("%lf", &height);
    printf("Enter a base of triangle: ");
    scanf("%lf", &base);
    printf("This is a child process after exec, and the area of triangle is: %g\n", calculateAreaOfTriangle(height, base));
    return 0;
}