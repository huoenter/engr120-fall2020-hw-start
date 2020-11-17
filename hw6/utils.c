#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

node_t *make_node(char c) {
  node_t *p = (node_t *) malloc(sizeof(node_t));
  p->letter = c;
  p->next = NULL;
  return p;
}

node_t *make_list(char letters[], int n) {
  if (n == 0) return NULL;

  node_t *head = make_node(letters[0]);
  node_t *last = head;
  for (int i=1; i<n; i++) {
    node_t *temp = make_node(letters[i]);
    last->next = temp;
    last = temp;
  }

  return head;
}

int equal_linked(node_t *l1, node_t *l2) {
  while (l1 != NULL && l2 != NULL) {
    if (l1->letter != l2->letter)
      return 0;
    l1 = l1->next;
    l2 = l2->next;
  }
  return l1 == l2;
}

void print_list(node_t *head) {
  if (head == NULL) {
    printf("NULL\n");
    return;
  }
  node_t *temp = head;
  while (temp != NULL) {
    printf("%c", temp->letter);
    if (temp->next != NULL) {
      printf(" -> ");
    }
    else {
      printf(" -> NULL\n");
    }
    temp = temp->next;
  }
}

void delete_list(node_t **head) {
  node_t *temp = *head;

  while (temp != NULL) {
    node_t *nxt = temp->next;
    // commenting out free since it will
    // cause problems when the hw is not finished
    //free(temp);
    temp = nxt;
  }

  *head = NULL;
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

int test_ll(node_t *a, node_t *e, char *am) {
    if (equal_linked(a, e)) {
        printf("PASSED\t%s should be ", am);
        print_list(a);
        return 1;
    } else {
        printf("FAILED\t%s should be ", am);
        print_list(e);
        printf("\tYours is ");
        print_list(a);
        return 0;
    }
}
