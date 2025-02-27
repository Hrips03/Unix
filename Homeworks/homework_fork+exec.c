#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

double calculateAreaOfRectangle(double height, double width)
{
    return height * width;
}

int main()
{
    pid_t pid = fork();

    double side1 = 1.5;
    double side2 = 3.5;

    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        int ret = execl("./procexec", "procexec", NULL);
        if (ret == -1)
        {
            perror("execl");
        }
    }
    else
    {
        int status;
        wait(&status);
        // wait(NULL);
        printf("This is a parent process, and the area of rectangle is: %g\n", calculateAreaOfRectangle(side1, side2));
    }

    return 0;
}