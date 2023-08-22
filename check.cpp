#include <stdio.h>




void read_coef(double *coef, bool *error_status) {
    int simvol;
    int point_count = 0;
    double number = 0;
    int sign = 1;
    if ((simvol = getchar()) == '-') {
        sign = -1;
    } else if (isdigit(simvol) != 0) {
        number = simvol - '0';
    } else {
        *error_status = 1;
    }

while ((simvol = getchar()) != '\n' && simvol != '.') {
    if (simvol == '-') {
        *error_status = 1;
    }

    if (simvol == '.')
        point_count++;
    if (point_count == 2)
        *error_status = 1;
    number = (number * 10) + (simvol - '0');
    }
    if (simvol == '\n') {
        *coef = sign * number;
        return;
    }
    double power = 1;
    while ((simvol = getchar()) != '\n') {
        number = (number * 10) + (simvol - '0');
        power *= 10.0;
    }
    *coef = ((sign * number) / power);
}






