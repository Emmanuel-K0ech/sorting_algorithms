#include "sort.h"
#include <sys/types.h>
/**
*swap_elem - the positions of two elements into an array
*@array: array
*@x: array element
*@y: array element
*/
void swap_elem(int *array, ssize_t x, ssize_t y)
{
	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finds = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			current++;
		} while (array[current] < pivot);
		do {
			finds--;
		} while (array[finds] > pivot);
		if (current >= finds)
			return (current);
		swap_elem(array, current, finds);
		print_array(array, size);
	}
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
		position = hoare_partition(array, first, last, size);
		qsa(array, first, position - 1, size);
		qsa(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qsa(array, 0, size - 1, size);
}
