#include "sort.h"

/**
 * node_swap - swap the two nodes
 * @h: pointer to header
 * @num_one: first num to swap
 * @num2: second to swap
 */

void node_swap(listint_t **h, listint_t **num_one, listint_t *num2)
{
	(*num_one)->next = num2->next;
	if (num2->next != NULL)
		num2->next->prev = *num_one;
	num2->prev = (*num_one)->prev;
	num2->next = *num_one;
	if ((*num_one)->prev != NULL)
		(*num_one)->prev->next = num2;
	else
		*h = num2;
	(*num_one)->prev = num2;
	*num_one = num2->prev;
}


/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			node_swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
