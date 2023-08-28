#ifndef WORK_WITH_COEF_H
#define WORK_WITH_COEF_H

int comparison_with_zero(double number);

int work_with_flag(char **argv, int *a, int argc);
void interactively_read_coefficients (double *coefs, bool *error_status, char **argv, int *a, int *b, int argc);
void read_coefficient(double *coef, bool *error_status, char **argv, int *a, int *b, int argc);
void print_solution(int number_of_roots, double x1, double x2);

int give_symbols(char **str, int *number_of_coef, int *number_of_symbol);
int my_getchar(char **str, int *number_of_coef, int *number_of_symbol);

#endif
