#ifndef __LIST_H
#define __LIST_H

#include "main.h"

typedef struct _node {
		void *data;
		struct _node *next;
} node;

int push(node **head, void *new_node, size_t new_node_size);
void free_list(node *head);
void* find_data(const node *head,const void *criteria, int (*compare)(const void*,const void*));
void iterate_list(node *head, void (*iterator_func)(const void *));

#endif
