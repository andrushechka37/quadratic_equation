#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "read_coefficient.h"
#include "unit_tests.h"


// struct string_iterator {
//     char *buffer;
//     int current_index;
// };
//
//
// struct generalized_stream {
//     char (*getc)(generalized_stream*);
//
//     FILE *file;
//     string_iterator iter;
// };
//
// char string_iterator_getc(generalized_stream *generalized) {
//     return generalized->iter.buffer[generalized->iter.current_index ++];
// }
//
// char file_getc(generalized *generalized) {
//     return getc(generalized->file);
// }
//
// generalized_stream from_file(FILE *file) {
//
//     return { file_getc, file };
// }
//
// generalized_stream from_string(char *string) {
//     return { string_iterator_getc, NULL, { string, 0 } };
// }
//
//
// void read_coefficient(generalized_stream *generalized) {
//     generalized->getc(generalized);
// }


void read_coefficient(double *coef, bool *error_status, const char *argv[], int *number_of_coef, int *number_of_symbol, int argc) {
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

    while ((symbol = f1(argv, number_of_coef, number_of_symbol)) != '\n' && (symbol != '\0')) {

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
}                                                                               // i know cringe, rewrite


void interactively_read_coefficients (double *coefs, bool *error_status, const char *argv[], int *number_of_coef, int *number_of_symbol, int argc) {
    for (int i = 0; i <= 2; i++) {
        if (argc == 1) {
	        putchar('a' + i);
            printf(" = ");
        }
        read_coefficient(coefs + i, error_status, argv, number_of_coef, number_of_symbol, argc);
    }
}



int read_file(const char *str[], int *number_of_coef, int *number_of_symbol) {        // i know cringe, rewrite
    FILE *mf = fopen("input.txt", "r");
    int c = 0;
    for(int i = 0; i < *number_of_coef; i++) {
        c = fgetc(mf);
    }
    *number_of_coef += 1;
    while ((c = fgetc(mf)) != ';' && c != ' ') {
        return c;
    }
    return '\0';
}
