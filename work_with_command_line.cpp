#include <stdio.h>
#include <string.h>
#include "read_coefficient.h"




int work_with_flag(const char **argv, int *number_of_coef, int *argc) {
    if (*argc == 1)
        return KEYBOARD_INPUT;
    if (strcmp(argv[1], "--help") == 0) {
        return HELP;
    }
    if (strcmp(argv[1], "-file") == 0) {
        *argc = 2;
        return 1;
    }
    int count = 0;
    for (int i = 1; i < *argc; i++) {
        if (strcmp(argv[i], "-coef") == 0) {
            i += 4;
        } else {
            puts(argv[i]);
            count++;
        }
    }
    if (count != 0)
        return UNKNOWN_ARGUEMENTS;
    for (int i = 1; i < *argc; i++) {
        if (strcmp(argv[i], "-coef") == 0) {
            if (*argc >= (i+4)) {
                *number_of_coef = i+1;
                return COMMAND_LINE_INPUT;
            } else {
                return ERROR;
            }
        }
    }
    return UNKNOWN_ARGUEMENTS;
}


int types_of_input(const char **argv, int *number_of_coef, int *argc) {
    switch (work_with_flag(argv, number_of_coef, argc)) {
        case ERROR:
            printf("ERROR, not enough arguments");
            return 0;
        case UNKNOWN_ARGUEMENTS:
            printf("^~~~~~~~~~~unknown arguments\n");
            return 0;
        case HELP:
            printf("These are common commands used in various situations:\n");
            printf("    --help          menu of commands\n");
            printf("     -coef          enter commands from command line like\n");
            printf("                    ./file_name -coef 1 -3 2\n");
            printf("     -file          reads coefs from file named input.txt like\n");
            printf("                    1 -2 3;\n");
            printf("Other commnds will be interpretated as errors\n");
            return 0;
    }
    return 1;
}


