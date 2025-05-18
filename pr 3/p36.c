#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void func(int count) {
    printf("Recursion depth: %d\n", count);
    func(count + 1);
}

int main() {
    struct rlimit limit;
    
    getrlimit(RLIMIT_STACK, &limit);
    printf("Default stack size: %ld bytes\n", limit.rlim_cur);
    
    limit.rlim_cur = 64 * 50;
    setrlimit(RLIMIT_STACK, &limit);
    
    getrlimit(RLIMIT_STACK, &limit);
    printf("New stack size: %ld bytes\n", limit.rlim_cur);
    
    func(1);
    
    return 0;
}
