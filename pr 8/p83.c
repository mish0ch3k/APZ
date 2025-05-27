#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int is_sorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i-1] > a[i]) return 0;
    return 1;
}

void test(const char *name, void (*fill)(int *, int)) {
    int *a = malloc(N * sizeof(int));
    fill(a, N);

    clock_t t1 = clock();
    qsort(a, N, sizeof(int), cmp);
    clock_t t2 = clock();

    printf("%-10s: %.3fs | sorted: %s\n", name,
           (double)(t2 - t1) / CLOCKS_PER_SEC,
           is_sorted(a, N) ? "yes" : "NO");

    free(a);
}

void sorted(int *a, int n) {
    for (int i = 0; i < n; i++) a[i] = i;
}

void reversed(int *a, int n) {
    for (int i = 0; i < n; i++) a[i] = n - i;
}

void randoms(int *a, int n) {
    for (int i = 0; i < n; i++) a[i] = rand();
}

int main() {
    srand(time(NULL));

    test("Sorted", sorted);
    test("Reversed", reversed);
    test("Random", randoms);

    return 0;
}
