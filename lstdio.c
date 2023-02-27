#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    //copy machine

    int fd = open("readme.md", (O_RDONLY));
    if(fd == -1) {
        perror("fd"); 
        exit(1);
    }
    int fd2 = open("hello.test", (O_CREAT | O_WRONLY), (S_IWUSR | S_IRUSR | S_IXUSR));
    if(fd2 == -1) {
        perror("fd2");
        exit(1);
    }
    
    int n = 0;
    char buf[10];

    while((n = read(fd, buf, 5)) > 0) {
        int k = write(fd2, buf, n);
        if(k != n) perror("write buf to fd2");
    }

    close(fd);
    close(fd2);
    return 0;
}