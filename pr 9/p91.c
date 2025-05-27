#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *fp = popen("getent passwd", "r");
    if (!fp) return 1;

    char line[1024];
    char *me = getlogin();
    if (!me) me = getenv("USER");

    while (fgets(line, sizeof(line), fp)) {
        char *user = strtok(line, ":");
        strtok(NULL, ":");
        char *uid_str = strtok(NULL, ":");

        if (!user || !uid_str) continue;

        int uid = atoi(uid_str);
        if (uid >= 1000 && me && strcmp(user, me) != 0) {
            printf("Користувач: %s (UID=%d)\n", user, uid);
        }
    }

    pclose(fp);
    return 0;
}
