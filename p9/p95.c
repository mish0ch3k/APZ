#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *file = "/tmp/mytemp.txt";

    FILE *f = fopen(file, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }
    fprintf(f, "Тестовий файл\n");
    fclose(f);

    printf("Зміна власника та прав доступу...\n");
    system("sudo chown root:root /tmp/mytemp.txt");
    system("sudo chmod 600 /tmp/mytemp.txt");

    f = fopen(file, "r");
    if (f) {
        printf("Читання дозволено\n");
        fclose(f);
    } else {
        printf("Читання заборонено\n");
    }

    f = fopen(file, "a");
    if (f) {
        printf("Запис дозволено\n");
        fclose(f);
    } else {
        printf("Запис заборонено\n");
    }

    return 0;
}
