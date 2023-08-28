#include <stdio.h>
#include <string.h>

int work_with_flag(char **argv, int *a, int argc) {
    if (argc == 1)
        return 0;
    if (strcmp(argv[1], "--help") == 0) {
        return 2;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-coef") == 0) {
            if (argc >= (i+3)) {
                *a = i+1;
                return 1;
            } else {
                return -1;
            }
        }
    }

    return 0;
}
