#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "p33.txt"
#define MAX_FILE_SIZE 1024
#define MAX_ROLLS 100

int main() {

    srand(time(NULL));

    FILE *file = fopen(FILE_NAME, "a+");
    if (!file) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    fseek(file, 0, SEEK_END); 
    long size = ftell(file);

    for (int i = 0; i < MAX_ROLLS && size < MAX_FILE_SIZE; i++) {

        int result = (rand() % 6) + 1;
        size += fprintf(file, "%d\n", result); 
        printf("%d ", result);
    }

    if (size >= MAX_FILE_SIZE) 

        printf("\nЛіміт файлу вичерпано(запис зупинено).\n");

    fclose(file);

    return 0;

}