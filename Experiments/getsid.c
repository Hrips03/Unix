#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t sid;
    sid = getsid(0);
    if (sid == -1)
        perror("getsid"); 
    else
        printf("My session id = %d\n", sid);
}