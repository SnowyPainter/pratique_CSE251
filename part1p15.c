#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    
    int n = 0;
    extern char* optarg;
    if(argc == 1) {
        printf("-p, -n with sth, -h \n");
        return 0;
    }

    while((n = getopt(argc, argv, "hpn:")) != -1) {
        if(n == 'p') {
            printf("Welcome sys programming\n");
        }
        else if(n == 'n') {
            printf("%s\n", optarg);
        }
        else if(n == 'h') { 
            printf("-p, -n with sth, -h \n");
        }
    }
}