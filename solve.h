#ifndef SOLVE_H
#define SOLVE_H


int solve_linear_equation(double coefs[], double *x1);
int solve_quadratic_equation (double coefs[], double *x1, double *x2);
void solve(double coefs[], double *x1, double *x2, int *number_of_roots);



int const INFINITE_ROOTS = 999;




#endif
