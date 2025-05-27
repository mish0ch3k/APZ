#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main() {

    DIR *dir = opendir(".");
    struct dirent *entry;
    char response;

    if (!dir) {
        perror("opendir");

        return 1;

    }

    while ((entry = readdir(dir))) {

        if (entry->d_name[0] != '.') {  
            printf("Файл: %s\n", entry->d_name);
            printf("Видалити цей файл? (y/n): ");
            scanf(" %c", &response);

            if (response == 'y' || response == 'Y') {
                if (remove(entry->d_name) == 0) {
                    printf("Файл %s видалено.\n", entry->d_name);
                } else {
                    perror("Не вдалося видалити файл");
                }
            }
        }
    }

    closedir(dir);

    return 0;
    
}
