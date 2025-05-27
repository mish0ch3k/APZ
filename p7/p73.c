#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f;
    char line[1024];

    if (argc != 3) return 1;

    f = fopen(argv[2], "r");
    if (!f) return 1;

    while (fgets(line, sizeof(line), f))
        if (strstr(line, argv[1]))
            printf("%s", line);

    fclose(f);
    return 0;
}
