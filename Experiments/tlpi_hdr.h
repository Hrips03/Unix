#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit, malloc, free, atoi
#include <unistd.h>     // close, read, write, fork, exec
#include <errno.h>      // errno
#include <string.h>     // memset, strcpy, strerror
#include <fcntl.h>      // open, O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
#include <sys/types.h>  // pid_t, size_t, ssize_t
#include <sys/stat.h>   // struct stat, chmod
#include <sys/wait.h>   // wait, waitpid
#include <sys/mman.h>   // mmap, munmap
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // sockaddr_in
#include <arpa/inet.h>  // inet_pton, inet_ntop
#include <signal.h>     // signal, sigaction, kill
#include <time.h>       // time, clock_gettime
#include <dirent.h>     // opendir, readdir, closedir
#include <stdarg.h>

void errExit(const char *format, ...) {
    va_list args;
    
    // Print custom error message
    fprintf(stderr, "Error: ");
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    // Print system error message (if errno is set)
    if (errno != 0) {
        fprintf(stderr, ": %s", strerror(errno));
    }
    
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

void fatal(const char *msg);