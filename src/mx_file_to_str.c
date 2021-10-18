#include "libmx.h"

char *mx_file_to_str(const char *filename) {
    if (filename == NULL) {
        return NULL;
    }
    char buff;
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    int size = 0;
    int len = read(fd, &buff, 1);
    while (len) {
        len = read(fd, &buff, 1);
        size++;
    }
    if (close(fd) < 0) {
        return NULL;
    }
    char *result = mx_strnew(size);
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return NULL;
    }
    for (int i = 0; read(fd, &buff, 1); i++) {
        result[i] = buff;
    }

    if (close(fd) < 0) {
        return NULL;
    }
    return result;
}
