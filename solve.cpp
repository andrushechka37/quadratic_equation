#include <stdio.h>
#include <math.h>
#include "solve.h"
#include "unit_tests.h"
#include "read_coefficient.h"


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
        *x1 = (-coefs[1] / (2 * coefs[0]));
        return 1;
    } else if (discriminant < 0) {
        return 0;
    } else {
        *x1 = (-coefs[1] + sqrt(discriminant)) / (2 * coefs[0]);
        *x2 = (-coefs[1] - sqrt(discriminant)) / (2 * coefs[0]);
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

int comparison_with_zero(double number) { // TODO: make static
    double epsilon = 1e-8;
    if (fabs(number) <= epsilon)
        return 0;
    return 1;
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
