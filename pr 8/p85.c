#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Дочірній процес 1 — ls
        close(pipefd[0]); // закриваємо читання
        dup2(pipefd[1], STDOUT_FILENO); // перенаправляємо stdout у pipe
        close(pipefd[1]);
        execlp("ls", "ls", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Дочірній процес 2 — wc -l
        close(pipefd[1]); // закриваємо запис
        dup2(pipefd[0], STDIN_FILENO); // перенаправляємо stdin з pipe
        close(pipefd[0]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp wc");
        exit(EXIT_FAILURE);
    }

    // Батьківський процес
    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}


