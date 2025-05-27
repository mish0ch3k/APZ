#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define FILE_PATH "secure.txt"
#define OPEN_HOUR 9
#define CLOSE_HOUR 13

int is_allowed_hour() {
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int hour = timeinfo->tm_hour;
    return (hour >= OPEN_HOUR && hour < CLOSE_HOUR);
}

int main() {
    if (is_allowed_hour()) {
        chmod(FILE_PATH, 0644); // дозвіл на читання/запис для власника
        printf("Доступ дозволено: файл доступний\n");
    } else {
        chmod(FILE_PATH, 0000); // заборона доступу
        printf("Доступ заборонено: файл недоступний\n");
    }

    return 0;
}

