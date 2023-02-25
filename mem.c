#include <stdlib.h>

int main() {
    int bytes = 100;
    char *p = malloc(sizeof(char) * bytes);
    
    char *arr = calloc(10, 10);

    char *new = realloc(p, sizeof(char) * 20)

    free(p);
    free(arr);

    return 0;
}