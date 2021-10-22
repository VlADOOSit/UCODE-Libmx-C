#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size < 0 || fd < 0) {
        return -2;
    }
    (*lineptr) = (char *) mx_realloc(*lineptr, buf_size);
    char buf;
    size_t result = 0;
    bool check = false;
    while(1) {
        if(!read(fd, &buf, 1) && !check) {
            return -1;
        }
        if (buf == delim) {
            break;
        }
        if (result >= buf_size) {
            (*lineptr) = (char *) mx_realloc(*lineptr, result + 1);
        }
        (*lineptr)[result] = buf;
        result++;
        if(!check) {
            check = true;
        }
    }
    size_t exbytes = malloc_usable_size((*lineptr)) - result;
    mx_memset(&(*lineptr)[result], '\0', exbytes);
    return result;
}
