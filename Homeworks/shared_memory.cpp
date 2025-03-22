#include <sys/wait.h>
#include <sys/mman.h>
#include <iostream>
#include <semaphore.h>
#include <cstring>

#define SHM_NAME "/my_shared_memory"

struct SharedMemory
{
    sem_t sem_parent;
    sem_t sem_child;
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

    if (pid == -1)
        perror("fork");
    else if (pid == 0)
    {
        while (true)
        {
            sem_wait(&shm_ptr->sem_child); // Wait for parent

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;

            std::cout << "Child received: " << shm_ptr->message << std::endl;

            std::cout << "Child: ";
            std::cin.getline(shm_ptr->message, 256);

            sem_post(&shm_ptr->sem_parent); // Signal parent

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;
        }
    }
    else
    {
        sem_init(&shm_ptr->sem_parent, 1, 1); // Parent starts unlocked
        sem_init(&shm_ptr->sem_child, 1, 0);  // Child starts locked

        while (true)
        {
            sem_wait(&shm_ptr->sem_parent); // Wait for child to read previous message

            std::cout << "Parent: ";
            std::cin.getline(shm_ptr->message, 256);

            sem_post(&shm_ptr->sem_child); // Signal child

            if (strcmp(shm_ptr->message, "exit") == 0)
                break;
        }

        sem_destroy(&shm_ptr->sem_parent);
        sem_destroy(&shm_ptr->sem_child);
    }

    munmap(shm_ptr, sizeof(int));
    shm_unlink(SHM_NAME);
    return 0;
}