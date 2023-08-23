#include <stdio.h>
#include <ctype.h>
<<<<<<< Updated upstream



void read_coefficient(double *coef, bool *error_status) {
    int symbol;
=======



void read_coef(double *coef, bool *error_status) {
    int simvol;
>>>>>>> Stashed changes
    double number = 0;
    int sign = 1;
    if ((symbol = getchar()) == '-') {
        sign = -1;
    } else if (isdigit(symbol) != 0) { // TODO: can you getc/ungetc
        number = symbol - '0';
    } else {
        *error_status = 1;
    }

// TODO: indent
while ((symbol = getchar()) != '\n' && symbol != '.') { // TODO: extract
    if (symbol == '-') {
        *error_status = 1;
    }

<<<<<<< Updated upstream
    number = (number * 10) + (symbol - '0');
    } // TODO: align
    if (symbol == '\n') { // TODO: what if I enter few spaces before or after?
=======
    number = (number * 10) + (simvol - '0');
    }
    if (simvol == '\n') {
>>>>>>> Stashed changes
        *coef = sign * number;
        return;
    }
    double power = 1;
    int point_count = 1;
<<<<<<< Updated upstream
    while ((symbol = getchar()) != '\n') { // TODO: extract in a separate function
        if (symbol == '.')
            point_count++;
        if (point_count == 2)
            *error_status = 1;
        number = (number * 10) + (symbol - '0');
=======
    while ((simvol = getchar()) != '\n') {
        if (simvol == '.')
            point_count++;
        if (point_count == 2)
            *error_status = 1;
        number = (number * 10) + (simvol - '0');
>>>>>>> Stashed changes
        power *= 10.0;
    }
    *coef = ((sign * number) / power);
}



