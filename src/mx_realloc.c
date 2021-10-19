#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (!ptr) {
        return malloc(size);
    }
    
    size_t new_size;
    void *new_ptr;

    new_size = malloc_size(ptr);

    if (size <= new_size) {
        return ptr;
    }

    new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}
