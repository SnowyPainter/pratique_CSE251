#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    //write child -> parent pipe
    //read parent -> child pipe
    int p4c[2], c4p[2];
    int st, len;
    pid_t pid;
    char buf[257];

    pipe(p4c);
    pipe(c4p);

    switch (pid = fork())
    {
    case 0: //child process
        close(c4p[0]);
        close(p4c[1]);
        len = read(p4c[0], buf, 256);
        printf("%s\n", buf);
        strcpy(buf, "child process IPC");
        write(c4p[1], buf, strlen(buf));
        break;
    default: //parent
        close(c4p[1]); //close, child write to parent. only read
        close(p4c[0]); //close, parent read from child. only write
        const char * str = "parent send it. IPC";
        write(p4c[1], str, strlen(str));
        len = read(c4p[0], buf, 256);
        printf("receieved from child : %s\n", buf);

        waitpid(pid, &st, 0); // wait for child process die
        break;
    }

    return 0;
}