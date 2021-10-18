#include "libmx.h"

char *mx_strndup(const char *str, size_t n) {
    char *temp = mx_strnew(n);
    mx_strncpy(temp, str, n);
    return temp;
}
