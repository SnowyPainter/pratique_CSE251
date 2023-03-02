#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void child_process(char* addr) {
    strcpy(addr, "child process sent it.");    
    shmdt((char *)addr);
    exit(9);
}

int main() {

    int id = shmget(IPC_PRIVATE, 1, IPC_CREAT|0644);
    char* for_child, *for_parent; //not for a two way IPC. to block segment.

    switch(fork()) {
        case 0: //child process
        for_child = (char *)shmat(id, NULL, 0);
        child_process(for_child);
        break;
        default:
        wait(1); //wait for working child process
        for_parent = (char *)shmat(id, NULL, 0);
        printf("%s\n", for_parent);
        shmdt((char *)for_parent); // close memory space

        //final work.
        shmctl(id, IPC_RMID, NULL); // close memory space & destroy struct ds
        break;
    }
    return 0;
}