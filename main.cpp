#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>



int const LIMIT = 20;
int const NO_ROOTS = -1;


int linear_equation(double coefs[], double *x1);
int comparison (double number);
void input_coef (double *coefs, bool *error_status);
int quadratic_eqation (double coefs[], double *x1, double *x2);
void get_coef (double *coef, bool *error_status);
void print_solution (int number_of_roots, double x1, double x2);
double myself_atof(char str[]);



int main(void) {
    printf("print a, b, c from ax^2 + bx + c = 0\n");

    bool error_status = 0;

    double coefs[] = {0, 0, 0};
    input_coef(coefs, &error_status);

    double x1 = 0, x2 = 0;
    int number_of_roots = 0;

    if (comparison(coefs[0]) == 0) {
        number_of_roots = linear_equation(coefs, &x1);
    } else {
        number_of_roots = quadratic_eqation(coefs, &x1, &x2);
    }


    if (error_status == 1) {
        printf("ERROR");
    } else {
        print_solution(number_of_roots, x1, x2);
    }

    return 0;
}







int quadratic_eqation (double coefs[], double *x1, double *x2) {
    double discriminant = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
    if (comparison(discriminant) == 0) {
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
        case 999:
            printf("an infinite number of solutions");
            break;
    }

}






int comparison (double number) {
    double epsilon = 1e-9;
    if (fabs(number) <= 0)
        return 0;
    if (number > 0) {
        return 1;
    } else {
        return -1;
    }
}


int linear_equation(double coefs[], double *x1) {
    if (comparison(coefs[1]) != 0) {
        *x1 = (double) (-coefs[2] / coefs[1]);
        return 1;
    } else if ((comparison(coefs[1]) == 0) && (comparison(coefs[2]) == 0)) {
        return 999;
    } else {
        return 0;
    }
}


void input_coef (double *coefs, bool *error_status) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
        printf(" = ");
        get_coef(coefs + i, error_status);
    }
}
