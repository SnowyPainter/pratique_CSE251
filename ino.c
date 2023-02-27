#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    
    struct stat stb;
    if(stat("readme.md", &stb)) {
        perror("reading readme.md calling stat");
    } 
    printf("inode : %d\n", (int)stb.st_ino);

    return 0;
}