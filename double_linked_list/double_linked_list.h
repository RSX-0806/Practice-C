#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_
#include <stdlib.h>

typedef struct Node {
    struct Node *previous;
    struct Node *next;
    uint value;
} Node;

void f_print_double_linked_list(Node *p_root);
void f_deallocate(Node **p_root);
#endif