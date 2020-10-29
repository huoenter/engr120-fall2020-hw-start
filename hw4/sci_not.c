#include <stdio.h>
#include <math.h>

#include "sci_not.h"

/*
 * Q1: A number expressed in scientific notation is represented by its mantissa
 * (a fraction - double) and its exponent (an integer). Please read through
 * "repl.it/@engr120/struct-ex" before you start.
 */

/* Q1.1 Define a type sci_not_t (use typedef) that has
 * separate components for these two parts in sci_not.h
 */


/* Q1.2 Define a function scan_sci that takes from the input source a string
 * representing a positive number in scientific notation, and breaks it into
 * components for storage The mantissa of an input value(m) should satisfy this
 * condition: 0.1 <= m < 1.0. in a sci_not_t structure.
 *
 * Sample input:
 * 0.20000e1
 * 0.32000e5
 *
 * Example: reading in two numbers from FILE *f
 *
 * sci_not_t s1 = fscanf_sci(f);
 * sci_not_t s2 = fscanf_sci(f);
 */

sci_not_t fscan_sci_not(FILE *in) {
    /* fscanf in a double */
    /* fscanf in a dummy 'e' */
    /* fscanf in an int */

    /* make a sci_not_t */

}

/*
Also, write functions to compute the sum, difference, product, and
quotient of two sci_not_t values. All these functions should have a result type
of sci_not_t and should ensure that the result’s mantissa is in the prescribed
range. Your output should be of this form:

Example:
Values input: 0.25000e3 0.20000e1
Sum: 0.25200e3
Difference: 0.24800e3
Product: 0.50000e3
Quotient: 0.12500e3

Note that 0.1 <= m < 1.0

*/

sci_not_t add(sci_not_t s1, sci_not_t s2) {
}

sci_not_t diff(sci_not_t s1, sci_not_t s2) {
}

sci_not_t product(sci_not_t s1, sci_not_t s2) {
}

sci_not_t quotient(sci_not_t s1, sci_not_t s2) {
}

int sci_not_equal(sci_not_t s1, sci_not_t s2) {
    return fabs(s1.mantissa - s2.mantissa) < DELTA &&
           s1.exponent == s2.exponent;
}

void print_sci_not(sci_not_t s) {
    printf("%.5lfe%d", s.mantissa, s.exponent);
}
