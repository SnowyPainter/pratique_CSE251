#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {

    struct stat b;
    stat("readme.md", &b);
    printf("%d\n", b.st_nlink);
    
    symlink("readme.md", "readme.sym");
    char bf[BUFSIZ];
    realpath("readme.sym", bf);
    printf("%s\n", bf);

    return 0;
}