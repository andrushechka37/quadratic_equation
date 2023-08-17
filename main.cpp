#include <stdio.h>
#include <math.h>
#include <stdlib.h> // TODO: Why             | Don't include  |
#include <locale.h> // TODO: do you need     | what you don't |
#include <string.h> // TODO: all of this?)   | use, alright?  |
#include <ctype.h> // TODO: spaces are just as important as words, as one famous designer said, whose name
int main(void) {   //       I don't remeber. Use them, and your code will be a lot more readable, it's also free 0-0
    // TODO: Are you still living in 1989? Because it sure seems like it, with this C89 style of writing. C allows
    //       you to define variables as close to usage as possible, use this ability.
    //
    //       As it greatly reduces changes for uninitialized variables. Consider:
    //       1.
    //            double a;
    //            // ... many lines of code
    //            if (expr)
    //                a = 0; // initialized
    //  
    //            It's very easy to loose track of variable lifetime, and forget to initialize variable.
    //            So never do that. Always initialize your variables and always bring them closer to their usage.
    //
    //       2. As in this example:
    //            double a = 0; // Much safer and clear!
    //
    //       See? Fix!
    double a, b, c, x, d; // TODO: Why such love for short variable names? I can kinda get a, b, c naming, it's
	   		  //       from math and people there don't work with lot's of names and consequently don't
	   		  //       name that well, but in programming naming is key, don't be lazy, you can do better!
    double epsilon = 0.00000000001; // TODO: There are much more readable double literals for this, e.g. 1e-10
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    printf("a = ");
    scanf("%lf", &a); // TODO: Maybe you can do something to this repetitive pattern? TODO: Also, doesn't scanf return
    printf("b = ");   //       ...                                                          something, has a use?)
    scanf("%lf", &b); //       of  entering coefficients
    printf("c = ");   //       ...
    scanf("%lf", &c); //       and entering coefficients, and make safer and more readable?

    // TODO: Your program now can only do one thing: show user the answer. But let's say someone from a big IT company
    //       Tries to find equation solver for his next big project and stumbles upon your github?
    // 
    //       He will be disappointed, because your solver is monolithic and very hard to integrate in his project. It
    //       is meant to solve equations interactively with a lively human entering numbers and reading outputs. But
    //       his project need an API, a programming interface that will be easy to interact with from other programs.


    // That is one reason, among many, to extract your code in functions and not just write everything in a one big
    // blob: it makes things a lot more reusable, and also makes parts much easier to write, debug and integrate.

    // TODO: So, that is the next important thing you need to do: split this one blob of a code in parts and extract
    //       them in functions, how to split it -- is yours decision to make. A good rule of thumb would be to make
    //       every function do one logical thing, consider how you would explain this program in human language, 
    //       it might give you an idea.

    if (a == 0) { // TODO: I see you're already familiar with the concept of relative precision and eps comparison
        if (b != 0) { //   for floating number. But this comparisons aren't using your newly acquired knowledge, why?
            x = (double) (-c / b);
            printf("x1 = x2 = %.2lf", x);
        } else if (b == 0 && c == 0) {
          printf("an infinite number of solutions");
        } else {
            printf("no valid solutions");
        }
    } else {
        d = b * b - 4 * a * c;
        if ((d >= (-1 * epsilon)) && (d <= epsilon)) { // TODO: I wounder is there a name for such operation with sign)
            x = (double) (-b / (2 * a));
            printf("x1 = x2 = %.2lf", x);
        } else if (d < 0) {
            printf("no valid solutions");
        } else {
            x = (double) (-b + sqrt(d)) / (2 * a);
            printf("x1 = %.2lf\n", x);
	    // TODO: You spent all your variable declarations and can't declare more? C'mon, x1 & x2 deserve better!
            x = (double) (-b - sqrt(d)) / (2 * a);
            printf("x2 = %.2lf\n", x);
        }
    }
    return 0; // TODO: Does your program never fail? What a marvel! Even if I want to solve abc*x^2 + jjj*x + heheh?
}
