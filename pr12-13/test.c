#include <stdio.h>

int main() {
    int *p = NULL;
    *p = 42; // Викликає SIGSEGV
    return 0;
}

