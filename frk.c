#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void childdie() {
    printf("child die\n");
}
void parentdie() {
    printf("parent die\n");
}

int main() {

    //run a process. fork run myself.

    pid_t pid;

    switch(pid = fork()) {
        case 0: //child process
            printf("child process, pid : %d\n", (int)getpid());
            atexit(childdie);
            break;
        default: //just me. (parent of child process). the value is pid.
            printf("pid : %d\n", (int)getpid());
            atexit(parentdie);
            break;
    }

    exit(0);
    //return 0;
}