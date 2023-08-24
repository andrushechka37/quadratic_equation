#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "solve.h"
#include "read_coefficient.h"





int main(int argc, const char *argv[]) {
    // ./solve-equation -a=1 -b=2 -c=3
    // argc = 4
    // argv[] = { "./solve-equation", "1", "-b=2", "-c=3" }
    bool error_status = 0; /*
    int j = 0
    while (argc > 1) {
        read_coefficient(argv[j], *error_status);
        argc--;
    }
    */
    printf("print a, b, c from ax^2 + bx + c = 0\n");

    double coefs[] = {0, 0, 0};
    interactively_read_coefficients(coefs, &error_status);

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






void interactively_read_coefficients (double *coefs, bool *error_status) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
        printf(" = ");
        read_coefficient(coefs + i, error_status);
    }
}






















