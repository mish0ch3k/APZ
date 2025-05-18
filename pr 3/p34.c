#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>

void limit(int seconds) {
    struct rlimit limit = {seconds, seconds};
    setrlimit(RLIMIT_CPU, &limit);
}

void generator(int *arr, int count, int max) {
    int *used = calloc(max + 1, sizeof(int));
    if (!used) {
        perror("помилка виділення пам’яті");
        exit(1);
    }

    for (int i = 0; i < count; ) {
        int num = rand() % max + 1;
        if (!used[num]) arr[i++] = used[num] = num;
    }

    free(used); 
}

int main() {
    srand(time(NULL));
    limit(1);

    int lotto_7[7], lotto_6[6];
    generator(lotto_7, 7, 49);
    generator(lotto_6, 6, 36);

    printf("7 із 49: "); for (int i = 0; i < 7; i++) printf("%d ", lotto_7[i]);
    printf("\n6 із 36: "); for (int i = 0; i < 6; i++) printf("%d ", lotto_6[i]);

    return 0;
}
