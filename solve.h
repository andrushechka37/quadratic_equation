#ifndef SOLVE_H
#define SOLVE_H

//----------------------------------------------------------------------------------------------
/// @brief Solve linear equation
///
/// @param array of coefficients
/// @param pointer to x1
/// @returns number of roots
///
//----------------------------------------------------------------------------------------------
int solve_linear_equation(double coefs[], double *x1);
//----------------------------------------------------------------------------------------------
/// @brief Solve quadratic equation
///
/// @param array of coefficients
/// @param pointer to x1
/// @param pointer to x2
/// @returns number of roots
///
//----------------------------------------------------------------------------------------------
int solve_quadratic_equation(double coefs[], double *x1, double *x2);

//----------------------------------------------------------------------------------------------
/// @brief Solve quadratic equation, by choosing the type of equation(linear or quadratic)
///
/// @param array of coefficients
/// @param pointer to x1
/// @param pointer to x2
/// @param  number of roots
///
//----------------------------------------------------------------------------------------------
void solve(double coefs[], double *x1, double *x2, int *number_of_roots);

//----------------------------------------------------------------------------------------------
/// @brief Print the solution depanding on the number of roots
///
/// @param number of roots
/// @param x1 root number one
/// @param x2 root number two
///
//----------------------------------------------------------------------------------------------
void print_solution(int number_of_roots, double x1, double x2);

int const INFINITE_ROOTS = 999;

#endif
