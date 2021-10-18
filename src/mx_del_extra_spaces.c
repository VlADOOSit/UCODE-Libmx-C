#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }

    char *result = NULL;
    char *temp = NULL;
    int count_temp = 0;

    temp = mx_strnew(mx_strlen(str));

    for (int i = 0; str[i]; i++) {
        if (!mx_isspace(str[i])) {
            temp[count_temp] = str[i];
            count_temp++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i+1])) {
            temp[count_temp] = ' ';
            count_temp++;
        }
    }

    result = mx_strtrim(temp);
    mx_strdel(&temp);
    return result;
}
