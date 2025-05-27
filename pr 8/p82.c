#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("test.bin", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    unsigned char data[] = {4, 5, 2, 2, 3, 3, 7, 9, 1, 5};
    write(fd, data, 10);
    close(fd);

    fd = open("test.bin", O_RDONLY);
    lseek(fd, 3, SEEK_SET);

    unsigned char buffer[4];
    read(fd, buffer, 4);

    for (int i = 0; i < 4; i++)
        printf("%d ", buffer[i]);
    printf("\n");

    close(fd);
    return 0;
}
