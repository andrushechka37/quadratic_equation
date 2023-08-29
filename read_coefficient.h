#ifndef WORK_WITH_COEF_H
#define WORK_WITH_COEF_H

int comparison_with_zero(double number);

int work_with_flag(char **argv, int *number_of_coef, int argc);
int types_of_input(char **argv, int *number_of_coef, int *argc);
int read_file(char **str, int *a, int *b);
void interactively_read_coefficients (double *coefs, bool *error_status, char **argv, int *a, int *b, int argc);
void read_coefficient(double *coef, bool *error_status, char **argv, int *a, int *b, int argc);
void print_solution(int number_of_roots, double x1, double x2);

int give_symbols(char **str, int *number_of_coef, int *number_of_symbol);
int my_getchar(char **str, int *number_of_coef, int *number_of_symbol);

const int KEYBOARD_INPUT = 0;
const int HELP = 2;
const int COMMAND_LINE_INPUT = 1;
const int ERROR = -1;
const int UNKNOWN_ARGUEMENTS = -999;

#endif
