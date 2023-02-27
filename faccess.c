#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include <unistd.h>

int main() {

    struct stat stb;

    //to know what kind of file
    stat("readme.md", &stb);
    printf("kind : %o\n", (unsigned int)(stb.st_mode & S_IFMT));
    //macro ... checking equal
    printf("is regular file? : %d\n", S_ISREG(stb.st_mode));

    printf("group read permission : %d\n", stb.st_mode & (S_IREAD >> 3));

    //RUID access check
    printf("result : %d (-1 = fail, 0 ok)\n", access("readme.md", F_OK));

    return 0;
}