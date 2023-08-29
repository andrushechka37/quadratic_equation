#ifndef WORK_WITH_COEF_H
#define WORK_WITH_COEF_H
//----------------------------------------------------------------------------------------------
/// @brief compare with zero using epsilon
///
/// @param number that is comparing
/// @returns 0 or 1 depanding on situation
///
//----------------------------------------------------------------------------------------------

int comparison_with_zero(double number);
//----------------------------------------------------------------------------------------------
/// @brief works with flags
///
/// @param argv
/// @param number of coeff
/// @param number argc
/// @returns number of situation
///
//----------------------------------------------------------------------------------------------

int work_with_flag(const char **argv, int *number_of_coef, int argc);
//----------------------------------------------------------------------------------------------
/// @brief work with pypes of input
///
/// @param argv
/// @param number of coeff
/// @param number argc
/// @returns number of situation
///
//----------------------------------------------------------------------------------------------
int types_of_input(const char **argv, int *number_of_coef, int *argc);

//----------------------------------------------------------------------------------------------
/// @brief reads file
///
/// @returns symbol
///
//----------------------------------------------------------------------------------------------
int read_file(const char *str[], int *a, int *b);
//----------------------------------------------------------------------------------------------
/// @brief make the cycle that prints interface
///
/// @param array of coefficients
/// @param error_status
/// @param argv
/// @param number of coefficient
/// @param number of symbol
/// @param argc
///
//----------------------------------------------------------------------------------------------
void interactively_read_coefficients (double *coefs, bool *error_status, const char *argv[], int *a, int *b, int argc);

//----------------------------------------------------------------------------------------------
/// @brief function that read coefficient // TODO: write in imperative
///
/// @param array of coefficients
/// @param error_status
/// @param argv
/// @param number of coefficient
/// @param number of symbol
/// @param argc
/// @returns number of situation
///
//----------------------------------------------------------------------------------------------
void read_coefficient(double *coef, bool *error_status, const char *argv[], int *a, int *b, int argc);
//----------------------------------------------------------------------------------------------
/// @brief make the cycle that prints interface // TODO: Write from uppercase letters
///
/// @param number of roots
/// @param x1
/// @param x2
///
//----------------------------------------------------------------------------------------------
void print_solution(int number_of_roots, double x1, double x2);

//----------------------------------------------------------------------------------------------
/// @brief work with command line
///
/// @param argv
/// @param number of coefficient
/// @param number of symbol
/// @returns symbol
///
//----------------------------------------------------------------------------------------------
int give_symbols(const char *str[], int *number_of_coef, int *number_of_symbol);
//----------------------------------------------------------------------------------------------
/// @brief gets symbols from stdin
///
/// @param argv
/// @param number of coefficient
/// @param number of symbol
/// @returns symbol
///
//----------------------------------------------------------------------------------------------
int my_getchar(const char *str[], int *number_of_coef, int *number_of_symbol);

const int KEYBOARD_INPUT = 0;
const int HELP = 2;
const int COMMAND_LINE_INPUT = 1;
const int ERROR = -1;
const int UNKNOWN_ARGUEMENTS = -999;

// TODO: in general, rewrite docs carefully

#endif
