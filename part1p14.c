#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc < 3) return -1;

    int n, m, sum = 0;
    n = atoi(argv[1]);
    m = atoi(argv[2]);

    for(int i = n;i <= m;i++)
        sum += i;
    printf("%d\n", sum);

    return 0;
}