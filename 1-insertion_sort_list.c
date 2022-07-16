#include "sort.h"

/**
 * node_swap - swaps two adjecent nodes
 * @left: the left node
 * @right: the right node
 */
void node_swap(listint_t *left, listint_t *right)
{
	left->next = right->next;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;

	if (left->next)
		left->next->prev = left;

	if (right->prev)
		right->prev->next = right;		
}
/**
 * insertion_sort_list - sorts doubly linked list
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, **last = list;
	listint_t *temp;


	while (last != NULL)
	{
		if (current==NULL)
			break;

		while (current && current->prev && current->n < current->prev->n)
		{
			/* when swapping at the edge */
			if (current->prev->prev == NULL)
			{
				
				temp = current->prev;
				temp->next = current->next;
				current->prev = NULL;
				
				temp->prev = current;
				current->next = temp;
				if (temp->next)
					temp->next->prev = temp;
				*list = current;
				(*list)->next = temp;
				(*list)->prev = NULL;
				
				
				

				print_list(*list);
				continue;
			}
			node_swap(current->prev, current);

			print_list(*list);
		}
		current = *last;
		last = &(*last)->next;
	}
}
