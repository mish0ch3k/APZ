#include <stdio.h>
#include <unistd.h>

int main() {

    system("ls -l $HOME");
    system("ls -l /usr/bin | head -n 5");
    system("ls -l /etc | head -n 5");

    const char *files[] = {"/etc/passwd", "/usr/bin/ls", "/etc/shadow"};
    for (int i = 0; i < 3; i++) {
        printf("\nФайл: %s\n", files[i]);
        printf("Читання: %s\n", access(files[i], R_OK) == 0 ? "так" : "ні");
        printf("Запис: %s\n", access(files[i], W_OK) == 0 ? "так" : "ні");
        printf("Виконання: %s\n", access(files[i], X_OK) == 0 ? "так" : "ні");
    }

    return 0;
    
}
