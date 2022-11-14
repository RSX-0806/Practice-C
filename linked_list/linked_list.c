#include <stdio.h>
#include "linked_list.h"

int main() {
	// Node pointer declaration & initialization
	Node *root = NULL; 
	// Insert 2 nodes in our root node
	// With value of 11, 12 respectively
	f_insert_node_end(&root, 11);
	f_insert_node_end(&root, 12);
	// f_insert_node_after(root->next, 99);
	// 1, 4, 19
	// f_remove_node_by_value(&root, 13);
	f_list_reverse(&root);
	f_deallocate_node(&root);
	return 0;
}

void f_print_node(Node *node) {
	if( node != NULL) {
		for (Node *current_node = node; current_node != NULL; current_node = current_node->next ) {
			printf("[ %d ]", current_node->value);
			if (current_node->next != NULL) 	{ printf(" --> "); }
		}
	}
}

void f_insert_node_start(Node **p_node, uint m_value) {
	Node *p_new_node = malloc(sizeof(Node));
	if (p_new_node == NULL) { exit(EXIT_FAILURE); }
	p_new_node->value = m_value;
	p_new_node->next = *p_node;
	*p_node = p_new_node;
}

void f_insert_node_end(Node **p_node, uint m_value) {
	Node *p_new_node = malloc(sizeof(Node));

	if(p_new_node == NULL)  exit(EXIT_FAILURE);
	
	p_new_node->value = m_value;
	p_new_node->next = NULL;
	
	if(*p_node == NULL) {
		*p_node = p_new_node;
		return;
	}

	Node *p_current = *p_node;
	
	while(p_current->next != NULL) {
		p_current = p_current->next;
	}

	p_current->next = p_new_node;
}

void f_insert_node_after(Node *p_node, uint m_value) {
	Node *new_node = malloc(sizeof(Node));
	if ( new_node == NULL ) { exit(EXIT_FAILURE); }
	new_node->next 	= p_node->next;
	p_node->next 	= new_node;
	new_node->value = m_value;
}

void f_remove_node_by_value(Node **p_node, uint m_value) {
	if (*p_node == NULL) { exit(EXIT_FAILURE); }
	if ((*p_node)->value == m_value) {
		Node *removable_node = *p_node;
		*p_node = (*p_node)->next;
		free(removable_node);
		return;
	}
	for (Node *current_node = *p_node; current_node->next != NULL; current_node = current_node->next) {
		if (current_node->next->value == m_value) {
			Node *remove_node = current_node->next;
			if(current_node->next->next != NULL) {
				current_node->next = current_node->next->next;
				free(remove_node);
			}
			else {
				current_node->next = NULL;
				free(remove_node);
			}
			break;
		}
	}		
}

void f_deallocate_node(Node **p_node) {
	if (*p_node == NULL) { return; }
	
	Node *p_current_node = *p_node;
	while (p_current_node != NULL) {
		Node *p_previous_node = p_current_node;
		p_current_node = p_current_node->next;
		free(p_previous_node);
	}
	*p_node = NULL;
}

void f_list_reverse(Node **linked_list) {
	Node *previous = NULL;
	Node *current = *linked_list;
	while(current != NULL) {
		Node *next = current->next;
		
		current->next = previous;

		previous = current;
		current  = next;
		free(next);
	}
	*linked_list = previous;
	free(previous);
}

unsigned int f_node_count(Node *p_node) {
	uint counter = 0;
	if (p_node == NULL) {
		return counter;
	}
	Node *current = p_node;
	while (current != NULL) {
		counter++;
		current = current->next;
	}
	return counter;

}