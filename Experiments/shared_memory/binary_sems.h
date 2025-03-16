#ifndef BINARY_SEMS_H
#define BINARY_SEMS_H

#include <sys/types.h>
#include "semun.h"
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void fatal(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int initSemAvailable(int semid, int semNum) {
    union semun arg;
    arg.val = 1; // Set the semaphore to available (1)
    return semctl(semid, semNum, SETVAL, arg);
}

int initSemInUse(int semid, int semNum) {
    union semun arg;
    arg.val = 0; // Set the semaphore to in-use (0)
    return semctl(semid, semNum, SETVAL, arg);
}

int reserveSem(int semid, int semNum) {
    struct sembuf sops;
    sops.sem_num = semNum;
    sops.sem_op = -1; // Decrement to reserve
    sops.sem_flg = 0;
    return semop(semid, &sops, 1);
}

int releaseSem(int semid, int semNum) {
    struct sembuf sops;
    sops.sem_num = semNum;
    sops.sem_op = 1; // Increment to release
    sops.sem_flg = 0;
    return semop(semid, &sops, 1);
}

#endif /* BINARY_SEMS_H */