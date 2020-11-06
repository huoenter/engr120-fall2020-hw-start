#define DELTA 0.0001

/* typedef sci_not_t here */

sci_not_t fscan_sci_not(FILE *in);

sci_not_t add(sci_not_t s1, sci_not_t s2);

sci_not_t diff(sci_not_t s1, sci_not_t s2);

sci_not_t product(sci_not_t s1, sci_not_t s2);

sci_not_t quotient(sci_not_t s1, sci_not_t s2);

int sci_not_equal(sci_not_t s1, sci_not_t s2);

void print_sci_not(sci_not_t s);
