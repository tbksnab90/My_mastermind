#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "make_code.c"
#include "flags_valid.c"

int         check_dup(char *str);
char*       code_gen();
int         is_valid(char *str);
char*       check_flags(char** argv, char flag);
int         valid_input(char *str);
char*       fill_gap(char* str);
int         str_cmp(char* str1, char* str2);

#endif