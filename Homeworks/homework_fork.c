#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

double calculateArea(double height, double width){
    return height * width;
}

int main(){
    pid_t pid = fork();

    double side1 = 1.5;
    double side2 = 3.5;

    if (pid == -1)
        perror("fork");
    else if(pid == 0){
        side1 = 2;
        printf("This is a child process, and the area of triangle is: %g\n", 0.5 * calculateArea(side1, side2));
    }
    else{    
        printf("This is a parent process, and the area of rectangle is: %g\n", calculateArea(side1, side2));
    }

    return 0;
}