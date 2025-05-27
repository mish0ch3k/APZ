#include <stdio.h>
#include <time.h>

int main() {

    clock_t start = clock();

    for (int i = 0; i < 1000000; i++) {
        int x = i * i;
    }

    clock_t end = clock();

    printf("Час : %.2f мс\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);

    return 0;

}
