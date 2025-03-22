#include <sys/wait.h>
#include <sys/mman.h>
#include <iostream>

int main()
{
    int *shared_var = (int *)mmap(NULL, sizeof(int),
                                  PROT_READ | PROT_WRITE,
                                  MAP_SHARED | MAP_ANONYMOUS,
                                  -1, 0);

    if (shared_var == MAP_FAILED)
        perror("mmap");

    pid_t pid = fork();

    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        std::cout << "Child process's shared_var = " << *shared_var << "\n";
        *shared_var = 5;

        //inchi hamara msync()-y ete meka popoxutyunnery erevum en aranc dra el
        if (msync(shared_var, sizeof(int), MS_SYNC) == -1)
        {
            perror("msync");
            return 1;
        }

        std::cout << "Child process's shared_var after modification = " << *shared_var << "\n";
    }
    else
    {
        wait(NULL);
        std::cout << "Parent process's shared_var = " << *shared_var << "\n";
        *shared_var = 15;
        std::cout << "Parent process's shared_var after modification = " << *shared_var << "\n";
    }

    munmap(shared_var, sizeof(int));
    return 0;
}