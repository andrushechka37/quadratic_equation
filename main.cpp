#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "solve.h"
#include "testing.h"
#include "work_with_coef.h"

int const LIMIT = 20;
int const INFINITE_ROOTS = 999;




int main(void) {
    /*
    printf("print a, b, c from ax^2 + bx + c = 0\n");

    bool error_status = 0;

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
*/
    test_solve();

    return 0;
}



void solve(double coefs[], double *x1, double *x2, int *number_of_roots) {
    if (comparison_with_zero(coefs[0]) == 0) {
        *number_of_roots = solve_linear_equation(coefs, x1);
    } else {
        *number_of_roots = solve_quadratic_equation(coefs, x1, x2);
    }
}



int solve_quadratic_equation (double coefs[], double *x1, double *x2) {
    double discriminant = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
    if (comparison_with_zero(discriminant) == 0) {
        *x1 = (double) (-coefs[1] / (2 * coefs[0]));
        return 1;
    } else if (discriminant < 0) {
        return 0;
    } else {
        *x1 = (double) (-coefs[1] + sqrt(discriminant)) / (2 * coefs[0]);
        *x2 = (double) (-coefs[1] - sqrt(discriminant)) / (2 * coefs[0]);
        return 2;
    }
}



int solve_linear_equation(double coefs[], double *x1) {
    if (comparison_with_zero(coefs[1]) != 0) {
        *x1 = (double) (-coefs[2] / coefs[1]);
        return 1;
    } else if ((comparison_with_zero(coefs[1]) == 0) && (comparison_with_zero(coefs[2]) == 0)) {
        return INFINITE_ROOTS;
    } else {
        return 0;
    }
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






int comparison_with_zero (double number) {
    double epsilon = 1e-5;
    if (fabs(number) <= 0)
        return 0;
    if (number > 0) {
        return 1;
    } else {
        return -1;
    }
}



void interactively_read_coefficients (double *coefs, bool *error_status) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
        printf(" = ");
        read_coefficient(coefs + i, error_status);
    }
}






























