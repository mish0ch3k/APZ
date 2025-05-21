#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024 * 1024 * 1024;
    void *ptr;

    while (1) {
        ptr = malloc(size);
        if (ptr) {
            printf("Успішно виділено: %zu байт (%.2f ГБ)\n", size, size / (1024.0 * 1024 * 1024));
            free(ptr);
            size *= 2; 
        } else {
            printf("Помилка виділення пам’яті на розмірі: %zu байт (%.2f ГБ)\n", size, size / (1024.0 * 1024 * 1024));
            break;
        }
    }

    return 0;
}