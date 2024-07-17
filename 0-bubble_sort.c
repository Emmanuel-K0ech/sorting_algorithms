#include "sort.h"
/**
* bubble_sort - sort array Elements - minimum to maximum
* @array: array
* @size: array size
* Return: void
*/
void bubble_sort(int *array, size_t size)
{

	size_t x, index, tmp = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
}
