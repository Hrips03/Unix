#include <fcntl.h>   // open
#include <unistd.h>  // close
#include <stdio.h>   // printf

int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
    
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    close(fd);  // Always close when done!
    return 0;
}
