#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "read_coefficient.h"
#include "unit_tests.h"

void read_coefficient(double *coef, bool *error_status, const char *argv[], int *a, int *b, int argc) {
    int symbol = '\0';
    int sign = 1;
    int len = 0;
    double number = 0;
    int point_counter = 0;
    bool fraction_trigger = 0;

    //-------------------------

    int (*f1) (const char **, int *, int *);
    if (argc == 2) {
        f1 = read_file;
    } else if (argc > 1){
        f1 = give_symbols;
    } else {
        f1 = my_getchar;
    }

   //---------------------------

    while ((symbol = f1(argv, a, b)) != '\n' && (symbol != '\0')) {

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

//TODO: find atof function else
int give_symbols(const char *str[], int *number_of_coef, int *number_of_symbol) {
    if(str[*number_of_coef][*number_of_symbol] == '\0') {
        (*number_of_coef)++;
        *number_of_symbol = 0;
        return '\0';
    }

    *number_of_symbol += 1;
    return str[*number_of_coef][*number_of_symbol - 1];
}




inline int my_getchar(const char *str[], int *number_of_coef, int *number_of_symbol) { // to make choise between two functions in
    return getchar();                                                           // read_coefficient possible
}


void interactively_read_coefficients (double *coefs, bool *error_status, const char *argv[], int *number_of_coef, int *number_of_symbol, int argc) {
    for (int i = 0; i <= 2; i++) {
        if (argc == 1) {
	        putchar('a' + i);
            printf(" = ");
        }
        read_coefficient(coefs + i, error_status, argv, number_of_coef, number_of_symbol, argc);
    }
}



int read_file(const char *str[], int *a, int *b) {
    FILE *mf;
    mf = fopen("input.txt", "r");
    int c;
    for(int i = 0; i < *a; i++) {
        c = fgetc(mf);
    }
    *a += 1;
    while ((c = fgetc(mf)) != ';' && c != ' ') {
        return c;
    }
    return '\0';

}
