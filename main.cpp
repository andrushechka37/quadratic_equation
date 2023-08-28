#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "solve.h"
#include "read_coefficient.h"



#include <string.h>
int main(int argc, char *argv[]) {
    bool error_status = 0;
    int number_of_coef = 1, number_of_symbol = 0;

        //TODO: types of error
        //TODO: flags
        //TODO: --help
        // remove functions
        // file (flag)
        // enum




    if (argc == 1)
        printf("print a, b, c from ax^2 + bx + c = 0\n");
    if (work_with_flag(argv, &number_of_coef, argc) == -1) {
        printf("ERROR");
        return 0;
    }
    if (work_with_flag(argv, &number_of_coef, argc) == 2) {
        printf("i am trying to help you, but cant");
        return 0;
    }
    if (work_with_flag(argv, &number_of_coef, argc) == 0)
        argc = 1;







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


