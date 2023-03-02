#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    key_t k = ftok("kf", 1);
    int id = msgget(k, IPC_CREAT| 0644);

    system("ipcs -q");
    printf("---- After call msgctl-----\n");
    msgctl(id, IPC_RMID, NULL);
    system("ipcs -q");

    //msg sending needs two terminal. but i mind it.

    return 0;
}