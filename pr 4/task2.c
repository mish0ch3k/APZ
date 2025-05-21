#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1000000;
    int xb = 5000;
    int num = xa * xb;

    printf("xa = %d, xb = %d\n", xa, xb);
    printf("num (xa * xb) = %d\n", num);
    printf("передається в malloc: %zu байт\n", (size_t)num);

    void *ptr = malloc(num);

    if (ptr == NULL) {
        printf("malloc не зміг виділити пам’ять \n");
    } else {
        printf("malloc виділив пам’ять потенційна помилка!\n");
        free(ptr);
    }

    return 0;
}
