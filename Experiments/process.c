#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
    pid_t id = getpid();
    printf("Process PID = %jd\n", (__intmax_t) id);
    pid_t parent_id = getppid();
    printf("Process Parent PID = %jd\n", (__intmax_t) parent_id);
    return 0;
}