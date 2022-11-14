#include <stdio.h>
#include "double_linked_list.h"

int main(int argc, char const *argv[]) {
    /* code */
    Node *root      =   malloc(sizeof(Node));
    Node *a         =   malloc(sizeof(Node));
    Node *b         =   malloc(sizeof(Node));

    root->previous  =   NULL;
    root->next      =   a;
    root->value     =   10;

    a->previous     =   root;
    a->next         =   b;
    a->value        =   11;

    b->previous     =   a;
    b->next         =   NULL;
    b->value        =   12;

    
    f_print_double_linked_list(root);
    f_deallocate(&root);
    // free(root);
    // free(a);
    // free(b);
    return 0;
}

void f_print_double_linked_list(Node *p_root) {
    if (p_root != NULL) {
        for(Node *p_current_node = p_root; p_current_node != NULL; p_current_node = p_current_node->next) {
		    printf("[ %d ]", p_current_node->value);
			if (p_current_node->next != NULL) { printf(" --> "); }
        }
    }
}

void f_deallocate(Node **p_root) {
    if (*p_root == NULL) { return; }

    Node *current = *p_root;
    while (current->next != NULL) {
        current = current->next;
        free(current->previous);
    }
    
    free(current);
    *p_root = NULL;
}