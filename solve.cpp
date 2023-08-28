#include <stdio.h>
#include <math.h>
#include "solve.h"
#include "testing.h"
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

int comparison_with_zero(double number) {
    double epsilon = 1e-8;
    if (fabs(number) <= epsilon)
        return 0;
    return 1;
}
