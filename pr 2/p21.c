#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main() {
    time_t max_time = (time_t)((uintmax_t)-1 >> 1);
    
    printf("Максимальне значення time_t: %ld\n", (long)max_time);
    printf("Дата і час: %s", ctime(&max_time));
    
    printf("Розмір time_t: %zu байт\n", sizeof(time_t));
    if (sizeof(time_t) == 4) {
        printf("32-бітна система \n");
    } else {
        printf("64-бітна система \n");
    }
    
    return 0;
}
