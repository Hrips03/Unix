#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

double calculateAreaOfTriangle(double height, double base)
{
    return 0.5 * height * base;
}

int main(){
    printf("This is a child process after exec, and the area of triangle is: %g\n", calculateAreaOfTriangle(5, 6));
}