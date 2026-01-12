#include "header.h"

int     is_valid(char *str) {
    
    int i = 0, count = 0;
    if (str) {
        while (str[i] != '\0') {
            if ((str[i] >= '0' && str[i] <= '9'))
                count++;
            i++;
        }
        if (count == i)
        return 1;
    }
    return 0;
}

char*       check_flags(char** argv, char flag) {
    int i = 0, j;
    char* data = NULL;

    while (argv[i] != NULL) {
        j = 0;
        while (argv[i][j] != '\0') {
            if (argv[i][j] == '-' && argv[i][j + 1] == flag) {
                data = argv[i + 1];
            }
            j++;
        }
        i++;
    }
    if (!(is_valid(data)))
        return 0;
    return data;
}
