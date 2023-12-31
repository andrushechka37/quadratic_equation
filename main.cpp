#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "solve.h"
#include "read_coefficient.h"
int main(int argc,const char *argv[]) {
    bool error_status = 0;
    int number_of_coef = 0, number_of_symbol = 0;
        //TOREAD: enum
        //TOREAD: union
        //TODO: generate makefile
        //TODO: intergate tests
        //TODO: phony in makefile
        //TODO: -file is very bad, need to completely rewrite cringe
        //TODO: rewrite choice between functions in check.cpp cringe
    if (argc == 1) {
        printf("print a, b, c from ax^2 + bx + c = 0\n");
    }

    if (types_of_input(argv, &number_of_coef, &argc) == 0)
        return 0;

    double coefs[] = {0, 0, 0};
    interactively_read_coefficients(coefs, &error_status, argv, &number_of_coef, &number_of_symbol, argc);

    if (error_status == 1) {
        printf("INCORRECT INPUT");
        return 0;
    }

    double x1 = 0, x2 = 0;
    int number_of_roots = 0;

    solve(coefs, &x1, &x2, &number_of_roots);

    print_solution(number_of_roots, x1, x2);

    return 0;
}



//////////

