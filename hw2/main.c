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

int precedence(char rator1, char rator2);

void mystrcat(char s[], char t[]);

int lower(char s[]);

int mystrcmp(char s[], char t[]);

int squeeze(char s[], char t[], char c);

void reverse_n(char s[], int n);

int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    test_int(precedence('!', '|'), 1, "precedence('!', '|')");
    test_int(precedence('=', ','), 1, "precedence('=', ',')");
    test_int(precedence('+', '-'), 0, "precedence('+', '-')");
    test_int(precedence(',', '.'), -1, "precedence(',', '.')");

    int ret;
    char s[100];
    mystrcat(strcpy(s, "abc"), "def");
    test_str(s, "abcdef", "mystrcat(\"abc\", \"def\")");

    strcpy(s, "HellO");
    ret = lower(s);
    test_str(s, "hello", "lower(\"HellO\")");
    test_int(ret, 2, "lower(\"HellO\")");

    strcpy(s, "abc");
    ret = lower(s);
    test_str(s, "abc", "lower(\"abc\")");
    test_int(ret, 0, "lower(\"abc\")");

    strcpy(s, "$ch0oL");
    ret = lower(s);
    test_str(s, "$ch0ol", "lower(\"$ch0ol\")");
    test_int(ret, 1, "lower(\"$ch0ol\")");

    test_int(mystrcmp("abc", "def"), -1, "mystrcmp(\"abc\", \"def\")");
    test_int(mystrcmp("abcxxx", "abd"), -1, "mystrcmp(\"abcxxx\", \"abd\")");
    test_int(mystrcmp("abcd", "abCd"), 1, "mystrcmp(\"abcd\", \"abCd\")");
    test_int(mystrcmp("abcd", "abcd"), 0, "mystrcmp(\"abcd\", \"abcd\")");

    return 0;
}
