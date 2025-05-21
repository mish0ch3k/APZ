#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int x;
    double y;
};

int main() {
    struct sbar *ptr, *newptr;

    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) {
        fprintf(stderr, "Помилка при calloc\n");
        return 1;
    }

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        fprintf(stderr, "Помилка при reallocarray\n");
        free(ptr);
        return 1;
    }

    newptr[0].x = 42;
    free(newptr) ;
    return 0 ;
}
