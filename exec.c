#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void process1() {
    //child process will work "ls -al"

    if(execlp("ls", "ls", "-al", (char *)NULL) == -1) {
        exit(1);
    }
    exit(0);
    //return;
}

int main() {

    pid_t pid = fork();

    if(pid == 0) {
        printf("fork completed, child process PID : %d\n", (int)getpid());
        process1();
    } else if (pid == -1) {
        exit(1);
    } else {
        printf("parent, PID : %d\n", (int)getpid());
    }

    return 0;

}