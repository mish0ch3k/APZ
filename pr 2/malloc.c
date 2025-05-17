#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    size_t size = 1024 * 1024 * 10; // 10 MB
    char *ptr = malloc(size);
    if (!ptr) {
        perror("malloc");
        return 1;
    }
    memset(ptr, 'A', size);
    printf("malloc pointer: %p\n", ptr);
    getchar(); 
    free(ptr);
    return 0;
}
