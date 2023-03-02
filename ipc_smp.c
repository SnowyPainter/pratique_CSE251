#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

union semun {
    int val; struct semid_ds* buf; unsigned short* array;
};

int create_single_semaphore(key_t key) {
    union semun s;
    int id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666), status;
    if(id == -1 && errno == EEXIST)
        id = semget(key, 1, 0); //get existing semaphore
    else {
        s.val = 1;
        status = semctl(id, 0, SETVAL, s); //the size of semaphore group is 1, so the element's number is 0
    }
    return (id != -1 && status != -1) ? id : -1;
}

int p(int id) {
    struct sembuf b;
    b.sem_num = 0;
    b.sem_op = -1;
    return semop(id, &b, 1);
}
int v(int id) {
    struct sembuf b;
    b.sem_num = 0;
    b.sem_op = 1;
    return semop(id, &b, 1);
}
void child_process() {
    int id = create_single_semaphore(1);
    pid_t pid = getpid();
    if(id < 0) exit(1);
    p(id);
    printf("lock mode / critical : %d\n", (int)pid);

    //sleep(1000); <-- if there's no semaphore, then the other process will run.
    //It means, no semaphore -> use std io public

    v(id);
    exit(0);
}

int main() {
    for(int i = 0;i < 10;i++)
        if(fork() == 0) child_process();

    printf("done!\n");

    //delete semaphore ...
    //semctl(id, 0, IPC_RMID);
    return 0;
}