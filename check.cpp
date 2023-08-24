#include <stdio.h>
#include <ctype.h>
#include <math.h>


void read_coefficient(double *coef, bool *error_status) {


    int symbol;
    int sign = 1;
    int len = 0;
    double number = 0;
    int point_counter = 0;
    bool fraction_trigger = 0;


    while ((symbol = getc(stdin)) != '\n') {

        len++;


        if (symbol == '-' && len == 1) {
            sign = -1;
        } else if(symbol == '-' && len != 1) {
            *error_status = 1;
        }

        if (symbol == '.') {
            len = 0;
            point_counter++;
            fraction_trigger = 1;
        }

        if (isdigit(symbol) != 0) {
            number = (number * 10) + (symbol - '0');
        }

        if (point_counter == 2)
            *error_status = 1;
    }
    if (fraction_trigger == 1) {
        *coef = ((sign * number) / pow(10, len));
        return;
    }
    *coef = (sign * number);
}
