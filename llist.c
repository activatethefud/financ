#include "llist.h"

void* find_data(const node *head,const void *criteria, int (*compare)(const void*,const void*))
{
		while(head != NULL) {
				if((*compare)(head->data,criteria)) {
						return head->data;
				}
				head=head->next;
		}

		return NULL;
}

int push(node **head, void *new_node, size_t new_node_size)
{
		node *new_data = malloc(sizeof *new_data);
		new_data->data = malloc(new_node_size);
		new_data->next = NULL;

		memmove(new_data->data,new_node,new_node_size);

		// Append the new node to list end
		if((*head) == NULL) {
				(*head)=new_data;
		}
		else {
				node *iter_node=(*head);
				while(iter_node->next != NULL) {
						iter_node=iter_node->next;
				}

				iter_node->next=new_data;
		}

		return 0;
}

void free_list(node *head) 
{
		if(head != NULL) {
				free_list(head->next);
				free(head->data);
				free(head);
		}
}

void iterate_list(node *head, void (*iterator_func)(const void *))
{
		while(head != NULL) {
				(*iterator_func)(head->data);
				head=head->next;
		}
}
