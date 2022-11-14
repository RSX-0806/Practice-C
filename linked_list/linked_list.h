#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdlib.h>
// Basic Linked List
// @next: pointer to the next Node
// @value: current de value 
typedef struct Node {
	struct Node *next;
	uint value; 
} Node;

// Functions prototype
void f_print_node(Node *node);
void f_insert_node_start(Node **p_node, uint m_value);
void f_insert_node_end(Node **p_node, uint m_value);
void f_insert_node_after(Node *p_node, uint m_value);
void f_remove_node_by_value(Node **p_node, uint m_value);
void f_deallocate_node(Node **p_node);
void f_list_reverse(Node **linked_list);
unsigned int f_node_count(Node *p_node);
#endif