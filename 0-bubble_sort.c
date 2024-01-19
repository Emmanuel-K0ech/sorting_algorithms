#include <stddef.h>
#include <stdio.h>
/**
 * bubble_sort - implemenation of bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	int temp = 0;

	int count = 0;

	j = 0;
	while (j != size - 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				for (k = 0; k < size; k++)
				{
					if (k == size - 1)
						printf("%d", array[k]);
					else
						printf("%d, ", array[k]);
				}
				printf("\n");
			}
			else
			{
				count++;
			}
		}
	}
}
