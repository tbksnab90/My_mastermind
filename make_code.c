#include "header.h"

int     check_dup(char *str) {
    int i = 0, j;
    
    while (str[i] != '\0') {
        j = i + 1;
        while (str[j] != '\0') {
            if (str[j] == str[i]) {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

char*       code_gen() {
    int i, n;
    char *code = NULL;
    time_t t;

    if (!(code = malloc(5 * sizeof(char))))
        return 0;

    srand(time(&t));
    for (i = 0; i < 4; i++) {
        n = rand() % 7;
        code[i] = n + '0';
    }
    code[i] = '\0';
    
    while (check_dup(code)) {
        for (i = 0; i < 4; i++) {
            n = rand() % 7;
            code[i] = n + '0';
        }
        code[i] = '\0';
    }
    return code;
}