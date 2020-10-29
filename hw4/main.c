#include <stdio.h>
#include <math.h>
#include <string.h>

#include "sci_not.h"

int test_int(int a, int e, char *am)
{
    if (e == a) {
        printf("PASSED\t%s should be %d\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be %d, your answer is %d\n", am, e, a);
        return 0;
    }
}

int test_str(char a[], char e[], char *am) {
    if (strcmp(a, e) == 0) {
        printf("PASSED\t%s should be %s\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be %s, your answer is %s\n", am, e, a);
        return 0;
    }
}

int test_double(double a, double e, char *am)
{
    if (fabs(e - a) < DELTA) {
        printf("PASSED\t%s should be %lf\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be %lf, your answer is %lf\n", am, e, a);
        return 0;
    }
}

int test_double_arr(double a[], double e[], char *am, int n)
{
    double delta = 1.0;
    char msg[100];
    for (int i = 0; i < n; i++) {
        if (fabs(e[i] - a[i]) >= DELTA) {
            printf("FAILED a[%d] should be %lf, you have %lf.\n", i, e[i], a[i]);
            return 0;
        }
    }

    printf("PASSED %s\n", am);
    return 1;
}

int test_sci_not(sci_not_t a, sci_not_t e, char *am) {
    if (sci_not_equal(a, e)) {
        printf("PASSED\t%s should be %lf\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be ", am);
        print_sci_not(e);
        printf("your answer is ");
        print_sci_not(a);
        printf("\n");
        return 0;
    }
}


int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    FILE *in = fopen("sci_not_input.txt", "r");

    sci_not_t s1 = fscan_sci_not(in);
    sci_not_t s2 = fscan_sci_not(in);

    sci_not_t sum = {0.252000, 3};
    test_sci_not(add(s1, s2), sum, "0.25000e3 + 0.20000e1");

    sci_not_t diff = {0.248000, 3};
    test_sci_not(difference(s1, s2), diff, "0.25000e3 - 0.20000e1");

    sci_not_t prod = {0.50000, 3};
    test_sci_not(product(s1, s2), prod, "0.25000e3 * 0.20000e1");

    sci_not_t quot = {0.125000, 3};
    test_sci_not(quotient(s1, s2), quot, "0.25000e3 / 0.20000e1");

    fclose(in);

    return 0;
}
