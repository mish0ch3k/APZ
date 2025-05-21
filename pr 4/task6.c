#include <stdio.h>
#include <stdlib.h>

int main() {
    char *ptr = realloc(NULL, 100);
    if (ptr) {
        printf("realloc(NULL, 100): пам'ять виділено\n");
        free(ptr);
    }

    ptr = malloc(50);
    ptr = realloc(ptr, 0);
    if (ptr == NULL) {
        printf("realloc(ptr, 0): пам'ять звільнено повернено NULL\n");
    }

    return 0;
}
