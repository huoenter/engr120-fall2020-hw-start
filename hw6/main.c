#include <stdio.h>
#include "utils.h"
#include "linked.h"

int main(void) {
    printf("\n\n===Begin TESTING===\n\n");

    char s[] = "HELLO";
    node_t *ll2 = make_list(s, 5);
    test_str(fold(ll2), s, "fold(ll2)");

    ll2 = insert_at(ll2, make_node('A'), 1); // HAELLO
    test_ll(ll2, make_list("HAELLO", 6), "insert(ll2, \'A\', 1)");
    ll2 = insert_at(ll2, make_node('K'), 0); // KHAELLO
    test_ll(ll2, make_list("KHAELLO", 7), "insert_at(ll2, \'K\', 0)");
    ll2 = append(ll2, make_node('O')); // KHAELLOO
    test_ll(ll2, make_list("KHAELLOO", 8), "append(ll2, \'O\')");
    ll2 = prepend(ll2, make_node('X')); // XKHAELLOO
    test_ll(ll2, make_list("XKHAELLOO", 9), "prepend(ll2, \'X\')");

    printf("===removing===\n");

    ll2 = remove_ith(ll2, 0); //KHAELLOO
    test_ll(ll2, make_list("KHAELLOO", 8), "remove_ith(ll2, 0)");
    ll2 = remove_ith(ll2, 0); //HAELLOO
    test_ll(ll2, make_list("HAELLOO", 7), "remove_ith(ll2, 0)");
    ll2 = remove_ith(ll2, 2); //HALLOO
    test_ll(ll2, make_list("HALLOO", 6), "remove_ith(ll2, 2)");
    ll2 = remove_ith(ll2, 4); //HALLO
    test_ll(ll2, make_list("HALLO", 5), "remove_ith(ll2, 4)");

    delete_list(&ll2);

    return 0;
}
