#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {  // Child process
        printf( "Child PID: %d ", getpid());
        //sleep(10); // Give time to attach gdb
        // Your actual code here...
    } else if (pid > 0) {
        sleep(10);
        printf( "Parent PID: %d", getpid());
    } else {
        perror("fork failed");
    }
    return 0;
}
