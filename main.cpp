#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h> // TODO: Are you kidding?! Add newlines, please, as I asked, read carefully!
void solve (double frst_coef, double sec_coef, double free_member);
// TODO:           ^~~~ naming, do not invent your own horrible abbrivations, just write "first", not "frst",
//                      what are you trying to save, a few (1!) keystrokes?
//
//                      Also, conventional names are good, I would probably name it a_coefficient instead, "a"
//                      is conventional name taken from underlying subject, so it's fine.
//
//                      Or, if writing coefficient_a, coefficient_b, ... seems weird to you, you can always
//                      create a "coefficients" struct with a, b, c fields.
// TODO: Fix names globally, not just here.

void get_coef(double *coef); // TODO: Please, more newlines, it makes a difference, and is free!
int main(void) {
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    double frst_coef, sec_coef, free_member;
    // TODO: Array of pointers? Isn't this too complex? Wouldn't double coefficients[...] suffice?
    double *array[] = {&frst_coef, &sec_coef, &free_member};
    for (int i = 0; i <= 2; i++) { // TODO: Can this whole loop be also extracted in a function?
	putchar(97 + i); // TODO: What is 97? Never write so called "magic constants", write 'a' instead! 
        printf(" = ");
        get_coef(array[i]);
    }
    solve(frst_coef, sec_coef, free_member);
    return 0;
}

void get_coef(double *coef) {
    char str [20];
    char c;
    int i = 0;
    while (((c = getchar()) >= 48 && c <= 57) || c == 46 || c == 45) { // TODO: get rid of magic numbers
	// TODO: Also, it's not a very good practice to put everything in your loop condition, it makes
	//       code unclear and complex for now reason, can you instead read character in loop?
	//
	//       You can use break if you need to break out of loop early. 

        if (c == 45 && i != 0) {
            printf("input error");
            exit(-1); 
	    // TODO: It's not a good practice to exit on errors, because it makes code difficult to reason
	    //       about, and unsafe.
	    //       
	    //       ==> Consider:
	    //       int number = read_int();
	    //       if (number == 0)
	    //           do_something(number);
	    //
	    //       Can this code even fail? It's not clear. Maybe it can, maybe can't. What happens if user
	    //       write wrong number? What does read_int return, does it return at all? Can user even write
	    //       something invalid. It's not clear!
	    //      
	    //       So you should always prefer explicit error handling over implicit (almost everything
	    //       explicit is better, honestly).
	    //
	    //       ==> Let's take a look at other piece of code:
	    //
	    //       int error = 0; // TODO: We will store error codes in this variable.
	    //
	    //       int number = read_int(&error);
	    //       if (error != 0) // So it's clear, there is an error.
	    //           return EXIT_FAILURE;
	    //
	    //       if (number == 0) {
	    //           do_something(number, &error);
	    //           if (error != 0)
            //               return EXIT_FAILURE;
	    //       }
	    //
	    //       Now we can answer all the question I presented before just by looking at the code. Cool!
	    //       Improve your code accordingly! 

        }
        str[i] = c;
        i += 1;
    }
    if (c == '\n') {
        *coef = atof(str);
        return;
    } else {
        printf("input error");
            exit(-1);
    }
}

// TODO: You can't use function programmatically, if it prints solution with printf, return it instead.
void solve (double frst_coef, double sec_coef, double free_member) {
        double x1;
//  ^~~~ TODO: what is happening with your alignment? Fix it :()
    double epsilon = 1e-9;
    if ((frst_coef >= (-epsilon)) && (frst_coef <= epsilon)) {    // TODO: I guess you haven't guessed it, when you can't
        if ((sec_coef <= (-epsilon)) || (sec_coef >= epsilon)) {  //       answer to my comment, don't just delete it, ask me.
            x1 = (double) (-free_member / sec_coef);              //       In this case I talked about abs() function:
            printf("x1 = x2 = %.2lf", x1);                 //           fabs(sec_coef) <= epsilon
        } else if (((sec_coef >= (-epsilon)) && (sec_coef <= epsilon)) && ((free_member >= (-epsilon)) && (free_member <= epsilon))) {
          printf("an infinite number of solutions");
        } else {
            printf("no valid solutions");
        }
    } else {
        double diskr = sec_coef * sec_coef - 4 * frst_coef * free_member;
        if ((diskr >= (-epsilon)) && (diskr <= epsilon)) {
            x1 = (double) (-sec_coef / (2 * frst_coef));
            printf("x1 = x2 = %.2lf", x1);
        } else if (diskr < 0) {
            printf("no valid solutions");
        } else {
            x1 = (double) (-sec_coef + sqrt(diskr)) / (2 * frst_coef);
            double x2 = (double) (-sec_coef - sqrt(diskr)) / (2 * frst_coef);
            printf("x1 = %.2lf\nx2 = %.2lf", x1, x2);
        }
    }
}


// TODO: Also, do not ever commit binary files, they pollute repository, get outdated and make git slow.
//       I'm talking about your main and main.dSYM whatever it is. 

// TODO: And, I encourage you to write commit names in English. Your commit names are already getting
//       better, but you switched to russian. How your chinese/american/german/japanese/finish colleges will understand them?
