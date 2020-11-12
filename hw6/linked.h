#ifndef NODE_T

struct node {
  char letter;
  struct node *next;
};

typedef struct node node_t;
#endif

#define NODE_T

/* Return the size of the list */
int size(node_t *head);

/* Return a string from all the characters in the list
 * Hint: use remove
 */
char *fold(node_t *head);

/* For ALL functions below, return the head of the changed list */

/* Add a node with c as payload before the current head. */
node_t *prepend(node_t *head, node_t *new);

/* Add a node at the end of list with payload c. */
node_t *append(node_t *head, node_t *new);

/* Make and insert a node after the ith node (0-indexed) */
node_t *insert_at(node_t *head, node_t *new, int pos);

/* Remove a node at the ith position (0-indexed) and free the space of the node */
node_t *remove_ith(node_t *head, int i);
