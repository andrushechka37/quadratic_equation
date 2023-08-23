// TODO: Every header you write should have an include guard, it's a thing that protects
//       it from double inclusion:
//
//       == Consider an example ==

//       1) You have two files:

//           // --- test.h ---
//           void foo();

//           // -- test.cpp --
//           #include "test.h"
//           #include "test.h"

//          When your compiler runs, it will expand code in test.cpp to:

//           // -- test.cpp --
//           void foo();
//           void foo();

//          NOTE: You can easily check it using "-E" flag with your
//          compiler, like: clang++ -E ... or g++ -E ..., this will
//          output preprocessed file to standard output.

//          You can ask so what? Where is the problem? Your would be right,
//          there are no problem, yet, because multiple function
//          foward-declarations are, in fact, allowed.

//       2) Let's take a look at another case:

//           // --- test.h ---
//           struct foo {};

//           // -- test.cpp --
//           #include "test.h"
//           #include "test.h"

//          Everything is the same, except multiple definitions of a
//          struct are not allowed in a single file, so this program
//          doesn't compile anymore.

//          You can say: why would you include one header multiple
//          times, just remove the second inclusion.
//
//          And in this case it's indeed A solution.

//       3) But in the third case there will be no such solution:

//           // ---- a.h ----
//           struct foo {};

//           // ---- b.h ----
//           #include "a.h"
//           // use foo in any way

//           // ---- c.h ----
//           #include "a.h"
//           // use foo in any way

//           // ---- d.h ----
//           #include "a.h"
//           #include "b.h"
//           // use stuff from a.h
//           // and stuff from b.h

//           // - test.cpp -
//           #include "d.h"
//           // use something from d.h

//          In this case there's no way you can avoid double
//          inclusion, because every file use the least amount
//          of header inclusion it needs, there's nothing to
//          remove. Yet a copy of a.h is included in both
//          b.h and c.h, so including both of them will always
//          lead to double inclusion.

//          That's called diamond inclusion:
//                a.h
//               /  \
//              /    \
//            b.h    c.h  :) Because it looks like a diamond!
//             \     /
//              \   /
//               d.h

//          What to do then? Use header guards!

//       4) Header guards in action! In the same layout!
//           // ---- a.h ----
//           #ifndef A_H
//           #define A_H
//
//           struct foo {};
//
//           #endif

//           // ---- b.h ----
//           #ifndef B_H
//           #define B_H
//
//           #include "a.h"
//           // use foo in any way
//
//           #endif

//           // ---- c.h ----
//           #ifndef C_H
//           #define C_H
//
//           #include "a.h"
//           // use foo in any way
//
//           #endif

//           // ---- d.h ----
//           #ifndef D_H
//           #define D_H
//
//           #include "a.h"
//           #include "b.h"
//           // use stuff from a.h
//           // and stuff from b.h
//
//           #endif

//           // - test.cpp -
//           #include "d.h"
//           // use something from d.h

//          This kind of machinery is expected to be in every
//          header you ever write, do you get how it works?)

int solve_linear_equation(double coefs[], double *x1);
int solve_quadratic_equation (double coefs[], double *x1, double *x2);
void solve(double coefs[], double *x1, double *x2, int *number_of_roots);

int comparison_with_zero (double number);
void interactively_read_coefficients (double *coefs, bool *error_status);
void read_coefficient (double *coef, bool *error_status);
void print_solution (int number_of_roots, double x1, double x2);


void testing_one_case(double coefs[], double x1_ref, double x2_ref, double x1, double x2, int nroots_ref, int nroots);
void test_solve(void);

// TODO: split in multiple files, give them good names
