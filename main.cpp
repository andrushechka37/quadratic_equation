#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


int const LIMIT = 20;
int const NO_ROOTS = 13;  // 13 is a bad number)

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

int comprassion (double number);
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

    double x1 = 0, x2 = 0;
    int number_of_roots = solve(coefs[0], coefs[1], coefs[2], &x1, &x2);

    if (error_status == 1) {
        printf("ERROR");
    } else {
        answer_output(number_of_roots, x1, x2);
    }

    return 0;
}



void get_coef(double *coef) {
    char str[LIMIT];
    int simvol;
    int i = 0;

    while ((simvol = getchar()) != '\n') {
        if (simvol == '-' && i != 0) {
            error_status = 1;
        }
        if (simvol == '.' && i == 0) { // TODO: Don't like numbers written like .99?
            error_status = 1;
        }
        if ((simvol >= '0' && simvol <= '9') || simvol == '.' || simvol == '-') {
            str[i] = simvol; //                  ^ TODO: What if I write 0.1.2? Is that a number?)
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
    }
    error_status = 1;
}




            // TODO: Why do you sometime pass coefficients as array and sometimes separately?
             //       Try to be consistent and make your API consistent :)
int solve (double a_coef, double b_coef, double c_coef, double *x1, double *x2) {
    if (compression(a_coef) == 0) { // TODO: extract this comparison in a function
	// TODO: isn't linear equation -- other case worth extracting in other function?
        if (compression(b_coef) != 0) {
            *x1 = (double) (-c_coef / b_coef);
            return 1;
        } else if ((fabs(b_coef) <= epsilon) && (fabs(c_coef) <= epsilon)) {
            return 999;
        } else {
            return 0;
        }
    } else {
        double discriminant = b_coef * b_coef - 4 * a_coef * c_coef;
        if (fabs(discriminant) <= epsilon) {
            *x1 = (double) (-b_coef / (2 * a_coef));
            return 1;
        } else if (discriminant < 0) {
            return 0;
        } else {
            *x1 = (double) (-b_coef + sqrt(discriminant)) / (2 * a_coef);
            *x2 = (double) (-b_coef - sqrt(discriminant)) / (2 * a_coef);
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
    }

}




void input_coef (double *coefs) {
    for (int i = 0; i <= 2; i++) {
	    putchar('a' + i);
        printf(" = ");
        get_coef(coefs + i);
    }
}



int comprassion (double number) {
    double epsilon = 1e-9;
    if (fabs(number) <= 0)
        return 0;
    if (number > 0) {
        return 1;
    } else {
        return -1;
    }
}
