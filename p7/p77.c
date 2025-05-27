#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;

    if (!dir) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir))) {
        if (strstr(entry->d_name, ".c")) {
            printf("Файл: %s\n", entry->d_name);
            char response;
            printf("Надати дозвіл на читання? (y/n): ");
            scanf(" %c", &response);

            if (response == 'y' || response == 'Y') {
                struct stat st;
                if (stat(entry->d_name, &st) == 0) {
                    chmod(entry->d_name, st.st_mode | S_IRUSR);
                    printf("Дозвіл на читання додано.\n");
                }
            }
        }
    }

    closedir(dir);
    return 0;
}
