#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


// TODO: Do not use define, there are a lot a cases where they can cause weird
//       behaviours they were necessary in C, but since we use C++ compiler we
//       have an alternative, constants:
//
//
//       const int LIMIT = 20; // For example
//       inline const int LIMIT = 20; // You can add "inline", although it's a newer C++
//                                    // it makes sure that constant is substituted
//                                    // pretty much the same way, define is, when possible
//
//
//       About weird cases, think what problems can occur if you were to use define
//       as a variable name later, or make define equal to expression, not just 
//       a single number, and so on... All this cases will cause weirdness, which only
//       gets worse since it's not easy to distinguish macros from variable without
//       searching for a declaration.
// 
//       So, try to avoid them, when possible.

#define LIM 20

// TODO: Now your whole program is just a one .cpp file with everything in it.
//
//       You need to split your program in few different files.
//
//       To do this, learn about header files, they will help you to "join"
//       different modules together.
//
//       How to split your program -- is something you need to come up with 
//       yourself, try thinking about logical modules inside this program,
//       what can you extract and how it will help. Think carefully, don't 
//       overdo it too :) 


void input_coef (double *coefs);
int solve (double a_coef, double b_coef, double c_coef, double *x1, double *x2);
void get_coef (double *coef);
void answer_output (int number_of_roots, double x1, double x2);


// TODO: Don't use global variables, it's very hard to keep track of them,
//       try to find an alternative.
bool error_status = 0;


int main(void) {
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    double coefs[] = {0, 0, 0};
    input_coef(coefs);
    double x1, x2; // TODO: A bit more space between lines, would you?)
    answer_output(solve(coefs[0], coefs[1], coefs[2], &x1, &x2), x1, x2);
    return 0;
}



void get_coef(double *coef) {
    char str [LIM];
    // TODO:^ inconsistent style, usually we don't put spaces before [] brackes, and you 
    //        didn't earlier in main, be consistent.

    int c; // TODO: named it c? You can do better, c'mon!
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (c == '-' && i != 0) {
                error_status = 1;
            }
        if (c == '.' && i == 0) { // TODO: Don't like numbers written like .99?
                error_status = 1;
            }
	//  ^ TODO: misaligned, *angry face*
        if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
            str[i] = c; //                  ^ TODO: What if I write 0.1.2? Is that a number?)
            i += 1;
            continue;
        }
        error_status = 1;
    }
    if (error_status != 1) {
	// TODO: you've done so much work parsing string yourself and now you delegate most
	//       of it to library function, even after you've done almost all parsing?)
        *coef = atof(str);
        return;
    } else { // TODO: else after return usually only clutters everything, remove it) 
        error_status = 1;
        return;
    }
}




// TODO: Why do you sometime pass coefficients as array and sometimes separately?
//       Try to be consistent and make your API consistent :)
int solve (double a_coef, double b_coef, double c_coef, double *x1, double *x2) {
    // TODO: It's very weird that your function refuses to do it's job because 
    //       of some global state in error_status.
    //
    //       I see that you tried to make this some kind of explicit error handling,
    //       but try to it in a way that is obvious from the caller.
    if (error_status == 1)
        return 73;
    double epsilon = 1e-9;
    if (fabs(a_coef) <= epsilon) { // TODO: extract this comparison in a function
	// TODO: isn't linear equation -- other case worth extracting in other function?
        if (fabs(b_coef) >= epsilon) { 
            *x1 = (double) (-c_coef / b_coef);
            return 1;
        } else if ((fabs(b_coef) <= epsilon) && (fabs(c_coef) <= epsilon)) {
            return 999;
        } else {
            return 0;
        }
    } else {
        double diskriminant = b_coef * b_coef - 4 * a_coef * c_coef;
// TODO: watch ^~~~~~~~~~~~ out for spelling of your words!
        if (fabs(diskriminant) <= epsilon) {
            *x1 = (double) (-b_coef / (2 * a_coef));
            return 1;
        } else if (diskriminant < 0) {
            return 0;
        } else {
            *x1 = (double) (-b_coef + sqrt(diskriminant)) / (2 * a_coef);
            *x2 = (double) (-b_coef - sqrt(diskriminant)) / (2 * a_coef);
            return 2;
        }
    }
}





// TODO: Is this a good name? What does it mean "to answer"?
//       ==> to come up with an answer and say it
//
//       But this function didn't come up with anything, it
//       just described what already were given to it, without
//       any kind of processing or "thinking", so it doesn't
//       seem to be an appropriate name.
//
//       Also, when you name things, don't try to be very "clever",
//       look around, see is there any conventions or good names,
//       programmers are already used to.
//
//       And this case there are, functionm that just write some
//       text without any "thinking" to stdout (standard output)
//       are usually called "printing" functions.
void answer_output(int number_of_roots, double x1, double x2) {
    switch (number_of_roots) {
        case 0:
            printf("no valid solutions");
            break;
        case 1:
            printf("x1 = x2 = %.2lf", x1);
            break;
        case 2:
            printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
            break;
        case 999:
            printf("an infinite number of solutions");
            break;
        case 73: // TODO: What is this magic number? How was it chosen?
		 //       If it was chosen randomly, use a constant with good name, to
		 //       explain it, and make a comment saying where it comes from.
            printf("ERROR");
	    // TODO: If it comes to this line
            break;
    }

}




void input_coef (double *coefs) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
// TODO:^~~~ whyy, alignment
        printf(" = ");
        get_coef(coefs + i);
    }
}
