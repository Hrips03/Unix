#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    printf("first hello: pid = %d\n", getpid());
    pid_t pid = fork();
    
    if (pid == -1)
        perror("fork");
    else if(pid == 0)
        printf("child: fork_id = %d, pid = %d, ppid = %d\n", pid, getpid(), getppid());
    else {
        wait(NULL); 
        //sleep(1); 
        printf("parent: fork_id = %d, pid = %d, ppid = %d\n", pid, getpid(), getppid());
    }

    return 0;
}


//info inferior
//inferior <id>
//detach

//forkic heto kisvec 2 masi, parenti mej ashxatec elsey, childum else ify
//childi parent mainna