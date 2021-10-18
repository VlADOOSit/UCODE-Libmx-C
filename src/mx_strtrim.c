#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) {
        return NULL;
    }

    while (mx_isspace(*str)) {
        str++;
    }

    int size = mx_strlen(str);

    while(mx_isspace(str[size-1])) {
        size--;
    }
    return mx_strndup(str, size);
    
}
