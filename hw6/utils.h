#include "linked.h"

node_t *make_node(char c);

node_t *make_list(char letters[], int n);

int test_ll(node_t *a, node_t *e, char *am);

int test_str(char a[], char e[], char *am);

int equal_linked(node_t *l1, node_t *l2);

void print_list(node_t *head);

void delete_list(node_t **head);
