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

        double height = 0;
        double weidth = 0;

        printf("Enter a height of rectangle: ");
        scanf("%lf", &height);
        printf("Enter a weidth of rectangle: ");
        scanf("%lf", &weidth);
        printf("This is a parent process, and the area of rectangle is: %g\n", calculateAreaOfRectangle(height, weidth));
    }

    return 0;
}