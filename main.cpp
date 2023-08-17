#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
void solve (double frst_coef, double sec_coef, double free_member);
void get_coef(double *coef);
int main(void) {
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    double frst_coef, sec_coef, free_member;
    double *array[] = {&frst_coef, &sec_coef, &free_member};
    for (int i = 0; i <= 2; i++) {
        putchar(97 + i);
        printf(" = ");
        get_coef(array[i]);
    }
    solve(frst_coef, sec_coef, free_member);
    return 0;
}

void get_coef(double *coef) {
    char str [20];
    char c;
    int i = 0;
    while (((c = getchar()) >= 48 && c <= 57) || c == 46 || c == 45) {
        if (c == 45 && i != 0) {
            printf("input error");
            exit(-1);
        }
        str[i] = c;
        i += 1;
    }
    if (c == '\n') {
        *coef = atof(str);
        return;
    } else {
        printf("input error");
            exit(-1);
    }
}

void solve (double frst_coef, double sec_coef, double free_member) {
        double x1;
    double epsilon = 1e-9;
    if ((frst_coef >= (-epsilon)) && (frst_coef <= epsilon)) {
        if ((sec_coef <= (-epsilon)) || (sec_coef >= epsilon)) {
            x1 = (double) (-free_member / sec_coef);
            printf("x1 = x2 = %.2lf", x1);
        } else if (((sec_coef >= (-epsilon)) && (sec_coef <= epsilon)) && ((free_member >= (-epsilon)) && (free_member <= epsilon))) {
          printf("an infinite number of solutions");
        } else {
            printf("no valid solutions");
        }
    } else {
        double diskr = sec_coef * sec_coef - 4 * frst_coef * free_member;
        if ((diskr >= (-epsilon)) && (diskr <= epsilon)) {
            x1 = (double) (-sec_coef / (2 * frst_coef));
            printf("x1 = x2 = %.2lf", x1);
        } else if (diskr < 0) {
            printf("no valid solutions");
        } else {
            x1 = (double) (-sec_coef + sqrt(diskr)) / (2 * frst_coef);
            double x2 = (double) (-sec_coef - sqrt(diskr)) / (2 * frst_coef);
            printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
        }
    }
}
