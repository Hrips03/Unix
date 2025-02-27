#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return -1;
    }
    else if (pid != 0)
        exit(EXIT_SUCCESS);
    
    printf("My session id = %d\n", setsid());

    return 0;
}