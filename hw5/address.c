#include <stdio.h>
#include <string.h>
#include "address.h"

/* A dummy place holder */
address_t dummy = { 0x1a, 0x2e, 0x30, 0x8a, "dummy" };


address_t scan_address(FILE *f) {
    return dummy;
}

void scan_addresses(address_t arr[], FILE *txt) {
}

int sentinel(address_t a) {
    return 1;
}

void read_addresses(address_t a[], FILE *f) {
}

void write_addresses(address_t a[], FILE *f) {
}

void print_address(address_t a) {
    printf("%d.%d.%d.%d %s\n", a.xx, a.yy, a.zz, a.mm, a.nickname);
}

int equal_address(address_t a1, address_t a2) {
    return a1.xx == a2.xx &&
           a1.yy == a2.yy &&
           a1.zz == a2.zz &&
           a1.mm == a2.mm &&
           strcmp(a1.nickname, a2.nickname) == 0;
}
