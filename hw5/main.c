#include <stdio.h>
#include "address.h"

#define N 5

int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    address_t ans[5] = {
        {1, 2, 3, 4, "a"},
        {21, 34, 11, 111, "b"},
        {89, 221, 81, 33, "cse"},
        {67, 242, 11, 0, "john"},
        {0, 0, 0, 0, "end"}
    };

    address_t as[NADDR];

    FILE *txt = fopen(TXT_INPUT, "r");

    scan_addresses(as, txt);

    fclose(txt);

    FILE *f = fopen(BIN_FILE, "wb");
    write_addresses(as, f);
    fclose(f);

    FILE *g = fopen(BIN_FILE, "rb");
    address_t fas[NADDR];
    read_addresses(fas, g);
    fclose(g);

    for (int i = 0; i < N; i++)
        if (equal_address(fas[i], ans[i]))
            printf("PASSED Successfuly store/read address %s\n",
                                                ans[i].nickname);
        else
            printf("FAILED Failed to store/read address %s\n",
                                                ans[i].nickname);

    return 0;
}
