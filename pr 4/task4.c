void *ptr = NULL;

while (<some-condition-is-true>) {
    if (!ptr)
        ptr = malloc(n);

    [... використання ptr ...]

    free(ptr);
    ptr = NULL;
}
