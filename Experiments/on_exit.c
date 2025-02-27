#include <stdio.h>
#include <stdlib.h>

void cleanup(int exit_status, void *arg) {
    printf("Cleanup function called. Exit status: %d\n", exit_status);
    printf("Message: %s\n", (char *)arg);
}

int main() {

    if (on_exit(cleanup, "Program is terminating!") != 0) {
        fprintf(stderr, "Failed to register exit handler\n");
        return 1;
    }
    printf("Main function is running...\n");

    //The exit_status is set automatically by the system, void *arg: is given by the user
    //return 42;  // / This will set `exit_status = 42` in cleanup()
    //exit(42);  // This will set `exit_status = 42` in cleanup()
    return 0;  // / This will set `exit_status = 0` in cleanup()
}
//valgrind