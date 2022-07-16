#include "sort.h"

/**
<<<<<<< HEAD
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Double pointer to the head of the linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *swap_node, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	swap_node = (*list)->next;
	while (swap_node != NULL)
	{
		next_swap = swap_node->next;
		while (swap_node->prev != NULL && swap_node->prev->n > swap_node->n)
		{
			swap_node->prev->next = swap_node->next;
			if (swap_node->next != NULL)
				swap_node->next->prev = swap_node->prev;
			swap_node->next = swap_node->prev;
			swap_node->prev = swap_node->next->prev;
			swap_node->next->prev = swap_node;
			if (swap_node->prev == NULL)
				*list = swap_node;
			else
				swap_node->prev->next = swap_node;
			print_list(*list);
		}
		swap_node = next_swap;
=======
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
	listint_t *current = *list, *last = *list;
	listint_t *temp = NULL;


	while (current)
	{
		while (current && current->prev && current->n < (current->prev)->n)
		{
			temp = (current->prev)->prev;

			node_swap(current->prev, current);
			/* when swapping at the edge */
			if (!temp)
				*list = current;

			print_list(*list);
		}
		current = last;
		if (last)
			last = last->next;
>>>>>>> 0eb6b61bed943206dd2576fbddea6cc8b0fbafc1
	}
}
