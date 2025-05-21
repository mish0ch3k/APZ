#include <stdlib.h>

int main() {
    for (int i = 0; i < 100; i++) {
        malloc(1024);
    }

    return 0;
}

