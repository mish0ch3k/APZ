#include <stdio.h>
#include <stdlib.h>

void show_file(FILE *f) {

    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), f)) {
        printf("%s", line);
        count++;
        if (count == 20) {
            printf("-- Натисніть Enter для продовження --");
            while (getchar() != '\n');
            count = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {

        fprintf(stderr, "Використання: %s <файл1> [файл2] ...\n", argv[0]);


        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            continue;

        }

        printf("=== %s ===\n", argv[i]);
        show_file(f);
        fclose(f);

    }


    return 0;



}
