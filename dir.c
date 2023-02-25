#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#include <dirent.h>

int main() {
    DIR* dp;
    struct dirent* dent;

    dp = opendir(".");

    while((dent = readdir(dp))) {
        printf("Name : %s\n", dent->d_name);
    }

    return 0;
}