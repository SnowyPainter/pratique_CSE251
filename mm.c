#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {

    int fd = open("readme.md", O_RDWR);
    struct stat b;
    stat("readme.md", &b);
    caddr_t addr = mmap(NULL, b.st_size, (PROT_READ|PROT_WRITE), MAP_SHARED, fd, 0);
    close(fd);

    printf("%s\n", addr);

    //un map
    munmap(addr, b.st_size);

    //use addr <-- core dumped, seg error.

    return 0;
}