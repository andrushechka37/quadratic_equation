#include <stdio.h>
int const LIMIT = 20;
double myself_atof(char str[]) {
    int i = 0;
    int sign = 0;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else {
        sign = 1;
    }
    double number = 0;
    while (str[i] != '.' && str[i] != '\0') {
        number = (number * 10) + (str[i] - '0');
        i++;
    }
    if (str[i] == '\0')
        return number;
    i++;
    double power = 1;
    while (str[i] != '\0') {
        number = (number * 10) + (str[i] - '0');
        power *= 10.0;
        i++;
    }
    return ((sign * number) / power);

}


void get_coef(double *coef, bool *error_status) {
    char str[LIMIT] = {0};
    int simvol;
    int i = 0;
    int point_count = 0;
    while ((simvol = getchar()) != '\n') {
        if (simvol == '-' && i != 0) {
            *error_status = 1;
        }

        if (simvol == '.')
            point_count++;
        if (point_count == 2)
            *error_status = 1;
        if ((simvol >= '0' && simvol <= '9') || simvol == '.' || simvol == '-') {
            str[i] = simvol;
            i += 1;
            continue;
        }
        *error_status = 1;
    }
    if (*error_status != 1) {
        *coef = myself_atof(str);
        return;
    }
    *error_status = 1;
}







