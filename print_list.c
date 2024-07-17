#include <stdio.h>
#include "sort.h"

/**
* list_print - Prints a list of integers
*
* @list: The list to be printed
*/
void list_print(const listint_t *list)
{
	int x;

	x = 0;
	while (list)
	{
		if (x > 0)
			printf(", ");
		printf("%d", list->n);
		++x;
		list = list->next;
	}
	printf("\n");
}
