#include "header.h"

int     str_cmp(char* str1, char* str2) {
    int i = 0, count = 0;

    while (str1[i] != '\0') {
        if (str1[i] == str2[i])
            count++;
        i++;
    }
    return count;
}

int     find_num(char* code, char num) {
    int i = 0, count = 0;

    while (code[i] != '\0') {
        if (code[i] == num)
            count++;
        i++;
    }
    return count;
}

int     find_missplaced(char* code, char* buff) {
	    int count= 0, i = 0;
	
	    while (code[i] != '0') {
	        if (code[i] != buff[i] && find_num(code, buff[i]) > 0)
                    count++;
	        i++;
	    }
	    return count;
	}

char*       fill_gap(char* str) {

    int i = 0, count = 0;
    if (str) {
        while (str[i] != '\0') {
            if (str[i] >= '0' && str[i] <= '9')
                count++;
            else {
                str[i] = '+';
            }
            i++;
        }
    }
    return str;
}

int     valid_input(char *str) {
    int i = 0, count = 0;
    if (str) {
        while (str[i] != '\0')
        {
            if (str[i] >= '0' && str[i] <= '9') {
                count++;
            }
            i++;
        }
    }
    return count;
}

int     main(int argc, char** argv) {
    
    char* code;
    char* tries;
    int rounds, i = 0, miss, hit;
    char buff[5];
    int bytes;
    
    code = check_flags(argv, 'c') ? check_flags(argv, 'c') : code_gen();
    tries = check_flags(argv, 't') ? check_flags(argv, 't') : "10";
    rounds = atoi(tries);
    
    if (argc > 0)
    {
        printf("Will you find the secret code?\nPlease enter a valid guess\n");
        
        while (i < rounds && str_cmp(code, buff) != 4) {
            printf("Round %d\n", i + 1);
            bytes = read(0, &buff, sizeof(buff));
            if (bytes <= 0) {
                printf("exit\n");
                return 0;
            }
            buff[4] = '\0';
            fill_gap(buff);
            
            if (valid_input(buff) == 0) {
                printf("Wrong input!\n");  
            } else {
                miss = find_missplaced(code, buff);
                hit = str_cmp(code, buff);
                (hit != 4) ? printf("Well placed pieces: %d\nMisplaced pieces: %d\n", hit, miss) : printf("Congratz! You did it!\n");   
            }
            i++;
        }
    }
    return 0;
}