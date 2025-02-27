#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
    stop = 1;
}


//ps aux | grep 'daemon' - to check the daemon procceses
int main() {
    pid_t pid;

    // Step 1: Fork to create a new process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Step 2: Parent exits, child continues as daemon
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Step 3: Create a new session and become session leader
    if (setsid() < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

    // Step 4: Change working directory to root
    if (chdir("/") < 0) {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    // Step 5: Close all open file descriptors
    for (int i = 0; i < sysconf(_SC_OPEN_MAX); i++) {
        close(i);
    }

    // Step 6: Redirect stdin, stdout, and stderr to /dev/null
    open("/dev/null", O_RDWR); // stdin
    dup(0);                    // stdout
    dup(0);                    // stderr

    // Signal handling
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    // Daemon main loop
    while (!stop) {
        sleep(5);
        FILE *fp = fopen("/tmp/daemon.log", "a");
        if (fp) {
            fprintf(fp, "Daemon is running...\n");
            fclose(fp);
        }
    }

    return 0;
}
