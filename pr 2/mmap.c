#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = 1024 * 1024 * 10; // 10 MB
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
    memset(ptr, 'B', size);
    printf("mmap pointer: %p\n", ptr);
    getchar(); // щоб перевірити pmap
    munmap(ptr, size);
    return 0;
}
