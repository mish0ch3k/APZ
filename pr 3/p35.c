#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Program need two arguments\n");
        return 1;
    }
    
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("Cannot open source file");

        return 1;
    }
    
    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Cannot open destination file");
        close(src_fd);
        return 1;
    }
    
    char buffer[BUFFER_SIZE];
    ssize_t bytes;
    while ((bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes) != bytes) {
            perror("Error writing file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    close(src_fd);
    close(dest_fd);

    return 0;




}
