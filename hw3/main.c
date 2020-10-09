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
    double delta = 1.0;
    char msg[100];
    for (int i = 0; i < n; i++) {
        if (fabs(e[i] - a[i]) >= DELTA) {
            printf("a[%d] should be %lf, you have %lf.\n", i, e[i], a[i]);
            return 0;
        }
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
    test_int(substring_n("abcdabcababcabc", "abc"), 4, "substring_n(\"abcdabcababcabc\", \"abc\")");
    test_int(substring_n("ababababa", "aba"), 4, "substring_n(\"ababababa\", \"aba\")");

    char v[100] = "<initial value>";

    replace("hello", "el", "abc", v);
    test_str(v, "habclo", "replace(\"hello\", \"el\", \"abc\", v)");

    replace("", "el", "abc", v);
    test_str(v, "", "replace(\"\", \"el\", \"abc\", v)");

    replace("hello", "abc", "def", v);
    test_str(v, "hello", "replace(\"hello\", \"abc\", \"def\", v)");

    replace("utilities", "ti", "def", v);
    test_str(v, "udeflidefes", "replace(\"utilities\", \"ti\", \"def\", v)");

    replace("xxxabxxxabcxxx", "abc", "def", v);
    test_str(v, "xxxabxxxdefxxx", "replace(\"xxxabxxxabcxxx\", \"abc\", \"def\", v)");

    int code1[] = {0, 7, 9, 4, 0, 0, 8, 0, 4, 5, 0, 1};
    test_int(validate(code1), -1, "0 7 9 4 0 0 8 0 4 5 0 1");

    int code2[] = {0, 2, 4, 0, 0, 0, 1, 6, 2, 8, 6, 0};
    test_int(validate(code2), 5, "0 2 4 0 0 0 1 6 2 8 6 0");

    int code3[] = {0, 1, 1, 1, 1, 0, 8, 5, 6, 8, 0, 7};
    test_int(validate(code3), -1, "0 1 1 1 1 0 8 5 6 8 0 7");

    int code4[] = {0, 5, 1, 0, 0, 0, 1, 3, 8, 1, 0, 1};
    test_int(validate(code4), -1, "0 5 1 0 0 0 1 3 8 1 0 1");

    int code5[] = {0, 5, 1, 0, 2, 1, 1, 3, 8, 1, 0, 1};
    test_int(validate(code5), 4, "0 5 1 0 2 1 1 3 8 1 0 1");

    FILE *in = fopen("values.txt", "r");

    double values[6];

    double ans[] = {830.5, 0.75, 0.3, 302, 117.444, 0.05};
    heat_transfer(values, in);
    test_double_arr(values, ans, "? 0.75 0.3 302 117.444 0.05", 6);

    heat_transfer(values, in);
    test_double_arr(values, ans, "830.5 ? 0.3 302 117.444 0.05", 6);

    heat_transfer(values, in);
    test_double_arr(values, ans, "830.5 0.75 ? 302 117.444 0.05", 6);

    heat_transfer(values, in);
    test_double_arr(values, ans, "830.5 0.75 0.3 ? 117.444 0.05", 6);

    heat_transfer(values, in);
    test_double_arr(values, ans, "830.5 0.75 0.3 302 ? 0.05", 6);

    heat_transfer(values, in);
    test_double_arr(values, ans, "830.5 0.75 0.3 302 117.444 ?", 6);

    fclose(in);

    return 0;
}
