#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    printf("first hello: pid = %d\n", getpid()); //1
    
    pid_t pid = fork();
    if (pid == -1)
        perror("fork");
    
    printf("Message 2\n"); //2

    fork();
    printf("Message 3\n"); //4

    fork();
    printf("Message 4\n"); //8
    
    return 0;
}


