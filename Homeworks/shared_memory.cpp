#include <sys/wait.h>
#include <sys/mman.h>
#include <iostream>
#include <semaphore.h>
#include <cstring>
#include <fcntl.h> 

#define SHM_NAME "/my_shared_memory"

struct SharedMemory
{
    sem_t *sem_parent;
    sem_t *sem_child;
    char message[256];
};

int main()
{
    SharedMemory *shm_ptr = (SharedMemory *)mmap(NULL, sizeof(SharedMemory),
                                                 PROT_READ | PROT_WRITE,
                                                 MAP_SHARED | MAP_ANONYMOUS,
                                                 -1, 0);

    if (shm_ptr == MAP_FAILED)
        perror("mmap");

    pid_t pid = fork();

    shm_ptr->sem_parent = sem_open("/sem_parent", O_CREAT, 0666, 1); 
    shm_ptr->sem_child = sem_open("/sem_child", O_CREAT, 0666, 0);   

    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        while (true)
        {
            sem_wait(shm_ptr->sem_child);

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;

            std::cout << "Child received: " << shm_ptr->message << std::endl;

            std::cout << "Child: ";
            std::cin.getline(shm_ptr->message, 256);

            sem_post(shm_ptr->sem_parent);

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;
        }
    }
    else
    {
        while (true)
        {
            sem_wait(shm_ptr->sem_parent);

            std::cout << "Parent: ";
            std::cin.getline(shm_ptr->message, 256);

            sem_post(shm_ptr->sem_child);

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;
        }
    }

    munmap(shm_ptr, sizeof(int));
    sem_close(shm_ptr->sem_parent);
    sem_close(shm_ptr->sem_child);
    sem_unlink("/sem_parent");
    sem_unlink("/sem_child");
    return 0;
}