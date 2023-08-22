#include <stdio.h>
#include "functions.h"


void testing_one_case(double coefs[], double x1_ref, double x2_ref, double x1, double x2, int nroots_ref, int nroots) {
    solve(coefs, &x1, &x2, &nroots);
    if (x1 != x1_ref || x2 != x2_ref || nroots != nroots_ref) {
        printf("Calculated: x1 = %lf, x2 = %lf, number of roots = %d\n                  Expected: x1 = %lf, x2 = %lf, number of roots = %d\n", x1, x2, nroots, x1_ref, x2_ref, nroots_ref);
    } else {
        printf("OK");
    }
    return;
}







void test_programm(void) {
    int nroots;
    double x1 = 0, x2 = 0;
    double coefs[3] = {0,0,0};
    testing_one_case(coefs, 0, 0, x1, x2, 0, nroots);
    return;
}
