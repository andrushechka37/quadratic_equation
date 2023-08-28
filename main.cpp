#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "solve.h"
#include "read_coefficient.h"

#include <string.h>

const int KEYBOARD_INPUT = 0;
const int HELP = 2;
const int COMMAND_LINE_INPUT = 1;
const int ERROR = -1;
const int UNKNOWN_ARGUEMENTS = -999;

int main(int argc, char *argv[]) {
    bool error_status = 0;
    int number_of_coef = 1, number_of_symbol = 0;

        //TODO: types of error
        // remove functions
        // file (flag)
        // enum


    if (argc == 1)
        printf("print a, b, c from ax^2 + bx + c = 0\n");
    switch (work_with_flag(argv, &number_of_coef, argc)) {
        case ERROR:
            printf("ERROR, not enough arguments");
            return 0;
        case UNKNOWN_ARGUEMENTS:
            printf("unknown arguments\n");
            return 0;
        case HELP:
            printf("i am trying to help you, but cant");
            return 0;
        case KEYBOARD_INPUT:
            argc = 1;
            break;
    }






    double coefs[] = {0, 0, 0};
    interactively_read_coefficients(coefs, &error_status, (char**)argv, &number_of_coef, &number_of_symbol, argc);

    if (error_status == 1) {
        printf("ERROR");
        return 0;
    }

    double x1 = 0, x2 = 0;
    int number_of_roots = 0;

    solve(coefs, &x1, &x2, &number_of_roots);

    print_solution(number_of_roots, x1, x2);

    return 0;
}

void print_solution(int number_of_roots, double x1, double x2) {
    switch (number_of_roots) {
        case 0:
            printf("no valid solutions");
            break;
        case 1:
            printf("x1 = x2 = %.2lf", x1);
            break;
        case 2:
            printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
            break;
        case INFINITE_ROOTS:
            printf("an infinite number of solutions");
            break;
    }
}

void interactively_read_coefficients (double *coefs, bool *error_status, char **argv, int *number_of_coef, int *number_of_symbol, int argc) {
    for (int i = 0; i <= 2; i++) {
        if (argc == 1) {
	        putchar('a' + i);
            printf(" = ");
        }
        read_coefficient(coefs + i, error_status, argv, number_of_coef, number_of_symbol, argc);
    }
}




