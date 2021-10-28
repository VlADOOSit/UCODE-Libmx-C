#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0)
        return -2;

    (*lineptr) = (char *) mx_realloc(*lineptr, buf_size);
    mx_memset((*lineptr), '\0', malloc_size((*lineptr)));
    size_t count_bytes = 0;
    char buf;

    if (read(fd, &buf, 1)) {
        if (buf == delim)
            return count_bytes;

        (*lineptr) = (char *) mx_realloc(*lineptr, count_bytes + 1);
        (*lineptr)[count_bytes] = buf;
        count_bytes++;
    }
    else
        return -1;

    while (read(fd, &buf, 1)) {
        if (buf == delim)
            break;
        
        if (count_bytes >= buf_size)
            (*lineptr) = (char *) mx_realloc(*lineptr, count_bytes + 1);

        (*lineptr)[count_bytes] = buf;

        count_bytes++;
    }

    (*lineptr) = (char *) mx_realloc(*lineptr, count_bytes + 1);

    size_t free_count_bytes = malloc_size((*lineptr)) - count_bytes;
    mx_memset(&(*lineptr)[count_bytes], '\0', free_count_bytes);

    return count_bytes + 1;
}
