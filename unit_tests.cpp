#include <stdio.h>
#include "solve.h"
#include <math.h>
#include "read_coefficient.h"
#include "colours.h"

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

double const spec_eps = 1e-3;

int compare_for_test(double number);


typedef struct test_case {
    double coefs[3];
    const double x1_ref;
    const double x2_ref;
    const int nroots_ref;
    } test_case;



int test_one_case(struct test_case *all_cases) {
    double x1 = 0, x2 = 0;
    int number_of_roots_from_solve = -1;
    solve(all_cases->coefs, &x1, &x2, &number_of_roots_from_solve);
    if (compare_for_test(x1 - all_cases->x1_ref) != 0|| compare_for_test(x2 - all_cases->x2_ref) != 0 || number_of_roots_from_solve != all_cases->nroots_ref) {
        printf(RED"\x1b[31mCalculated: x1 = %.4lf, x2 = %.4lf, number of roots = %d\n  Expected: x1 = %.4lf, x2 = %.4lf, number of roots = %d\n", x1, x2, number_of_roots_from_solve, all_cases->x1_ref, all_cases->x2_ref, all_cases->nroots_ref);
        return 0;
    }
    return 1;
}






void test_solve(void) {

    test_case all_cases[] = {
        {{     0,      0,       0},      0,       0, INFINITE_ROOTS},
        {{     0,      0,       7},      0,       0,              0},
        {{     2,     21,       3}, -0.145, -10.355,              2},
        {{  -0.7,     20,    -3.3},  0.166,  28.405,              2},
        {{     1,     -3,       2},      2,       1,              2},
        {{     0,     20,       0},      0,       0,              1},
        {{-5.345,12.4543,   5.232}, -0.363,   2.693,              2},
        {{     4,      0,       0},      0,       0,              1},
        {{     4,  59.39,       0},      0, -14.848,              2},
        {{  3.45,      0,  4.9494},      0,       0,              0},
        {{ 5.345,      0, -4.9494},  0.962,  -0.962,              2},
        {{     0, 56.994,   8.349}, -0.146,       0,              1}
        };

        const int NUMBER_OF_TESTS = ARRAY_SIZE(all_cases);
        int right_answer_count = 0;
        for (int i = 0; i < NUMBER_OF_TESTS; i++) {
            if (test_one_case(&all_cases[i]) == 1)
                right_answer_count++;
        }

        if (right_answer_count == 12) {
            printf(GREEN"%d/%d correct answers", right_answer_count, NUMBER_OF_TESTS);
            return;
        }
        printf(RED"%d/%d correct answers", right_answer_count, NUMBER_OF_TESTS);
    }


int compare_for_test(double number) {
    if (fabs(number) < spec_eps) {
        return 0;
    }
    return 1;
}
