#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle = dlopen("./libmylibrary.so", RTLD_LAZY);
    if (!handle)
    {
        fprintf(stderr, "Error opening library: %s\n", dlerror());
        return 1;
    }

    dlerror();

    void (*hello)() = dlsym(handle, "hello");
    char *error = dlerror();
    if (error != NULL)
    {
        fprintf(stderr, "Error loading function: %s\n", error);
        return 1;
    }

    hello();

    dlclose(handle);

    return 0;
}