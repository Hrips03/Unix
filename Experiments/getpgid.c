#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t child_pid, pgid_parent, pgid_child;

    // Get the process group ID of the parent process
    pgid_parent = getpgid(0);
    printf("Parent Process Group ID: %d\n", pgid_parent);

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Inside the child process

        // Set the process group ID of the child to its own PID
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            exit(EXIT_FAILURE);
        }

        // Get the process group ID of the child process
        pgid_child = getpgid(0);
        printf("Child Process Group ID: %d\n", pgid_child);

        // Keep the child process running to observe the group ID
        while (1) {
            sleep(1);
        }
    } 

    return 0;
}
