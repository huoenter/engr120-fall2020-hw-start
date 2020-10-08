#include <stdio.h>
#include <math.h>
#include <string.h>

#define DELTA 0.01

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
    char msg[100];
    for (int i = 0; i < n; i++) {
        sprintf(msg, "a[%d] does not match. ", i);
        if (!test_double(a[i], e[i], msg))
            return 0;
    }

    printf("PASSED %s\n", am);
    return 1;
}

int substring_n(char *s, char *t);
void replace(char *s, char *t, char *u, char *v);
int validate(int code[]);
void heat_transfer(double values[], FILE *input);

int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    test_int(substring_n("hello", "el"), 1, "substring_n(\"hello\", \"el\")");
    test_int(substring_n("", "ab"), 0, "substring_n(\"\", \"ab\")");
    test_int(substring_n("utilities", "ti"), 2, "substring_n(\"utilities\", \"ti\")");

    char v[100] = "<initial value>";

    replace("hello", "el", "abc", v);
    test_str(v, "habclo", "replace(\"hello\", \"el\", \"abc\", v)");

    replace("", "el", "abc", v);
    test_str(v, "", "replace(\"\", \"el\", \"abc\", v)");

    replace("hello", "abc", "def", v);
    test_str(v, "hello", "replace(\"hello\", \"abc\", \"def\", v)");

    replace("utilities", "ti", "def", v);
    test_str(v, "udeflidefes", "replace(\"utilities\", \"ti\", \"def\", v)");


    int code1[] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};
    test_int(validate(code1), -1, "0 7 9 4 0 0 8 0 4 5 0 1");

    int code2[] = {0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0};
    test_int(validate(code2), 5, "0 2 4 0 0 0 1 6 2 8 6 0");

    FILE *in = fopen("values.txt", "r");

    double values[6];

    double ans1[] = {755.0, 0.8, 0.12, 298, 274, 0.003};
    heat_transfer(values, in);
    test_double_arr(values, ans1, "755.0 0.8 0.12 298 ? 0.003", 6);

    fclose(in);

    return 0;
}
