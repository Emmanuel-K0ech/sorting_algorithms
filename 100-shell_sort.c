#include "sort.h"

/**
*swap_elements - the positions of two elements into an array
*@array: array
*@x: array element
*@y: array element
*/
void swap_elements(int *array, int x, int y)
{

	int tmp;

	tmp = array[x];
	array[x] = array[y];
	array[y] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, indx = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (indx = i; indx >= gap &&
			 (array[indx] < array[indx - gap]); indx -= gap)
				swap_elements(array, indx, indx - gap);
		print_array(array, size);
		gap /= 3;
	}
}
