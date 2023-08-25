#include <stdio.h>
#include <ctype.h>
#include <math.h>

/*#define ensure_and_skip(condition)  \
    ({                              \
        char symbol = getc(stdin);  \
                                    \
        bool parsed = true;         \
        if (condition)              \
            ugetc(symbol, stdin);   \
        else {                      \
            parsed = false;         \
        }                           \
                                    \
        parsed;                     \
    });

int read_number(bool *read_any, int *pow = NULL) {
    int number = 0;
    while (true) {
		if (!ensure_and_skip(isdigit(symbol)))
			break;

		number = 10 * number + (symbol - '0');
        if (pow) *pow *= 10;
    }

    return number;
}


double read_double(int *error_code) {
    int sign = ensure_and_skip_symbol('-') ? -1 : 1;

    bool entered_whole = false;
    bool entered_fractional = false;

    int whole = read_number(&entered_whole);
    ensure_and_skip_symbol('.');

    int fraction_pow = 1;
    int fractional = read_number(&entered_fractional, &fraction_pow);

    if (!entered_whole && !entered_fractional)
        *error_code = 1;


    return whole + fractional / fraction_pow;
}*/


void read_coefficient(double *coef, bool *error_status) {


    int symbol = '\0';
    int sign = 1;
    int len = 0;
    double number = 0;
    int point_counter = 0;
    bool fraction_trigger = 0;


    while ((symbol = getc(stdin)) != '\n') {

        len++;


        if (symbol == '-' && len == 1) {
            sign = -1;
            continue;
        }
        if (point_counter == 2)
            *error_status = 1;
        if (symbol == '.') {
            len = 0;
            point_counter++;
            fraction_trigger = 1;
            continue;
        }

        if (isdigit(symbol) != 0) {
            number = (number * 10) + (symbol - '0');
            continue;
        }

        *error_status = 1;

    }
    if (fraction_trigger == 1) {
        *coef = ((sign * number) / pow(10, len));
        return;
    }
    *coef = (sign * number);
}
