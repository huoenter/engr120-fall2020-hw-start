#include <stdio.h>
#include <math.h>

#define DELTA 0.01

int test_int(int e, int a, char *am)
{
    if (e == a) {
        printf("PASSED\t%s should be %d\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be %d, your answer is %d\n", am, e, a);
        return 0;
    }
}

int test_double(double e, double a, char *am)
{
    if (fabs(e - a) < DELTA) {
        printf("PASSED\t%s should be %lf\n", am, e);
        return 1;
    } else {
        printf("FAILED\t%s should be %lf, your answer is %lf\n", am, e, a);
        return 0;
    }
}

int add(int a, int b);

int range_sum(int lower, int upper);

int square_sum(int lower, int upper);

double fare(double miles, double rate);


int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    test_int(add(0, 0), 0, "add(0, 0)");
    test_int(add(3, 4), 7, "add(3, 4)");
    test_int(add(-14, 4), -10, "add(-14, 4)");

    test_int(range_sum(1, 4), 10, "range_sum(1, 4)");
    test_int(range_sum(11, 16), 81, "range_sum(11, 16)");
    test_int(range_sum(4, 1), 0, "range_sum(4, 1)");
    test_int(range_sum(-4, -3), -7, "range_sum(-4, -3)");

    test_int(square_sum(1, 1), 1, "square_sum(1, 1)");
    test_int(square_sum(1, 0), 0, "square_sum(1, 0)");
    test_int(square_sum(5, 8), 174, "square_sum(5, 8)");
    test_int(square_sum(-4, -2), 29, "square_sum(-4, -2)");
    test_int(square_sum(-2, -4), 0, "square_sum(-2, -4)");

    test_double(fare(3.2, 4.5), 19.4, "fare(3.2, 4.5)");
    test_double(fare(1.7, 2.2), 8.74, "fare(1.7, 2.2)");
    test_double(fare(0.5, 3.3), 6.65, "fare(0.5, 3.3)");

    return 0;
}
