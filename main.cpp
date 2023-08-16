#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    double a, b, c, x, d;
    double epsilon = 0.00000000001;
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    if (a == 0) {
        if (b != 0) {
            x = (double) (-c / b);
            printf("x1 = x2 = %.2lf", x);
        } else if (b == 0 && c == 0) {
            printf("an infinite number of solutions");
        } else {
            printf("no valid solutions");
        }
    } else {
        d = b * b - 4 * a * c;
        if ((d >= (-1 * epsilon)) && (d <= epsilon)) {
            x = (double) (-b / (2 * a));
            printf("x1 = x2 = %.2lf", x);
        } else if (d < 0) {
            printf("no valid solutions");
        } else {
            x = (double) (-b + sqrt(d)) / (2 * a);
            printf("x1 = %.2lf\n", x);
            x = (double) (-b - sqrt(d)) / (2 * a);
            printf("x2 = %.2lf\n", x);
        }
    }
    return 0;
}
