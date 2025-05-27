#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    const char *filename = "/tmp/testfile.txt";
    const char *copyname = getenv("HOME");
    char fullpath[1024];
    snprintf(fullpath, sizeof(fullpath), "%s/copied_by_root.txt", copyname);

    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("fopen (create)");
        return 1;
    }
    fprintf(fp, "Це тестовий файл\n");
    fclose(fp);
    printf("Файл створено: %s\n", filename);

    printf("Копіювання файлу від імені root...\n");
    char cmd[2048];
    snprintf(cmd, sizeof(cmd), "sudo cp %s %s", filename, fullpath);
    system(cmd);

    printf("\nls -l %s:\n", fullpath);
    snprintf(cmd, sizeof(cmd), "ls -l %s", fullpath);
    system(cmd);

    printf("\nСпроба редагувати файл...\n");
    fp = fopen(fullpath, "a"); 
    if (!fp) {
        perror("fopen (append)");
    } else {
        fprintf(fp, "Дописано звичайним користувачем\n");
        fclose(fp);
        printf("Успішно змінено файл\n");
    }

    printf("\nСпроба видалити файл...\n");
    if (remove(fullpath) == 0) {
        printf("Файл успішно видалено\n");
    } else {

        perror("remove");
    }

    return 0;
    
}
