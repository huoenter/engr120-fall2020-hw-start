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
        printf("PASSED\t%s should be ", am);
        print_sci_not(e);
        printf("\n");
        return 1;
    } else {
        printf("FAILED\t%s should be ", am);
        print_sci_not(e);
        printf(" your answer is ");
        print_sci_not(a);
        printf("\n");
        return 0;
    }
}


int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    fclose(in);

    return 0;
}
