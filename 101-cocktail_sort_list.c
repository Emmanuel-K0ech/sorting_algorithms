#include "sort.h"
#include <stdio.h>
/**
 *node_swap - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *node_swap(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
/**
 *cocktail_sort_list - the cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int no_of_swaps = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (no_of_swaps == 1)
	{
		no_of_swaps = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = node_swap(node->next, list);
				no_of_swaps = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (no_of_swaps == 0)
			break;
		no_of_swaps = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = node_swap(node, list);
				no_of_swaps = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
