#include "utils.hpp"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isInputZero(char *p)
{
    int i = 0;

    while (p[i] && ((p[i] == '0') || (p[i] == 'f') || (p[i] == '.'))) {
        i++;
    }
    if (p[i] == '\0')
        return (1);
    return (0);
}

int     inputType(char *p)
{
    if (strlen(p) == 1 && isprint(atoi(p))){
        return (CHAR);
    } else if (strchr(p, '.') && !strchr(p, 'f')){
        return (DOUBLE);
    } else if (strchr(p, '.') && strchr(p, 'f')) {
        return (FLOAT);
    }
    else if (!strncmp(p, "nan", strlen(p)) || !strncmp(p, "nanf", strlen(p)) \
        || !strncmp(p, "inf", strlen(p)) || !strncmp(p, "-inf", strlen(p))) {
        return (NOTAN);
    } else {
        return (INT);
    }
    return (UNKNOWN);
}