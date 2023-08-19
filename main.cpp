#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define LIM 20



void input_coef (double *coefs);
int solve (double a_coef, double b_coef, double c_coef, double *x1, double *x2);
void get_coef (double *coef);
void answer_output (int number_of_roots, double x1, double x2);


bool error_status = 0;



int main(void) {
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    double coefs[] = {0, 0, 0};
    input_coef(coefs);
    double x1, x2;
    answer_output(solve(coefs[0], coefs[1], coefs[2], &x1, &x2), x1, x2);
    return 0;
}



void get_coef(double *coef) {
    char str [LIM];
    int c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (c == '-' && i != 0) {
                error_status = 1;
            }
        if (c == '.' && i == 0) {
                error_status = 1;
            }
        if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
            str[i] = c;
            i += 1;
            continue;
        }
        error_status = 1;
    }
    if (error_status != 1) {
        *coef = atof(str);
        return;
    } else {
        error_status = 1;
        return;
    }
}




int solve (double a_coef, double b_coef, double c_coef, double *x1, double *x2) {
    if (error_status == 1)
        return 73;
    double epsilon = 1e-9;
    if (fabs(a_coef) <= epsilon) {
        if (fabs(b_coef) >= epsilon) {
            *x1 = (double) (-c_coef / b_coef);
            return 1;
        } else if ((fabs(b_coef) <= epsilon) && (fabs(c_coef) <= epsilon)) {
            return 999;
        } else {
            return 0;
        }
    } else {
        double diskriminant = b_coef * b_coef - 4 * a_coef * c_coef;
        if (fabs(diskriminant) <= epsilon) {
            *x1 = (double) (-b_coef / (2 * a_coef));
            return 1;
        } else if (diskriminant < 0) {
            return 0;
        } else {
            *x1 = (double) (-b_coef + sqrt(diskriminant)) / (2 * a_coef);
            *x2 = (double) (-b_coef - sqrt(diskriminant)) / (2 * a_coef);
            return 2;
        }
    }
}





void answer_output(int number_of_roots, double x1, double x2) {
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
        case 73:
            printf("ERROR");
            break;
    }

}




void input_coef (double *coefs) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
        printf(" = ");
        get_coef(coefs + i);
    }
}
