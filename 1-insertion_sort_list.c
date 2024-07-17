#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: A Double linked list to sort
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = node_swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
/**
 *node_swap - swap a node for his previous one
 *@node: the node
 *@list: the node list
 *Return: return a pointer to a node
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
