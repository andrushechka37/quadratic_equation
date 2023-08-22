int solve_linear_equation(double coefs[], double *x1);
int solve_quadratic_eqation (double coefs[], double *x1, double *x2);
void solve(double coefs[], double *x1, double *x2, int *number_of_roots);

int comparison_with_zero (double number);
void interactively_read_coefficients (double *coefs, bool *error_status);
void read_coef (double *coef, bool *error_status);
void print_solution (int number_of_roots, double x1, double x2);
