#include <stdio.h>

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

int add(int a, int b);

int main(void) {
    test_int(add(3, 4), 0, "add(3,4)");
    test_int(add(0, 0), 0, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 0, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 0, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 0, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    test_int(add(3, 4), 7, "add(3,4)");
    return 0;
}
