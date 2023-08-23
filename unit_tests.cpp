#include <stdio.h>
#include "functions.h"
#include <math.h>

int const NO_ROOTS = -1;
int const INFINITE_ROOTS = 999;

void testing_one_case(double coefs[4][], double roots[4][]) {
    double x1 = 0, x2 = 0;
    int nroots;
    solve(coefs, &x1, &x2, &nroots);
    if (comparison_with_zero(x1-roots[0]) != 0|| comparison_with_zero(x2-roots[1]) != 0 || nroots != (int) roots[2]) {
        printf("Calculated: x1 = %.4lf, x2 = %.4lf, number of roots = %d\n                 Expected: x1 = %.4lf, x2 = %.4lf, number of roots = %d\n", x1, x2, nroots, roots[0], roots[1], (int) roots[2]);
    } else {
        printf("OK");
    }
    return;
}







void test_solve(void) {

    double testing_coeffivients[4][3] = {{0,0,0}, {0,0,7}, {2,21,3}, {-0.7, 20, -3.3}};
    double roots[4][3] = {{0,0,INFINITE_ROOTS}, {0, 0, NO_ROOTS}, {-0.145, -10.355, 2}, {28,405, 0.166, 2}};
    for (int i = 0; i <= 3; i++) {
        testing_one_case(coefs[i][], roots[i][]);
    }




    return;
}
