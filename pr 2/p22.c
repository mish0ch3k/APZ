#include <stdio.h>

void local()
{
    int a[1000];
    static int a2[1000] = {5};
}

int main()
{
    printf("Hello World\n");
    local();
    return 0;
}