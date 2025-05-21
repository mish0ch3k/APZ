#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t big_size = (size_t)1 << 40;
    char *ptr = malloc(100);
    if (!ptr) {
        perror("malloc");
        return 1;
    }

    strcpy(ptr, "Hello");

    char *new_ptr = realloc(ptr, big_size);
    if (new_ptr == NULL) {
        printf("realloc не зміг виділити %zu байтів\n", big_size);
        printf("Старий вказівник дійсний: %s\n", ptr);
        free(ptr);  
    } else {
        printf("realloc успішний: %s\n", new_ptr);
        free(new_ptr);
    }

    return 0;
}
