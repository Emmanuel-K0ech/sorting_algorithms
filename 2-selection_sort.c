#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t x, indx;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;
	for (x = 0; x < size; x++)
	{
		tmp = x;
		flag = 0;
		for (indx = x + 1; indx < size; indx++)
		{
			if (array[tmp] > array[indx])
			{
				tmp = indx;
				flag += 1;
			}
		}
		swap = array[x];
		array[x] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
