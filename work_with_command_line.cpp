#include <stdio.h>
#include <string.h>


const int KEYBOARD_INPUT = 0;
const int HELP = 2;
const int COMMAND_LINE_INPUT = 1;
const int ERROR = -1;
const int UNKNOWN_ARGUEMENTS = -999;



int work_with_flag(char **argv, int *a, int argc) {
    if (argc == 1)
        return KEYBOARD_INPUT;
    if (strcmp(argv[1], "--help") == 0) {
        return HELP;
    }
    if ((strcmp(argv[1], "--help") != 0) && (strcmp(argv[1], "-coef") != 0)) {
        return UNKNOWN_ARGUEMENTS;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-coef") == 0) {
            if (argc >= (i+4)) {
                *a = i+1;
                return COMMAND_LINE_INPUT;
            } else {
                return ERROR;
            }
        }
    }

    return UNKNOWN_ARGUEMENTS;
}
