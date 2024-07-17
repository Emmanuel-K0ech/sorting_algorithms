#include "sort.h"
/**
* int_swap - Swap two integers in an array.
* @x: The first integer to swap.
* @y: The second integer to swap.
* Return: void
*/
void int_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
* bubble_sort - Sort an array of integers in ascending order.
* @array: An array of integers to sort.
* @size: The size of the array.
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t x, length = size;
	bool decis = false;

	if (array == NULL || size < 2)
		return;

	while (decis == false)
	{
		decis = true;
		for (x = 0; x < length - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				int_swap(array + x, array + x + 1);
				print_array(array, size);
				decis = false;
			}
		}
		length--;
	}
}
