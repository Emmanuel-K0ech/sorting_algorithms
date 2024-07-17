#include <stdlib.h>
#include <stdio.h>

/**
* array_print - Prints an array of integers
*
* @array: The array to be printed
* @size: Number of elements in @array
*/
void array_print(const int *array, size_t size)
{
	size_t x;

	x = 0;
	while (array && x < size)
	{
		if (x > 0)
			printf(", ");
		printf("%d", array[x]);
		++x;
	}
	printf("\n");
}
