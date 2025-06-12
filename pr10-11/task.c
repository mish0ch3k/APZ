#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Це дочірній процес
        printf("Дочірній процес:\n");
        printf("PID: %d\n", getpid());  
        printf("PID батьківського процесу: %d\n", getppid());
    } else {
        // Це батьківський процес
        wait(NULL);
    }

    return 0;
}

