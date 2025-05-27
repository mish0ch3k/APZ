#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand((unsigned int)time(NULL));

    float rand_num_0_to_1 = (float)rand() / RAND_MAX;
    printf("Випадкове число від 0.0 до 1.0: %.6f\n", rand_num_0_to_1);

    float n;
    printf("Введіть значення n (дійсне число з плаваючою точкою): ");

    scanf("%f", &n);

    float rand_num_0_to_n = (float)rand() / RAND_MAX * n;
    printf("Випадкове число від 0.0 до %.2f: %.6f\n", n, rand_num_0_to_n);

    return 0;
    
}
