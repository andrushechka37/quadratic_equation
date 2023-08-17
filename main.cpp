#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(void) { 


    double frst_coef, sec_coef, free_member; 
    printf("print a, b, c from ax^2 + bx + c = 0\n");
    printf("a = ");
    scanf("%lf", &frst_coef); 
    printf("b = "); 
    scanf("%lf", &sec_coef); 
    printf("c = ");  
    scanf("%lf", &free_member); 

    double x1;
    double epsilon = 1e-9;
    if ((frst_coef >= (-epsilon)) && (frst_coef <= epsilon)) { 
        if ((sec_coef <= (-epsilon)) || (sec_coef >= epsilon)) { 
            x1 = (double) (-free_member / sec_coef);
            printf("x1 = x2 = %.2lf", x1);
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
    return 0;
}
