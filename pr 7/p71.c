#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[256];

    fp = popen("who", "r");
    if (fp == NULL) {
        perror("popen failed");
        return 1;
    }

    FILE *more = popen("more", "w");
    if (more == NULL) {
        perror("popen for more failed");
        pclose(fp);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fputs(buffer, more);
    }

    pclose(fp);
    pclose(more);

    return 0;
}
