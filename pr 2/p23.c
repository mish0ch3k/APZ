#include <stdio.h>
#include <stdlib.h>

int global_var = 42;
static int static_var = 99;

int main() {
    char large_array[1024 * 1024];

    int local_var;
    int *heap_var = (int *)malloc(sizeof(int));

    printf("Code segment: %p\n", (void *)main);
    printf("Data segment (global): %p\n", &global_var);
    printf("Data segment (static): %p\n", &static_var);
    printf("Stack top: %p\n", &local_var);
    printf("Heap segment: %p\n", heap_var);
    printf("New stack top: %p\n", &large_array);
    free(heap_var);
    return 0;
}
