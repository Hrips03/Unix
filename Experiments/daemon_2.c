#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t stop = 0;

void handle_signal(int sig) {
    stop = 1;
}

// ps aux | grep 'daemon' - to check the daemon processes
int main() {
    // Create the daemon
    if (daemon(0, 0) == -1) {
        perror("daemon");
        exit(EXIT_FAILURE);
    }

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
