#include "sort.h"
#include <sys/types.h>
/**
*swap_elements - swaps two elements in array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap_elements(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - implementation of lomuto partition sorting scheme
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finds;

	for (finds = first; finds < last; finds++)
	{
		if (array[finds] < pivot)
		{
			if (array[current] != array[finds])
			{
				swap_elements(array, current, finds);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swap_elements(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *qsa - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void qsa(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		qsa(array, first, position - 1, size);
		qsa(array, position + 1, last, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qsa(array, 0, size - 1, size);
}
